#include "emp.h"
Emp::Emp()
{
    id=0;
    nom="";
    prenom="";
    email="";
    mdp="";
    grade="";
    nb_heure_supp=0;
    salaire=0;
}

Emp::Emp(int id,QString nom,QString prenom,QString email,QString mdp,QString grade,float salaire,int nb_heure_supp)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->email=email;
    this->mdp=mdp;
    this->grade=grade;
    this->salaire=salaire;
    this->nb_heure_supp=nb_heure_supp;
}

void Emp::setid(int ident)
{
    id=ident;
}

void Emp::setnom(QString n)
{
    nom=n;
}

void Emp::setprenom(QString pr)
{
    prenom=pr;
}

void Emp::setemail(QString mail)
{
    email=mail;
}

void Emp::setmdp(QString motpasse)
{
    mdp=motpasse;
}

void Emp::setgrade(QString grad)
{
    grade=grad;
}

void Emp::setsalaire(float sal)
{
    salaire=sal;
}


 void Emp::setnbhs(int nbhs)
 {
     nb_heure_supp=nbhs;
 }

int Emp::getid()
{
    return id;


}
 QString Emp::getnom()
 {
     return nom;
 }
 QString Emp::getprenom()
 {
     return prenom;
 }
 QString Emp::getemail()
 {
     return email;
 }
 QString Emp::getgrade()
 {
     return grade;
 }
 float Emp::getsalaire()
 {
     return salaire;
 }

 int Emp::getnbhs()
 {
     return nb_heure_supp;
 }

 bool  Emp:: ajouter()
   {




        QSqlQuery query;







       QString id_string=QString::number(id);
        QString nb_heure_supp_string=QString::number(nb_heure_supp);
        QString salaire_string=QString::number(salaire);

        query.prepare("INSERT INTO EMPLOYES (ID,NOM,PRENOM,EMAIL,MDP,GRADE,SALAIRE,NBHS) "
                      "VALUES (:ID,:NOM,:PRENOM,:EMAIL,:MDP,:GRADE,:SALAIRE,:NBHS)");
        query.bindValue(0, id_string);
        query.bindValue(1, nom);
        query.bindValue(2, prenom);
        query.bindValue(3, email);
        query.bindValue(4, mdp);
        query.bindValue(5, grade);
        query.bindValue(6, salaire_string);
        query.bindValue(7,nb_heure_supp_string);
         return query.exec();
    }



 QSqlQueryModel * Emp:: afficher()
    {
           QSqlQueryModel *model= new   QSqlQueryModel ();

               model->setQuery("SELECT*  FROM EMPLOYES");
             model->setHeaderData(0, Qt::Horizontal,  QObject::tr("ID"));
               model->setHeaderData(1, Qt::Horizontal,  QObject ::tr("NOM"));
               model->setHeaderData(2, Qt::Horizontal,  QObject ::tr("PRENOM"));
               model->setHeaderData(3, Qt::Horizontal,  QObject ::tr("EMAIL"));
               model->setHeaderData(4, Qt::Horizontal,  QObject ::tr("MDP"));
               model->setHeaderData(5, Qt::Horizontal,  QObject ::tr("GRADE"));
               model->setHeaderData(6, Qt::Horizontal,  QObject ::tr("NBHS"));
               model->setHeaderData(7, Qt::Horizontal,  QObject ::tr("SALAIRE"));


            return  model;

    }
 bool  Emp::supprimer (int id)
  {
      QSqlQuery query;

      query.prepare("delete  from EMPLOYES where id=:id ");

      query.bindValue(0, id);


  return query.exec();

  }
 bool Emp::modifier(int id)
 {
     QSqlQuery query;

     QString idString=QString::number(id);
     QString salaireString=QString::number(salaire);
     QString nb_heure_suppString=QString::number(nb_heure_supp);

    if(nom!="")
    {

        query.prepare("UPDATE EMPLOYES SET NOM=:nom WHERE ID=:id");
       query.bindValue(":id",idString);
       query.bindValue(":nom",nom);
       query.exec();
    }

    if(prenom!="")
    {
        query.prepare("UPDATE EMPLOYES SET PRENOM=:prenom WHERE ID=:id");
        query.bindValue(":id",idString);
       query.bindValue(":prenom",prenom);
       query.exec();
    }
    if(email!="")
    {
        query.prepare("UPDATE EMPLOYES SET EMAIL=:email WHERE ID=:id");
        query.bindValue(":id",idString);
       query.bindValue(":email",email);
       query.exec();
    }

    if(mdp!="")

    {
        query.prepare("UPDATE EMPLOYES SET MDP=:mdp WHERE ID=:id");
        query.bindValue(":id",idString);
       query.bindValue(":mdp",mdp);
       query.exec();
    }

    if(grade!="")
    {
        query.prepare("UPDATE EMPLOYES SET GRADE=:grade WHERE ID=:id");
        query.bindValue(":id",idString);
       query.bindValue(":grade",grade);
       query.exec();
    }

    if(salaireString!="")
    {
        query.prepare("UPDATE EMPLOYES SET SALAIRE=:salaire WHERE ID=:id");
        query.bindValue(":id",idString);
       query.bindValue(":salaire",salaireString);
       query.exec();
    }

    if(nb_heure_suppString!="")
    {
        query.prepare("UPDATE EMPLOYES SET NBHS=:nbhs WHERE ID=:id");
        query.bindValue(":id",idString);
       query.bindValue(":nbhs",nb_heure_suppString);
       query.exec();
    }
     return query.exec();
 }






