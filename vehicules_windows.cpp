#include "vehicules_windows.h"
#include "ui_vehicules_windows.h"
vehicules_windows::vehicules_windows(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::vehicules_windows)
{
    ui->setupUi(this);
    ui->tableView->setModel(V.afficher());

    //matricule

    ui->lineEdit_matricule->setMaxLength(10);
    ui->lineEdit_matricule->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z0-9]+")));

    //marque
   ui->lineEdit_marque->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z0-9]+")));

    //AGE

     ui->lineEdit_age->setValidator(new QRegExpValidator(QRegExp("[0-9]+")));

     //NB_CHEVAUX

     ui->lineEdit_nbchevaux->setMaxLength(3);
     ui->lineEdit_nbchevaux->setValidator(new QRegExpValidator(QRegExp("[0-9]+")));

     //PUISSANCE

     ui->lineEdit_puissance->setValidator(new QRegExpValidator(QRegExp("[0-9.]+")));

     //CARBURANT

     ui->lineEdit_carburant->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));

    //CIN
     ui->lineEdit_cin->setMaxLength(8);
     ui->lineEdit_cin->setValidator(new QRegExpValidator(QRegExp("[0-9]+")));

     QFile file(":/Images/Images/voiture.jpg");
     if(!file.open(QIODevice::ReadOnly |QIODevice::Text))
     {
         qDebug()<<"erreur d'ouverture du fichier";
         return;
     }
  QTextStream in(&file);
  qDebug()<<in.readAll();
}

vehicules_windows::~vehicules_windows()
{
    delete ui;
}

void vehicules_windows::on_button_ajouter_clicked()
{
    QString matricule=ui->lineEdit_matricule->text();
    QString marque=ui->lineEdit_marque->text();
    QString type=ui->comboBox_type->currentText();
    float puissance=ui->lineEdit_puissance->text().toFloat();
    int age=ui->lineEdit_age->text().toInt();
    int nbchevaux=ui->lineEdit_nbchevaux->text().toInt();
    QString carburant=ui->lineEdit_carburant->text();
    QString CIN=ui->lineEdit_cin->text();
   vehicule V(matricule,marque,type,puissance,age,nbchevaux,carburant,CIN);

   if(V.chercher_client(V.getcin()))
   {
    bool test=V.ajouter();

    if(test)
    {
        ui->tableView->setModel(V.afficher());

               QMessageBox:: information(nullptr, QObject::tr("OK"),
                                                   QObject::tr("Ajout effectué\n"
                                                               "click cancel to exit."),QMessageBox::Cancel);

               QString chemin_image=ui->lineEdit_photo->text();

               QString repertoire="C:/"+V.getmatricule()+"_"+V.getcin();

               QDir dossier;

               if(!dossier.mkdir(repertoire))
                   qWarning() << "Impossible de créer le dossier";

               QString destination=QString("%1/%2").arg(repertoire).arg(QFileInfo(chemin_image).fileName());

               if(!QFile::copy(chemin_image,destination))
               {
                   qWarning() << "Impossible de copier l'image";
                   return;
               }
               QMessageBox::information(nullptr, QObject::tr("OK"),
                                        QObject::tr("Image créée avec succès\n"
                                                    "cliquez sur Annuler pour quitter."), QMessageBox::Cancel);
   }
    else
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("Ajout non effectué.\n"
                                              "click Cancel to exit."),QMessageBox::Cancel);
   }

   else
       QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                             QObject::tr("Client n'existe pas.\n"
                                         "click Cancel to exit."),QMessageBox::Cancel);
}

void vehicules_windows::on_button_modifier_clicked()
{

    QString matricule=ui->lineEdit_matricule->text();
    QString marque=ui->lineEdit_marque->text();
    QString type=ui->comboBox_type->currentText();
    int age=ui->lineEdit_age->text().toInt();
    int nbchevaux=ui->lineEdit_nbchevaux->text().toInt();
     float puissance=ui->lineEdit_puissance->text().toFloat();
     QString carburant=ui->lineEdit_carburant->text();
     QString cin=ui->lineEdit_cin->text();

     vehicule V(matricule,marque,type,puissance,age,nbchevaux,carburant,cin);

     bool test=V.modifier(matricule);

     if(test)
     {
         ui->tableView->setModel(V.afficher());
         QMessageBox:: information(nullptr, QObject::tr("OK"),
                                             QObject::tr("modification effectuee\n"
                                                       "click cancel to exit."),QMessageBox::Cancel);


     }
     else
         QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                               QObject::tr("modification non effectuee.\n"
                                         "click Cancel to exit."),QMessageBox::Cancel);

}

