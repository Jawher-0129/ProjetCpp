#ifndef VISITE_H
#define VISITE_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <qmessagebox.h>
#include <QtDebug>
#include <QDate>

class visite
{
public:
       void setnumero(int num);
       void setdate_visite(QString datev );
       void setresultat(QString res);
       void setmontant(float mont);
       void setnb_visite(int nbvisite);
       void setheure_entree(int he);
       void setheure_sortie(int hs);
       void setid_employe(int idemp);
       void setmatricule_vehicule(QString matv );

       int  getnumero();
       QString getdate_visite();
       QString getresultat();
       float getmontant();
       int getnb_visite();
       int getheureentree();
       int getheuresortie();
       int getid_employe();
       QString getmatricule_vehicule();


       visite();
       visite(QString date,QString resultat,float montant,int nb_visite,int heure_entree,int heure_sortie,int id,QString matricule_vehicule);
       //bool chercher_visite(int numero);
       bool supprimer(QString matricule);
       bool ajouter();
       bool modifier(QString matv);
       QSqlQueryModel *afficher();
   private:
       QString date,resultat,matricule_vehicule;
       int nb_visite,heure_entree,heure_sortie,id;
       float montant;
   };

#endif // VISITE_H
