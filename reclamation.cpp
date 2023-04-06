#include "reclamation.h"

reclamation::reclamation()
{



}

reclamation::reclamation(QString nom_client,QString prenom_client,QString email_client,QString type,QString cin_client,int etat,QString message)
{
    this->etat=etat;
    this->nom_client=nom_client;
    this->prenom_client=prenom_client;
    this->email_client=email_client;
    this->type=type;
    this->cin_client=cin_client;
    this->message=message;
}


void reclamation::setnom_client(QString n)
{
    nom_client=n;
}

void reclamation::setprenom_client(QString pr)
{
    prenom_client=pr;
}

void reclamation::setemail_client(QString em)
{
    email_client=em;
}

void reclamation::settype(QString typee)
{
    type=typee;
}

 void reclamation::setcin_client(QString c)
 {
     cin_client=c;
 }


 QString reclamation::getcin_client()
 {
     return cin_client;
 }

 QString reclamation::getnom_client()
 {
     return nom_client;
 }

  QString reclamation::getprenom_client()
  {
      return prenom_client;
  }

  QString reclamation::getemail_client()
  {
      return email_client;

  }

  QString reclamation::gettype()
  {
      return type;
  }


  bool reclamation::ajouter()
  {
     QSqlQuery query;
     query.prepare("INSERT INTO RECLAMATIONS(NOM_CLIENT,PRENOM_CLIENT,EMAIL_CLIENT,TYPE_RECLAMATION,CIN_CLIENT,DATE_RECLAMATION,MESSAGE)""VALUES(:nom,:prenom,:email,:type,:cin,CURRENT_TIMESTAMP,:message)");
     query.bindValue(":nom",nom_client);
     query.bindValue(":prenom",prenom_client);
     query.bindValue(":email",email_client);
     query.bindValue(":type",type);
     query.bindValue(":cin",cin_client);
     query.bindValue(":message",message);

      return query.exec();
  }


 QSqlQueryModel * reclamation::afficher()
{
      QSqlQueryModel *model=new QSqlQueryModel();

      model->setQuery("SELECT * FROM RECLAMATIONS");
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("NUMERO"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOM_CLIENT"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM_CLIENT"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("EMAIL_CLIENT"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("TYPE_RECLAMATION"));
      model->setHeaderData(5,Qt::Horizontal,QObject::tr("DATE_RECLAMATION"));
      model->setHeaderData(6,Qt::Horizontal,QObject::tr("ETAT"));
      model->setHeaderData(7,Qt::Horizontal,QObject::tr("CIN_CLIENT"));
      model->setHeaderData(8,Qt::Horizontal,QObject::tr("MESSAGE"));
      return model;
}

 bool reclamation::chercher_reclamation(int num)
 {
     QSqlQuery query;
     QString num_str=QString::number(num);

     query.prepare("SELECT * FROM RECLAMATIONS WHERE NUMERO=:num");
     query.bindValue(":num",num_str);

     if(query.exec() && query.next())
         return true;
     else
         return false;
 }

 bool reclamation::supprimer(int num)
 {
     QSqlQuery query;

     QString num_str=QString::number(num);

     query.prepare("DELETE FROM RECLAMATIONS WHERE NUMERO=:num");
     query.bindValue(":num",num_str);
     return query.exec();
 }

 bool reclamation::modifier(int num)
 {
     QSqlQuery query;

     QString num_str=QString::number(num);

     QString etat_str=QString::number(etat);

     if(nom_client!="")
     {
         query.prepare("UPDATE RECLAMATIONS SET NOM_CLIENT=:nom_client WHERE NUMERO=:num");
         query.bindValue(":num",num_str);
         query.bindValue(":nom_client",nom_client);
         query.exec();
     }
     if(prenom_client!="")
     {
         query.prepare("UPDATE RECLAMATIONS SET PRENOM_CLIENT=:prenom_client WHERE NUMERO=:num");
         query.bindValue(":num",num_str);
         query.bindValue(":prenom_client",prenom_client);
         query.exec();
     }

     if(email_client!="")
     {
         query.prepare("UPDATE RECLAMATIONS SET EMAIL_CLIENT=:email_client WHERE NUMERO=:num");
         query.bindValue(":num",num_str);
         query.bindValue(":email_client",email_client);
         query.exec();

     }

     if(type!="")
     {
         query.prepare("UPDATE RECLAMATIONS SET TYPE_RECLAMATION=:type WHERE NUMERO=:num");
         query.bindValue(":num",num_str);
         query.bindValue(":type",type);
         query.exec();
     }

     if(etat_str!="")
     {
         query.prepare("UPDATE RECLAMATIONS SET ETAT=:etat WHERE NUMERO=:num");
         query.bindValue(":num",num_str);
         query.bindValue(":etat",etat_str);
         query.exec();
     }
     return query.exec();

 }

 QSqlQueryModel * reclamation::rechercher_reclamation_numero(QString num)
 {

     QSqlQueryModel *model=new QSqlQueryModel();
     model->setQuery("SELECT * FROM RECLAMATIONS WHERE NUMERO LIKE '"+num+"%' OR CIN_CLIENT LIKE '"+num+"%'");
     return model;
 }

 QSqlQueryModel * reclamation::triC()
 {
    QSqlQueryModel *model=new QSqlQueryModel();
   QSqlQuery *q = new QSqlQuery();

    q->prepare("SELECT * FROM RECLAMATIONS ORDER BY DATE_RECLAMATION ASC");
    q->exec();
    model->setQuery(*q);
    return model;
 }

 QSqlQueryModel * reclamation::triDec()
 {
    QSqlQueryModel *model=new QSqlQueryModel();
   QSqlQuery *q = new QSqlQuery();

    q->prepare("SELECT * FROM RECLAMATIONS ORDER BY DATE_RECLAMATION DESC");
    q->exec();
    model->setQuery(*q);
    return model;
 }

 bool reclamation::verif_email(QString email)
 {

     if (!email.contains("@")) {
         return false;
     }

     int index = email.indexOf("@");
     if (email.indexOf(".", index) == -1) {
         return false;
     }
     if (email.startsWith(".") || email.startsWith("@") || email.endsWith(".") || email.endsWith("@")) {
         return false;
     }

     QRegExp regExp("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
     return regExp.exactMatch(email);
 }

