#include "visite_window.h"
#include "ui_visite_window.h"

visite_window::visite_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::visite_window)
{
    ui->setupUi(this);
    ui->lineEdit_montant->setText("30");
    ui->lineEdit_montant_modif->setText("30");
    ui->tableView_2->setModel(V.afficher());
    ui->lineEdit_nbvisites->setValidator(new QRegExpValidator(QRegExp("[0-9]+")));
     ui->lineEdit_nbvisites_modif->setValidator(new QRegExpValidator(QRegExp("[0-9]+")));
    ui->lineEdit_id->setValidator(new QRegExpValidator(QRegExp("[0-9]+")));
    ui->lineEdit_id_modif->setValidator(new QRegExpValidator(QRegExp("[0-9]+")));
    ui->lineEdit_montant->setValidator(new QIntValidator(0, 9999, this));
    ui->lineEdit_montant_modif->setValidator(new QIntValidator(0, 9999, this));
    ui->comboBox->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
     ui->comboBox_2->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
     ui->lineEdit_hs->setValidator(new QIntValidator(0, 99, this));
     ui->lineEdit_he->setValidator(new QIntValidator(0, 99, this));
     ui->lineEdit_hs_modif->setValidator(new QIntValidator(0, 99, this));
     ui->lineEdit_he_modif->setValidator(new QIntValidator(0, 99, this));


}

visite_window::~visite_window()
{
    delete ui;
}

//ui->QLineEdit_montant->settext("30")

void visite_window::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void visite_window::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void visite_window::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void visite_window::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}



void visite_window::on_pushButton_9_clicked()
{
    this->close();
}

void visite_window::on_pushButton_17_clicked()
{

    QDate selectedDate = ui->dateEdit_date->date();
    QString date = selectedDate.toString("yyyy-MM-dd");
    QString resultat=ui->comboBox->currentText();
    float montant=ui->lineEdit_montant->text().toFloat();
    int nb_visite=ui->lineEdit_nbvisites->text().toInt();
    int heure_entree=ui->lineEdit_he->text().toInt();
    int heure_sortie=ui->lineEdit_hs->text().toInt();
    int id=ui->lineEdit_id->text().toInt();
    QString matricule_vehicule=ui->lineEdit_matriculevehicule->text();
    visite V(date,resultat,montant,nb_visite,heure_entree,heure_sortie,id,matricule_vehicule);



   bool test=V.ajouter();



        if(test)
        {
            ui->tableView_2->setModel(V.afficher());
            QMessageBox:: information(nullptr, QObject::tr("OK"),
                                                QObject::tr("Ajout effectuee\n"
                                                            "click cancel to exit."),QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("Ajout non effectuee.\n"
                                              "click Cancel to exit."),QMessageBox::Cancel);
}

void visite_window::on_pushButton_16_clicked()
{
    QString matricule=ui->lineEdit_supprimer->text();



        bool test=V.supprimer(matricule);

        if(test)
        {
            ui->tableView_2->setModel(V.afficher());
            QMessageBox:: information(nullptr, QObject::tr("OK"),
                                                               QObject::tr("Suppression effectué\n"
                                                                           "click cancel to exit."),QMessageBox::Cancel);


        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("Suppression non effectué.\n"
                                              "click Cancel to exit."),QMessageBox::Cancel);
}

void visite_window::on_pushButton_8_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}

void visite_window::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void visite_window::on_pushButton_3_clicked()
{

        QDate selectedDate = ui->dateEdit_date_modif->date();
        QString date = selectedDate.toString("yyyy-MM-dd");
        QString resultat=ui->comboBox_2->currentText();
        float montant=ui->lineEdit_montant_modif->text().toFloat();
        int nb_visite=ui->lineEdit_nbvisites_modif->text().toInt();
        int heure_entree=ui->lineEdit_he_modif->text().toInt();
        int heure_sortie=ui->lineEdit_hs_modif->text().toInt();
        QString matricule=ui->lineEdit_matricule_modif->text();
        int id=ui->lineEdit_id_modif->text().toInt();
        //int id=ui->lineEdit_id_modif->text().toInt();
        QString matricule_vehicule=ui->lineEdit_matricule_modif->text();

        visite V(date,resultat,montant,nb_visite,heure_entree,heure_sortie,id,matricule_vehicule);




         bool test=V.modifier(matricule);


         if(test)
         {

             ui->tableView_2->setModel(V.afficher());

             QMessageBox:: information(nullptr, QObject::tr("OK"),
                                                 QObject::tr("modification effectuee\n"
                                                             "click cancel to exit."),QMessageBox::Cancel);
         }
         else
             QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                   QObject::tr("modification non effectuee.\n"
                                               "click Cancel to exit."),QMessageBox::Cancel);
}


void visite_window::on_pushButton_5_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
}
