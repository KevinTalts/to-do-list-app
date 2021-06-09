#include <mainwindow.h>
#include <ui_mainwindow.h>

void MainWindow::ReadFromFile(const QString& FileName){         // loeb failis olevad taskid
    QString path = QCoreApplication::applicationDirPath();
    path.append("/").append(FileName);
    QFile file(path);
    if(!file.open(QIODevice::ReadWrite)) {
        QMessageBox::information(nullptr, "error", file.errorString());
    }
    if(FileName == "ToDoData.txt"){
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            ui->toDo->addItem(line);
            }
    }
    if(FileName == "CompletedData.txt"){
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            ui->completed->addItem(line);
            }
    }
    file.close();
}

void MainWindow::WriteToFile(const QString& FileName){      // kirjutab taskid faili
    QString path = QCoreApplication::applicationDirPath();
    path.append("/").append(FileName);
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(nullptr, "error", file.errorString());
    }
    if(FileName == "ToDoData.txt"){
        QTextStream stream(&file);
        for (int i = 0; i < ui->toDo->count(); i++) {
            QListWidgetItem *item = ui->toDo->item(i);
            stream << item->text() << '\n';
        }
    }
    if(FileName == "CompletedData.txt"){
        QTextStream stream(&file);
        for (int i = 0; i < ui->completed->count(); i++) {
            QListWidgetItem *item = ui->completed->item(i);
            stream << item->text() << '\n';
        }
    }
    file.close();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ReadFromFile("ToDoData.txt");
    ReadFromFile("CompletedData.txt");
}

MainWindow::~MainWindow(){
    WriteToFile("ToDoData.txt");
    WriteToFile("CompletedData.txt");
    delete ui;
}

void MainWindow::on_helpButton_clicked(){        // loob help nupu vajutamisel akna, kus on opetus rakenduse kasutamise kohta
    QMessageBox::about(this, "Help", "*add task: to add a task click on the add task button and type in the task you wish to add to the to do list \n\n"
                                     "*complete task: to complete a task drag and drop it to the completed list or double click on the task \n\n"
                                     "*clear list: to clear the completed task list click the clear list button \n\n");
}

void MainWindow::on_addTask_clicked(){       // lisab taski to do listi
    bool ok;
    QString task = QInputDialog::getText(this, QString("Task"), QString("Add a new task:"),
                                         QLineEdit::Normal, QString(""), &ok,
                                         (this->windowFlags() & ~Qt::WindowContextHelpButtonHint));
    if(ok && !task.isEmpty()){
        ui->toDo->addItem (task);
     }
    if(ok && task.isEmpty()){
        QMessageBox::critical(this,"Error!" ,"You can't add an empty task");
     }
}

void MainWindow::on_clearList_clicked(){     // kustutab completed listi ara
    ui->completed->clear();
}

void MainWindow::on_toDo_itemDoubleClicked(){       // liigutab taski double clickides to do listist completed listi
    QListWidgetItem *widget = ui->toDo->takeItem( ui->toDo->currentRow());
      ui->completed->addItem(widget);
}

void MainWindow::on_completed_itemDoubleClicked(){       // liigutab taski double clickides completed listist to do listi
    QListWidgetItem *widget = ui->completed->takeItem( ui->completed->currentRow());
      ui->toDo->addItem(widget);
}
