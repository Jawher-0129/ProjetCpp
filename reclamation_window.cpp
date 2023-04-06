#include "reclamation_window.h"
#include "ui_reclamation_window.h"
reclamation_window::reclamation_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::reclamation_window)
{
    ui->setupUi(this);
    ui->tableView_2->setModel(R.afficher());
    ui->lineEdit_etat_modifier->setText("0");
    ui->lineEdit_nom_client->setMaxLength(20);
    ui->lineEdit_nom_client_modifier->setMaxLength(20);
    ui->lineEdit_prenom_client->setMaxLength(20);
    ui->lineEdit_prenom_client_modifeir->setMaxLength(20);
    ui->lineEdit_cin_client->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_nom_client->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
    ui->lineEdit_prenom_client->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
}

reclamation_window::~reclamation_window()
{
    delete ui;
}


void reclamation_window::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void reclamation_window::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void reclamation_window::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void reclamation_window::on_pushButton_5_clicked()
{
    this->close();
}

void reclamation_window::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void reclamation_window::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void reclamation_window::on_pushButton_18_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void reclamation_window::on_pushButton_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void reclamation_window::on_pushButton_20_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void reclamation_window::on_pushButton_22_clicked()
{

    QString nom_client=ui->lineEdit_nom_client->text();
    QString prenom_client=ui->lineEdit_prenom_client->text();
    QString email_client=ui->lineEdit_email_client->text();
    QString type=ui->comboBox->currentText();
    QString cin_client=ui->lineEdit_cin_client->text();
    QString message=ui->plainTextEdit->toPlainText();

    int etat=0;
    reclamation R(nom_client,prenom_client,email_client,type,cin_client,etat,message);


    if (R.verif_email(email_client))
    {
        bool test=R.ajouter();
    if(test)
    {
        ui->tableView_2->setModel(R.afficher());
        QMessageBox:: information(nullptr, QObject::tr("OK"),
                                                           QObject::tr("Ajout effectué\n"
                                                                       "click cancel to exit."),QMessageBox::Cancel);
                        }
                    else
                        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                              QObject::tr("Ajout non effectué,client n'existe pas\n"

                                                          "click Cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Email invalide !!!\n"

                                          "click Cancel to exit."),QMessageBox::Cancel);

}


void reclamation_window::on_pushButton_26_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void reclamation_window::on_pushButton_29_clicked()
{
    int num=ui->lineEdit_supprimer->text().toInt();

    if(R.chercher_reclamation(num))
    {

    bool test=R.supprimer(num);

    if(test)
    {

        ui->tableView_2->setModel(R.afficher());
        QMessageBox:: information(nullptr, QObject::tr("OK"),
                                                           QObject::tr("Suppression effectué\n"
                                                                       "click cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Suppression non effectué.\n"
                                          "click Cancel to exit."),QMessageBox::Cancel);

    }
}

void reclamation_window::on_pushButton_25_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}



