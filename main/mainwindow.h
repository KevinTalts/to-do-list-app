#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>          // help nupu jaoks
#include <QListWidget>          // to do ja completed
#include <QInputDialog>         // kasutaja sisendi jaoks
#include <QString>              // kasutaja sisendi jaoks
#include <QFile>                // failist lugemine/kirjutamine
#include <QTextStream>          // votab failist sisselugedes ekstra newlinei ara

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_helpButton_clicked();

    void on_addTask_clicked();

    void on_clearList_clicked();

    void ReadFromFile(const QString& FailName);

    void WriteToFile(const QString& FailName);

    void on_toDo_itemDoubleClicked();

    void on_completed_itemDoubleClicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
