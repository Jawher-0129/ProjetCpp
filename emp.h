#ifndef EMP_H
#define EMP_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
class Emp
{
public:
    void setid(int ident);
    void setnom(QString n);
    void setprenom(QString pr);
    void setemail(QString mail);
    void setmdp(QString motpasse);
    void setgrade(QString grad);
    void setsalaire(float sal);
    void setnbhs(int nbhs);

    int getid();
    QString getnom();
    QString getprenom();
    QString getemail();
    QString getgrade();
    float getsalaire();
    int getnbhs();
     bool ajouter();
     bool supprimer (int cin);
    Emp();
    Emp(int id,QString nom,QString prenom,QString email,QString mdp,QString grade,float salaire,int nb_heure_supp);
    QSqlQueryModel * afficher();
    bool modifier(int id );
private:
    QString nom,prenom,email,mdp,grade;
    int id,nb_heure_supp;
    float salaire;
};

#endif // EMP_H
