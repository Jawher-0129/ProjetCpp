#ifndef VEHICULES_WINDOWS_H
#define VEHICULES_WINDOWS_H
#include <QDir>
#include <QApplication>
#include <QTableView>
#include <QStandardItemModel>
#include <QStringList>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include <QMainWindow>
#include <QFile>
#include <QSqlError>
#include "vehicule.h"
#include <QDebug>
#include <QtCore/QRegExp>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QtCharts/QBarSeries>
#include "qrcodegen.h"

QT_BEGIN_NAMESPACE
namespace Ui { class vehicules_windows; }
QT_END_NAMESPACE

class vehicules_windows : public QMainWindow
{
    Q_OBJECT

public:
    vehicules_windows(QWidget *parent = nullptr);
    ~vehicules_windows();

private slots:

    void on_button_ajouter_clicked();

    void on_button_modifier_clicked();

    void on_button_retour_clicked();

    void on_button_supprimer_clicked();

    void on_button_rechercher_vehicule_clicked();

    void on_radioButton_croissant_clicked();

    void on_radioButton_decroissant_clicked();

    void on_button_convertir_pdf_clicked();

    void on_boutton_generer_codeqr_clicked();

    void on_button_scanner_codeqr_clicked();

    void on_button_retour_codeqr_clicked();

    void on_button_statistique_clicked();

    void on_pushButton_clicked();

    void on_boutton_verifier_image_clicked();

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::vehicules_windows *ui;
    vehicule V;
};
#endif // VEHICULES_WINDOWS_H