void reclamation_window::on_pushButton_31_clicked()
{
    QString cin_client=ui->lineEdit_cin_client_modifier->text();
    QString nom_client=ui->lineEdit_nom_client_modifier->text();
    QString prenom_client=ui->lineEdit_prenom_client_modifeir->text();
    QString email_client=ui->lineEdit_email_client_modifier->text();
    QString type=ui->comboBox_2->currentText();
    int etat=ui->lineEdit_etat_modifier->text().toInt();
    QString message=ui->plainTextEdit->toPlainText();
    int num=ui->lineEdit_numero_modifier->text().toInt();

    reclamation R(nom_client,prenom_client,email_client,type,cin_client,etat,message);

    bool test=R.modifier(num);
    if(R.verif_email(email_client))
    {
    if(test)
     {
        ui->tableView_2->setModel(R.afficher());
        QMessageBox:: information(nullptr, QObject::tr("OK"),
                                                           QObject::tr("Modification effectué\n"
                                                                       "click cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Modification non effectué.\n"
                                          "click Cancel to exit."),QMessageBox::Cancel);


    }

}

void reclamation_window::on_pushButton_32_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void reclamation_window::on_pushButton_30_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void reclamation_window::on_button_rechercher_reclamation_clicked()
{
    QString val=ui->lineEdit_rechercher->text();
    ui->tableView_2->setModel(R.rechercher_reclamation_numero(val));
}

void reclamation_window::on_radioButton_tri_croissant_clicked()
{
    ui->tableView_2->setModel(R.triC());
}

void reclamation_window::on_radioButton_tri_decroissant_clicked()
{
    ui->tableView_2->setModel(R.triDec());
}


void reclamation_window::on_pushButton_27_clicked()
{
    QString strStream;
        QTextStream out(&strStream);
        const int rowCount = ui->tableView_2->model()->rowCount();
        const int columnCount =ui->tableView_2->model()->columnCount();

        out <<  "<html>\n"
                "<head>\n"
                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                <<  QString("<title>%1</title>\n").arg("vehicule")
                <<  "</head>\n"
                "<body bgcolor=#CFC4E1 link=#5000A0>\n"
                    "<h1>Liste des Reclamations</h1>"


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
    printer.setOutputFileName("ListedesReclamations.pdf");
    document->print(&printer);

}

void reclamation_window::on_pushButton_28_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    int nb_service,nb_qualite,nb_prix,nb_autres;
    float pourcentage_serivce,pourcentage_qualite,pourcentage_prix,pourcentage_autres,total;

    model->setQuery("SELECT * FROM RECLAMATIONS WHERE TYPE_RECLAMATION='Service'");
    nb_service=model->rowCount();

    model->setQuery("SELECT * FROM RECLAMATIONS WHERE TYPE_RECLAAMTION='Qualité'");
    nb_qualite=model->rowCount();

    model->setQuery("SELECT * FROM RECLAMATIONS WHERE TYPE_RECLAMATION='Prix'");
    nb_prix=model->rowCount();

    model->setQuery("SELECT * FROM RECLAMATIONS WHERE TYPE_RECLAMATION='Autres'");
    nb_autres=model->rowCount();

    total=nb_service+nb_qualite+nb_prix+nb_autres;

    pourcentage_serivce=(nb_service*100)/total;
    pourcentage_qualite=(nb_qualite*100)/total;
    pourcentage_prix=(nb_prix*100)/total;
    pourcentage_autres=(nb_autres*100)/total;


    QString a=QString::number(pourcentage_serivce,'f',2);
    QString b=QString::number(pourcentage_qualite,'f',2);
    QString c=QString::number(pourcentage_prix,'f',2);
    QString d=QString::number(pourcentage_autres,'f',2);
    a="Service: "+a+"%";
    b="Qualité: "+b+"%";
    c="Prix: "+c+"%";
    d="Autres: "+d+"%";

    QPieSeries  *series=new QPieSeries();

    series->append(a,nb_service);
    series->append(b,nb_qualite);
    series->append(c,nb_prix);
    series->append(d,nb_autres);

    if(nb_service!=0)
    {
        QPieSlice *slice= series->slices().at(0);
        slice->setLabelVisible();
        slice->setExploded(true);
    }

    if(nb_qualite!=0)
    {
     QPieSlice *slice1= series->slices().at(1);
     slice1->setLabelVisible();
    }

    if(nb_prix!=0)
    {
     QPieSlice *slice2=series->slices().at(2);
     slice2->setLabelVisible();
    }

    if(nb_autres!=0)
    {
     QPieSlice *slice3=series->slices().at(3);
     slice3->setLabelVisible();
    }

    QChart * chart=new QChart();

    chart->addSeries(series);

    chart->setTitle("Nombre Des RECLAMATIONS: "+ QString::number(total));

    QChartView * chartview=new QChartView(chart);

    chartview->resize(1000,500);
    chartview->show();
}
