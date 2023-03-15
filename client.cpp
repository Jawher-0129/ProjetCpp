#include "client.h"

client::client()
{
    nom="";
    prenom="";
    adress="";
    cin="";
    email="";
    sexe="";
    tel="";
    date="";
}

client::client(QString cin,QString nom,QString prenom,QString adress,QString date,QString email,QString tel,QString sexe)
{
    this->nom=nom;
    this->prenom=prenom;
    this->adress=adress;
    this->cin=cin;

    this->email=email;
    this->sexe=sexe;
    this->tel=tel;
    this->date=date;
}

QString client::getnom()
{
    return nom;
}
QString client::getprenom()
{
    return prenom;
}
QString client::getadress()
{
    return adress;
}
QString client::getcin()
{
    return cin;
}
QString client::getemail()
{
    return email;
}
QString client::getsexe()
{
    return sexe;
}
QString client::gettel()
{
    return tel;
}
QString client::getdate()
{
    return date;
}

void client::setnom(QString n)
{
    nom=n;
}
void client::setprenom(QString p)
{
    prenom=p;
}
void client::setadress(QString a)
{
    adress=a;
}
void client::setcin(QString c)
{
    cin=c;
}
void client::setemail(QString e)
{
    email=e;
}
void client::setsexe(QString s)
{
    sexe=s;
}
void client::settel(QString t)
{
    tel=t;
}
void client::setdate(QString d)
{
    date=d;
}

bool client::isValidEmail(QString email) {
    QRegularExpression regex("[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}");

       // We use QRegularExpressionMatch to test if the email matches the regex pattern
       QRegularExpressionMatch match = regex.match(email);

       // If the match is valid, return true. Otherwise, return false.
       return match.hasMatch();
}

 

bool client::chercher_client(QString cin)
{
    QSqlQuery query;

    query.prepare("SELECT * FROM CLIENTS WHERE CIN=:cin");
    query.bindValue(":cin",cin);

    if(query.exec() && query.next())
        return true;
    else
        return false;

}

bool client::ajouter_clilent()
{
    QSqlQuery query;

    query.prepare("INSERT INTO CLIENTS (CIN,NOM,PRENOM,ADRESSE,DATE_NAISSANCE,EMAIL,TEL,SEXE)""VALUES(:cin,:nom,:prenom,:adress,:date,:email,:tel,:sexe)");
    query.bindValue(":cin",cin);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":email",email);
    query.bindValue(":sexe",sexe);
    query.bindValue(":adress",adress);
    query.bindValue(":tel",tel);
    query.bindValue(":date",date);

    return query.exec();

}

bool client::supprimer_client(QString cin)
{
    QSqlQuery query;

    query.prepare("DELETE FROM CLIENTS WHERE CIN=:cin");
    query.bindValue(":cin",cin);

    return query.exec();
}

bool client::modifier_client(QString cin)
{
    QSqlQuery query;

   // query.prepare("UPDATE CLIENTS SET CIN=:cin,NOM=:nom,PRENOM=:prenom,ADRESSE=:adress,DATE_NAISSANCE=:date,EMAIL=:email,TEL=:tel WHERE CIN=:cin");

    if(nom!="")
            {
                 query.prepare("UPDATE CLIENTS SET NOM=:nom WHERE CIN=:cin");
                 query.bindValue(":cin",cin);
                 query.bindValue(":nom",nom);

                 query.exec();

            }
    if(prenom!="")
            {
                 query.prepare("UPDATE CLIENTS SET PRENOM=:prenom WHERE CIN=:cin");
                  query.bindValue(":cin",cin);
                   query.bindValue(":prenom",prenom);

                    query.exec();
            }
    if(adress!="")
            {
                 query.prepare("UPDATE CLIENTS SET ADRESSE=:adress WHERE CIN=:cin");
                  query.bindValue(":cin",cin);
                  query.bindValue(":adress",adress);

                   query.exec();
            }
    if(date!="")
            {
                 query.prepare("UPDATE CLIENTS SET DATE_NAISSANCE=:date WHERE CIN=:cin");
                  query.bindValue(":cin",cin);
                  query.bindValue(":date",date);
                  query.exec();
            }
    if(email!="")
            {
                 query.prepare("UPDATE CLIENTS SET EMAIL=:email WHERE CIN=:cin");
                  query.bindValue(":cin",cin);
                 query.bindValue(":email",email);
                 query.exec();

            }
    if(tel!="")
            {
                 query.prepare("UPDATE CLIENTS SET TEL=:tel WHERE CIN=:cin");
                  query.bindValue(":cin",cin);
                  query.bindValue(":tel",tel);
                  query.exec();
            }
    if(sexe!="")
            {
                 query.prepare("UPDATE CLIENTS SET SEXE=:sexe WHERE CIN=:cin");
                 query.bindValue(":cin",cin);
                 query.bindValue(":sexe",sexe);
                 query.exec();
            }

return query.exec();

}
 

QSqlQueryModel * client::afficher_client()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM CLIENTS");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("DATE_NAISSANCE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("EMAIL"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("TEL"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("SEXE"));

    return model;
}

QSqlQueryModel* client::afficher_client_tri_cor()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QString query = "SELECT * FROM CLIENTS ORDER BY DATE_NAISSANCE ASC";
    model->setQuery(query);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_NAISSANCE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("TEL"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("SEXE"));

    return model;
}

QSqlQueryModel* client::afficher_client_tri_dec()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QString query = "SELECT * FROM CLIENTS ORDER BY DATE_NAISSANCE DESC";
    model->setQuery(query);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE_NAISSANCE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("TEL"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("SEXE"));

    return model;
}


