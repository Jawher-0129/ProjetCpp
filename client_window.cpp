#include "client_window.h"
#include "ui_client_window.h"

client_window::client_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::client_window)
{
      ui->setupUi(this);
   // ui->client_table->setModel(c.afficher_client());
    ui->client_tel->setValidator(new QIntValidator(0, 99999999, this));

    QRegularExpression alphaRegex("^[a-zA-Z]*$");

    ui->client_prenom->setValidator(new QRegularExpressionValidator(alphaRegex, this));
    ui->client_nom->setValidator(new QRegularExpressionValidator(alphaRegex, this));

}

client_window::~client_window()
{
    delete ui;
}
//----------------------------recherche
void client_window::on_client_recherche_clicked()
{

     QString cin=ui->client_rech->text();

       client c;


    if(cin!="")
    {
               bool test=c.chercher_client(cin);

                  if(test)
                      {

                            QMessageBox:: information(nullptr, QObject::tr("Recherche"),
                            QObject::tr("Client Found\n"
                            "click cancel to exit."),QMessageBox::Cancel);
                       }
                      else
                      {
                              QMessageBox::critical(nullptr, QObject::tr("Recherche"),
                              QObject::tr("Client not found.\n"
                              "click Cancel to exit."),QMessageBox::Cancel);
                      }

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Recherche"),
        QObject::tr("Recherche is empty.\n"
        "click Cancel to exit."),QMessageBox::Cancel);


    }
    ui->client_rech->clear();

}
//----------------------------delete
void client_window::on_client_supprimer_clicked()
{

    QString cin=ui->client_rech->text();

    if(cin!="")
    {

          if(c.chercher_client(cin))
                    {
                            bool test=c.supprimer_client(cin);

                                   if(test)
                                       {
                                               ui->client_cin->clear();
                                               ui->client_nom->clear();

                                               ui->client_prenom->clear();
                                               ui->client_adress->clear();

                                               ui->client_email->clear();
                                               ui->client_tel->clear();
                                             QMessageBox:: information(nullptr, QObject::tr("Delete"),
                                             QObject::tr("Deleted done\n"
                                             "click cancel to exit."),QMessageBox::Cancel);

                                        }
                                       else
                                       {
                                               QMessageBox::critical(nullptr, QObject::tr("Delete"),
                                               QObject::tr("Delete not working.\n"
                                               "click Cancel to exit."),QMessageBox::Cancel);
                                       }

                     }
          else
          {
              QMessageBox::critical(nullptr, QObject::tr("Delete"),
              QObject::tr("Client not found to be deleted.\n"
              "click Cancel to exit."),QMessageBox::Cancel);
          }

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Delete"),
        QObject::tr("recherche is empty.\n"
        "click Cancel to exit."),QMessageBox::Cancel);
    }


}
//----------------------------modif
void client_window::on_client_modifier_clicked()
{

    

     QString cin=ui->client_cin->text();
     QString nom=ui->client_nom->text();
     QString prenom=ui->client_prenom->text();
     QString adress=ui->client_adress->text();
     QString email=ui->client_email->text();
     QString tel=ui->client_tel->text();

     QDate selectedDate = ui->client_date->date();
     QString date = selectedDate.toString("yyyy-MM-dd");

     QString sexe = ui->client_sexe->currentText();

    if(cin!="")
    {

            if(c.chercher_client(cin))
            {
                    if(c.isValidEmail(email))
                    {


                                    client c(cin,nom,prenom,adress,date,email,tel,sexe);
                                    bool test=c.modifier_client(cin);

                                if(test)
                                    {
                                            ui->client_cin->clear();
                                            ui->client_nom->clear();

                                            ui->client_prenom->clear();
                                            ui->client_adress->clear();

                                            ui->client_email->clear();
                                            ui->client_tel->clear();

                                            QMessageBox:: information(nullptr, QObject::tr("MODIF"),
                                            QObject::tr("MODIF done\n"
                                            "click cancel to exit."),QMessageBox::Cancel);
                                    }
                                else
                                    {
                                                QMessageBox::critical(nullptr, QObject::tr("MODIF"),
                                                QObject::tr("modif non effectué.\n"
                                                "click Cancel to exit."),QMessageBox::Cancel);
                                    }
                       }
                    else
                    {
                        QMessageBox::critical(nullptr, QObject::tr("ADD"),
                        QObject::tr("Email is wrong in.\n"
                        "click Cancel to exit."),QMessageBox::Cancel);
                    }

            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("MODIF"),
                QObject::tr("client not found.\n"
               "click Cancel to exit."),QMessageBox::Cancel);

            }

    }
    else 
    {
        QMessageBox::critical(nullptr, QObject::tr("MODIF"),
        QObject::tr("CIN is empty.\n"
        "click Cancel to exit."),QMessageBox::Cancel);
    }

}
//----------------------------go   
void client_window::on_recherche_affiche_6_clicked()
{
    //go to stats
ui->stackedWidget->setCurrentIndex(1);

}

