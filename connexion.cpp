#include "connexion.h"

connexion::connexion(){}

bool connexion::createconnect()
{
bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("AutoTech");
db.setUserName("ranim");//inserer nom de l'utilisateur
db.setPassword("ranim");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
return  test;
}

void connexion::closeconnect()
{db.close();}
