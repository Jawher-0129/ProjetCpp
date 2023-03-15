#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <qmessagebox.h>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <algorithm>
#include <QVariant>
#include <QtSql>
#include <QPdfWriter>
#include <QTextDocument>
#include <QPainter>
#include <QTableWidget>
#include <QHeaderView>


#include <QLineEdit>
#include <QValidator>
#include <QRegExp>
#include <QRegExpValidator>



 
class client
{
public:
    client();

    client(QString cin,QString nom,QString prenom,QString adress,QString date,QString email,QString tel,QString sexe);

    QString getnom();
    QString getprenom();
    QString getadress();
    QString getcin();
    QString getemail();
    QString getsexe();
    QString gettel();
    QString getdate();

    void setnom(QString nom);
    void setprenom(QString prenom);
    void setadress(QString adress);
    void setcin(QString cin);
    void setemail(QString email);
    void setsexe(QString sexe);
    void settel(QString tel);
    void setdate(QString date);

    bool chercher_client(QString cin);
    bool ajouter_clilent();
    bool supprimer_client(QString cin);
    bool modifier_client(QString cin);

    bool isValidEmail(QString email);
    

    QSqlQueryModel * afficher_client();
    QSqlQueryModel * afficher_client_tri_dec();
    QSqlQueryModel * afficher_client_tri_cor();

    void client_to_pdf();
     
private:
       QString cin,nom,prenom,adress,date,email,tel,sexe;
};

#endif // CLIENT_H
