#include <mainwindow.h>
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication to_do_list(argc, argv);
    MainWindow window;
    window.show();
    return to_do_list.exec();       // loopib rakenduse akent
}