void client_window::on_pushButton_5_clicked()
{
    //go to main client
    ui->stackedWidget->setCurrentIndex(0);
}
//----------------------------affiche_table

//----------------------------tri
void client_window::on_pushButton_3_clicked()
{
      QString tri = ui->client_tri->currentText();

    if(tri=="normal")
          ui->client_table->setModel(c.afficher_client());
    else if(tri=="tri_decroissant")
        {
             ui->client_table->setModel(c.afficher_client_tri_dec());
              
        }
    else 
        {
                  ui->client_table->setModel(c.afficher_client_tri_cor());
        }

}
//----------------------------add
void client_window::on_ajouter_client_clicked()
{
    QString cin=ui->client_cin->text();
    QString nom=ui->client_nom->text();
    QString prenom=ui->client_prenom->text();
    QString adress=ui->client_adress->text();
    QDate selectedDate = ui->client_date->date();
    QString date = selectedDate.toString("yyyy-MM-dd");
    QString email=ui->client_email->text();
    QString tel=ui->client_tel->text();
    QString sexe = ui->client_sexe->currentText();


    if(cin!="" && nom!="" && prenom!="" && adress!="" && email!="" && tel!=""  )
    {
            if(c.isValidEmail(email))
            {
                        if(!c.chercher_client(cin))
                            {
                                client c(cin,nom,prenom,adress,date,email,tel,sexe);


                                    bool test=c.ajouter_clilent();

                                        if(test)
                                        {
                                                        QMessageBox:: information(nullptr, QObject::tr("ADD"),
                                                        QObject::tr("Ajout effectué\n"
                                                        "click cancel to exit."),QMessageBox::Cancel);
                                                        ui->client_cin->clear();
                                                        ui->client_nom->clear();

                                                        ui->client_prenom->clear();
                                                        ui->client_adress->clear();

                                                        ui->client_email->clear();
                                                        ui->client_tel->clear();
                                        }
                                        else
                                        {
                                                            QMessageBox::critical(nullptr, QObject::tr("ADD"),
                                                            QObject::tr("Ajout non effectué.\n"
                                                            "click Cancel to exit."),QMessageBox::Cancel);
                                        }


                            }
                        else
                            {
                                QMessageBox::critical(nullptr, QObject::tr("ADD"),
                                QObject::tr("Client already in.\n"
                                "click Cancel to exit."),QMessageBox::Cancel);
                            }
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("ADD"),
                QObject::tr("Email is wrong in.\n"
                "click Cancel to exit."),QMessageBox::Cancel);
            }
    }
    else 
    {
         QMessageBox::critical(nullptr, QObject::tr("ADD"),
         QObject::tr("something is empty.\n"
         "click Cancel to exit."),QMessageBox::Cancel);

    }



   

}


