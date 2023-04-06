#ifndef VISITE_WINDOW_H
#define VISITE_WINDOW_H
#include "visite.h"
#include <QMainWindow>
#include <QtPrintSupport/QPrinter>
#include <QLineSeries>
#include <QtCharts>
#include <QChartView>
#include <QSqlError>

QT_BEGIN_NAMESPACE
namespace Ui { class visite_window; }
QT_END_NAMESPACE

class visite_window : public QMainWindow
{
    Q_OBJECT

public:
    visite_window(QWidget *parent = nullptr);
    ~visite_window();

private slots:


    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_14_clicked();


    void on_pushButton_5_clicked();




    void on_pdf_clicked();



    void on_statistique_clicked();



    void on_Croissante_clicked();

    void on_decroissante_clicked();

    void on_recherche_clicked();

    void on_tableView_2_activated(const QModelIndex &index);

private:
    Ui::visite_window *ui;
    visite V;
};
#endif // VISITE_WINDOW_H
