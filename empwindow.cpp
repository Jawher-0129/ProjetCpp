#include "empwindow.h"
#include "ui_empwindow.h"
#include "emp.h"

empWindow::empWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::empWindow)
{
    ui->setupUi(this);
    ui->lineEdit_id->setValidator(new QRegExpValidator(QRegExp("[0-9]+")));
    ui->lineEdit_id->setMaxLength(8);
    ui->lineEdit_n->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
    ui->lineEdit_p->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
    ui->lineEdit_em->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}")));
     ui->lineEdit_mdp->setValidator(new QRegExpValidator(QRegExp("(?=.*[a-zA-Z])(?=.*[0-9])(?=.*[^a-zA-Z0-9]).{8,}")));
      ui->lineEdit_g->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
      ui->lineEdit_s->setValidator(new QRegExpValidator(QRegExp("[0-9.]+")));

    ui->tableView->setModel(e.afficher());


}

empWindow::~empWindow()
{
    delete ui;
}




void empWindow::on_ajouter_clicked()
{
   int id=ui->lineEdit_id->text().toInt();
        QString nom=ui->lineEdit_n->text();
        QString prenom=ui->lineEdit_p->text();
        QString email=ui->lineEdit_em->text();
        QString mdp=ui->lineEdit_mdp->text();
       QString grade=ui->lineEdit_g->text();
        float salaire=ui->lineEdit_s->text().toFloat();
       int nb_heure_supp=ui->lineEdit_sup->text().toInt();

      Emp e(id,nom,prenom,email,mdp,grade,salaire,nb_heure_supp);
        bool test=e.ajouter();

        if(test)
        {
             ui->tableView->setModel(e.afficher());

                   QMessageBox:: information(nullptr, QObject::tr("OK"),
                                                       QObject::tr("Ajout effectué\n"
                                                                   "click cancel to exit."),QMessageBox::Cancel);
                    }
                else
                    QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                          QObject::tr("Ajout non effectué.\n"
                                                      "click Cancel to exit."),QMessageBox::Cancel);



}



void empWindow::on_supprimer1_clicked()
{
    int id=ui->le_supprimer->text().toInt();

       bool test=e.supprimer(id);

       if(test)
       {
           QMessageBox:: information(nullptr, QObject::tr("OK"),
                                               QObject::tr("Suppression effectué\n"
                                                           "click cancel to exit."),QMessageBox::Cancel);
            }
        else
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("Suppression non effectué.\n"
                                          "click Cancel to exit."),QMessageBox::Cancel);



       ui->stackedWidget->setCurrentIndex(0);
}



void empWindow::on_modifier_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void empWindow::on_modifier2_clicked()
{

    int id=ui->lineEdit_idm->text().toInt();
         QString nom=ui->lineEdit_nm->text();
         QString prenom=ui->lineEdit_pm->text();
        QString email =ui->lineEdit_emm->text();
          QString mdp=ui->lineEdit_mdpm->text();
          QString grade=ui->lineEdit_gm->text();
          float salaire=ui->lineEdit_sm->text().toFloat();
         int nb_heure_supp=ui->lineEdit_suppm->text().toInt();

     Emp e (id,nom,prenom,email,mdp,grade,salaire,nb_heure_supp);
     bool test=e.modifier(id);

     if(test)
     {
         QMessageBox:: information(nullptr, QObject::tr("OK"),
                                             QObject::tr("modification effectuee\n"
                                                         "click cancel to exit."),QMessageBox::Cancel);
     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                               QObject::tr("modification non effectuee.\n"
                                           "click Cancel to exit."),QMessageBox::Cancel);
}

void empWindow::on_pushButton_2_clicked()
{
   ui->stackedWidget->setCurrentIndex(1);
}

void empWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void empWindow::on_pushButton_16_clicked()
{
   ui->stackedWidget->setCurrentIndex(3);
}

void empWindow::on_pushButton1_clicked()
{
   ui->stackedWidget->setCurrentIndex(4);
}


void empWindow::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}