void vehicules_windows::on_button_retour_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void vehicules_windows::on_button_supprimer_clicked()
{
    QString matricule=ui->lineEdit_chercher_supprimer->text();

    if(matricule!="" && V.chercher_matricule(matricule))
       {
    bool test=V.supprimer(matricule);
    if(test)
    {
        ui->tableView->setModel(V.afficher());
        QMessageBox:: information(nullptr, QObject::tr("OK"),
                                            QObject::tr("Suppression effectué\n"
                                                        "click cancel to exit."),QMessageBox::Cancel);
        ui->stackedWidget->setCurrentIndex(0);
         }
     else
         QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                               QObject::tr("Suppression non effectué.\n"
                                       "click Cancel to exit."),QMessageBox::Cancel);
}
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Matricule à supprimer est invalide.\n"
                                      "click Cancel to exit."),QMessageBox::Cancel);
}

void vehicules_windows::on_button_rechercher_vehicule_clicked()
{
    QString mat=ui->lineEdit_chercher_supprimer->text();
    ui->tableView->setModel(V.rechercher(mat));
}

void vehicules_windows::on_radioButton_croissant_clicked()
{
    ui->tableView->setModel(V.tri_croissant());
}

void vehicules_windows::on_radioButton_decroissant_clicked()
{
    ui->tableView->setModel(V.tri_decroissant());
}

