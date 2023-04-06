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
     ui->lineEdit_matricule_modif->setMaxLength(9);
     ui->lineEdit_matriculevehicule->setMaxLength(9);



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

    //QDate selectedDate = ui->dateEdit_date->date();
    //QString date = selectedDate.toString("yyyy-MM-dd");
    QDate today = QDate::currentDate();
    QDate selectedDate = ui->dateEdit_date->date();

    if (selectedDate < today) {
        QMessageBox::critical(nullptr, QObject::tr("INSERT"),
            QObject::tr("Invalid date. Date must be from today or the future.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
        return;
    }
    //QDate selectedDate = ui->dateEdit_date->date();
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

// tbadel suppression wel modifier b numero eli howa cle primaire

void visite_window::on_pushButton_5_clicked()
{

        QDate selectedDate = ui->dateEdit_date->date();
        QString date = selectedDate.toString("yyyy-MM-dd");
        QDate today = QDate::currentDate();

        if (selectedDate < today) {
            QMessageBox::critical(nullptr, QObject::tr("MODIF"),
                QObject::tr("Invalid date. Date must be from today or the future.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
            return;
        }
        QString resultat=ui->comboBox_2->currentText();
        float montant=ui->lineEdit_montant->text().toFloat();
        int nb_visite=ui->lineEdit_nbvisites->text().toInt();
        int heure_entree=ui->lineEdit_he->text().toInt();
        int heure_sortie=ui->lineEdit_hs->text().toInt();
        QString matricule=ui->lineEdit_matriculevehicule->text();
        int id=ui->lineEdit_id->text().toInt();
        QString matricule_vehicule=ui->lineEdit_matriculevehicule->text();

        visite V(date,resultat,montant,nb_visite,heure_entree,heure_sortie,id,matricule_vehicule);
          int numero=ui->lineEdit_supprimer->text().toInt();



         bool test=V.modifier(numero);


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












void visite_window::on_pdf_clicked()
{
    QString strStream;
        QTextStream out(&strStream);
        const int rowCount = ui->tableView_2->model()->rowCount();
        const int columnCount =ui->tableView_2->model()->columnCount();

        out <<  "<html>\n"
                "<head>\n"
                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                <<  QString("<title>%1</title>\n").arg("visite")
                <<  "</head>\n"
                "<body bgcolor=#CFC4E1 link=#5000A0>\n"
                    "<h1>Liste des Visites</h1>"


                    "<table border=1 cellspacing=0 cellpadding=2>\n";
        // headers
            out << "<thead><tr bgcolor=#f0f0f0>";
            for (int column = 0; column < columnCount; column++)
                    out << QString("<th>%1</th>").arg(ui->tableView_2->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";
            // data table
               for (int row = 0; row < rowCount; row++)
               {
                   out << "<tr>";
                   for (int column = 0; column < columnCount; column++)
                   {
                           QString data = ui->tableView_2->model()->data(ui->tableView_2->model()->index(row, column)).toString().simplified();
                           out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));

                   }
                   out << "</tr>\n";
               }
               out <<  "</table>\n"




                   "</body>\n"

                       "</html>\n";




    QTextDocument *document = new QTextDocument();
    document->setHtml(strStream);

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("ListedesVisites.pdf");
    document->print(&printer);

}



void visite_window::on_statistique_clicked()
{
    QSqlQueryModel * mod = new QSqlQueryModel();
            mod->setQuery("select * from VISITES where MONTANT < 40 ");
            float montant=mod->rowCount();
            mod->setQuery("select * from VISITES where MONTANT  between 40 and 50 ");
            float montantt=mod->rowCount();
            mod->setQuery("select * from VISITES where MONTANT>50 ");
            float montanttt=mod->rowCount();
            float total=montant+montantt+montanttt;
            QString a=QString("moins de 40 Dinars "+QString::number((montant*100)/total,'f',2)+"%" );
            QString b=QString("entre 40 et 50 Dinars "+QString::number((montantt*100)/total,'f',2)+"%" );
            QString c=QString("+50 Dinars "+QString::number((montanttt*100)/total,'f',2)+"%" );
            QPieSeries *series = new QPieSeries();
            series->append(a,montant);
            series->append(b,montantt);
            series->append(c,montanttt);
            if (montant!=0)
            {QPieSlice *slice = series->slices().at(0);
                slice->setLabelVisible();
                slice->setPen(QPen());}
            if ( montantt!=0)
            {
                // Add label, explode and define brush for 2nd slice
                QPieSlice *slice1 = series->slices().at(1);
                //slice1->setExploded();
                slice1->setLabelVisible();
            }
            if(montanttt!=0)
            {
                // Add labels to rest of slices
                QPieSlice *slice2 = series->slices().at(2);
                //slice1->setExploded();
                slice2->setLabelVisible();
            }
            // Create the chart widget
            QChart *chart = new QChart();
            // Add data to chart with title and hide legend
            chart->addSeries(series);
            chart->setTitle("Pourcentage Par montant :montant "+ QString::number(total));
            chart->legend()->hide();
            // Used to display the chart
            QChartView *chartView = new QChartView(chart);
            chartView->setRenderHint(QPainter::Antialiasing);
            chartView->resize(1000,500);
            chartView->show();

}


void visite_window::on_Croissante_clicked()
{
    ui->tableView_2->setModel(V.triC());
}

void visite_window::on_decroissante_clicked()
{
    ui->tableView_2->setModel(V.triDec());
}

void visite_window::on_recherche_clicked()
{
    int numero=ui->lineEdit_chercher->text().toInt();
    ui->tableView_2->setModel(V.chercher_visite(numero));

}

void visite_window::on_tableView_2_activated(const QModelIndex &index)
{
    visite V;

           ui->tableView_2->setModel(V.afficher());
           QString val=ui->tableView_2->model()->data(index).toString();
           QSqlQuery qry;
           qry.prepare("SELECT * FROM VISITES WHERE NUMERO='"+val+"'");
           if(qry.exec())
           {
            if(qry.next())
            {
             ui->lineEdit_nbvisites->setText(qry.value(0).toString());
             ui->lineEdit_montant->setText(qry.value(1).toString());
             //ui->comboBox_type->setCurrentText(qry.value(2).toString());
             ui->lineEdit_he->setText(qry.value(2).toString());
             ui->lineEdit_hs->setText(qry.value(3).toString());
             ui->dateEdit_date->setDate(qry.value(4).toDate());
             ui->comboBox->setCurrentText(qry.value(5).toString());
             ui->lineEdit_id->setText(qry.value(6).toString());
             ui->lineEdit_matriculevehicule->setText(qry.value(7).toString());
                     }
                    }
                    else
                    {
                     QMessageBox::critical(this,tr("error::"),qry.lastError().text());
                    }

}
