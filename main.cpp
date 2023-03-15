#include "visite_window.h"
#include "connexion.h"
#include <QtDebug>
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    bool test;
    QApplication a(argc, argv);
    connexion c;
     test=c.createconnect();
    visite_window w;
    if (test)
    {
    w.show();
    QMessageBox::information(nullptr,QObject::tr("database is open"),
    QObject::tr("connection successful.\n"
                "click cancel to exit.") ,QMessageBox::Cancel);  }


 else
 QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                       QObject::tr("connection failed.\n"
                                   "click cancel to exit.") ,QMessageBox::Cancel);
    return a.exec();
}
