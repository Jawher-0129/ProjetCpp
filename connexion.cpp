#include "connexion.h"

connexion::connexion(){}

bool connexion::createconnect()
{
bool test1=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("AutoTech");
db.setUserName("mouna");//inserer nom de l'utilisateur
db.setPassword("mounamouna");//inserer mot de passe de cet utilisateur

if (db.open())
test1=true;
return  test1;
}
void connexion::closeconnect()
{db.close();}