void vehicules_windows::on_button_convertir_pdf_clicked()
{
    QString strStream;
    QTextStream out(&strStream);
    const int rowCount = ui->tableView->model()->rowCount();
    const int columnCount =ui->tableView->model()->columnCount();

    out <<  "<html>\n"
            "<head>\n"
            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            <<  QString("<title>%1</title>\n").arg("vehicule")
            <<  "</head>\n"
            "<body bgcolor=#CFC4E1 link=#5000A0>\n"
                "<h1>Liste des Vehicules</h1>"


                "<table border=1 cellspacing=0 cellpadding=2>\n";
    // headers
        out << "<thead><tr bgcolor=#f0f0f0>";
        for (int column = 0; column < columnCount; column++)
                out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";
        // data table
           for (int row = 0; row < rowCount; row++)
           {
               out << "<tr>";
               for (int column = 0; column < columnCount; column++)
               {                 
                       QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
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
printer.setOutputFileName("ListeDesVehicules.pdf");
document->print(&printer);
}

void vehicules_windows::on_boutton_generer_codeqr_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void vehicules_windows::on_button_scanner_codeqr_clicked()
{
    using namespace qrcodegen;

                ///////////////// FETCH DATA FROM DATABASE ////////////////////////
                QString matricule=ui->lineEdit_matricule_codeqr->text();

                     QSqlQuery query;
                     query.prepare("SELECT * FROM VEHICULES WHERE MATRICULE=:matricule");
                     query.bindValue(":matricule",matricule);
                     query.exec();
                    ///////////////// SAVING DATA ///////////

                     if(query.next())
                     {
                     QString mat=query.value(0).toString().simplified();
                     QString marque=query.value(1).toString().simplified();
                     QString type=query.value(2).toString().simplified();
                     QString puissance=query.value(3).toString().simplified();
                     QString age=query.value(4).toString().simplified();
                     QString nb_chevaux=query.value(5).toString().simplified();
                     QString carb=query.value(6).toString().simplified();
                     QString cin=query.value(7).toString().simplified();

               QString text ="MATRICULE: "+mat+"\n"+"Marque: "+marque+"\n"+"TYPE: "+type+"\n"+"PUISSANCE: "+puissance+"\n"+"AGE: "+age+"\n"+"NOMBRE DE CHEVAUX: "+nb_chevaux+"\n"+"CARBURANT: "+carb+"\n"+"CIN: "+cin+"\n";

                  // Create the QR Code object
                  QrCode qr = QrCode::encodeText( text.toUtf8().data(), QrCode::Ecc::MEDIUM ); //9ad ma tihh niveau de correction alors codeQr ynajem yestoki akther données mais correction d'erreur tih

                  int taille = qr.getSize();
                  QImage im(taille,taille, QImage::Format_RGB32);
                    QRgb black = qRgb(0,0,0);
                    QRgb white = qRgb(255,255,255);
                  for (int i = 0; i < taille; i++)
                    for (int j = 0; j < taille; j++)
                      im.setPixel(i,j,qr.getModule(i,j) ? black : white );//setpixmap tafichilek qr code //netsa3mlouh hata l décodage mte3 codeQr

                  ui->qrcode->setPixmap( QPixmap::fromImage(im.scaled(200,200,Qt::KeepAspectRatio,Qt::FastTransformation),Qt::MonoOnly));
              }
}

void vehicules_windows::on_button_retour_codeqr_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void vehicules_windows::on_button_statistique_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    int nombre_voiture,nombre_moto,nombre_camion;
    float pourcentage_voiture,pourcentage_camion,pourcentage_moto,total;

    model->setQuery("SELECT * FROM VEHICULES WHERE TYPE='Voiture'");
    nombre_voiture=model->rowCount();

    model->setQuery("SELECT * FROM VEHICULES WHERE TYPE='Camion'");
    nombre_camion=model->rowCount();

    model->setQuery("SELECT * FROM VEHICULES WHERE TYPE='Moto'");
    nombre_moto=model->rowCount();

    total=nombre_voiture+nombre_moto+nombre_camion;

    pourcentage_voiture=(nombre_voiture*100)/total;
    pourcentage_camion=(nombre_camion*100)/total;
    pourcentage_moto=(nombre_moto*100)/total;

    QString a=QString::number(pourcentage_voiture,'f',2);
    QString b=QString::number(pourcentage_camion,'f',2);
    QString c=QString::number(pourcentage_moto,'f',2);
    a="VOITURE: "+a+"%";
    b="CAMION: "+b+"%";
    c="MOTO: "+c+"%";

    QPieSeries  *series=new QPieSeries();

    series->append(a,nombre_voiture);
    series->append(b,nombre_camion);
    series->append(c,nombre_moto);

    if(nombre_voiture!=0)
    {
        QPieSlice *slice= series->slices().at(0);
        slice->setLabelVisible();
        slice->setExploded(true);
    }
    if(nombre_camion!=0)
    {
     QPieSlice *slice1= series->slices().at(1);
     slice1->setLabelVisible();
    }

    if(nombre_moto!=0)
    {
     QPieSlice *slice2=series->slices().at(2);
     slice2->setLabelVisible();
    }
    QChart * chart=new QChart();

    chart->addSeries(series);

    chart->setTitle("Pourcentage Par Type DE VEHICULE :Nombre Des VEHICULES "+ QString::number(total));

    QChartView * chartview=new QChartView(chart);

    chartview->resize(1000,500);
    chartview->show();
}

void vehicules_windows::on_pushButton_clicked()
{
    QString file = QFileDialog::getOpenFileName(nullptr, "Sélectionner une image",QDir::homePath(), "Images (*.png *.xpm *.jpg *.jpeg)");
    ui->lineEdit_photo->setText(file);
}

void vehicules_windows::on_boutton_verifier_image_clicked()
{
    vehicule V;
    QString matricule=ui->lineEdit_chercher_supprimer->text();
    QString chemin_dossier="";
    QSqlQuery query;

    if(matricule!="" && V.chercher_matricule(matricule))
    {
        query.prepare("SELECT * FROM VEHICULES WHERE MATRICULE=:matricule");
        query.bindValue(":matricule",matricule);
        query.exec();

        QString mat=query.value(0).toString().simplified();
        QString marque=query.value(1).toString().simplified();
        QString type=query.value(2).toString().simplified();
        QString puissance=query.value(3).toString().simplified();
        QString age=query.value(4).toString().simplified();
        QString nb_chevaux=query.value(5).toString().simplified();
        QString carb=query.value(6).toString().simplified();
        QString cin=query.value(7).toString().simplified();

    QDir doss("C:/");
        QStringList fichier_dossier = doss.entryList();
        for (const auto& d:fichier_dossier)
        {
            if (d.startsWith(matricule))
            {
                chemin_dossier=d;
            }
        }
        if(chemin_dossier!="")
        {
        chemin_dossier="C:/"+chemin_dossier;
          QDir dossier(chemin_dossier);
          QStringList filters;

              filters << "*.jpg" << "*.jpeg" << "*.png" << "*.gif";
              qDebug()<<filters[0];
               dossier.setNameFilters(filters); //récupération des tous les images dans le répertoire

                QFileInfoList files = dossier.entryInfoList();
               QString chemin_complet=chemin_dossier+"/"+files[0].fileName();
               QPixmap image_vehicule(chemin_complet);
               QChart *chart = new QChart();

               QGraphicsPixmapItem *imageV = new QGraphicsPixmapItem(image_vehicule);
               QGraphicsScene *scene = new QGraphicsScene();
               scene->addItem(imageV);

               QChartView *chartView = new QChartView(chart);

               // Ajouter la scène au QGraphicsView
               chartView->setScene(scene);
               chartView->show();
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                  QObject::tr("Vous n'avez pas inserer une image pour cette vehicule !!!.\n"
                                          "click Cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Matricule est invalide.\n"
                                      "click Cancel to exit."),QMessageBox::Cancel);
}

void vehicules_windows::on_tableView_activated(const QModelIndex &index)
{
    vehicule v;

       ui->tableView->setModel(v.afficher());
       QString val=ui->tableView->model()->data(index).toString();
       QSqlQuery qry;
       qry.prepare("SELECT * FROM VEHICULES WHERE MATRICULE='"+val+"'");
       if(qry.exec())
       {
        if(qry.next())
        {
         ui->lineEdit_matricule->setText(qry.value(0).toString());
         ui->lineEdit_marque->setText(qry.value(1).toString());
         ui->comboBox_type->setCurrentText(qry.value(2).toString());
         ui->lineEdit_puissance->setText(qry.value(3).toString());
         ui->lineEdit_age->setText(qry.value(4).toString());
         ui->lineEdit_nbchevaux->setText(qry.value(5).toString());
         ui->lineEdit_carburant->setText(qry.value(6).toString());
         ui->lineEdit_cin->setText(qry.value(7).toString());
        }
       }
       else
       {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
       }
}
