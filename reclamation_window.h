#ifndef RECLAMATION_WINDOW_H
#define RECLAMATION_WINDOW_H
#include "reclamation.h"
#include <QMainWindow>
#include <QtPrintSupport/QPrinter>
#include <QLineSeries>
#include <QtCharts>
#include <QChartView>

QT_BEGIN_NAMESPACE
namespace Ui { class reclamation_window; }
QT_END_NAMESPACE

class reclamation_window : public QMainWindow
{
    Q_OBJECT

public:
    reclamation_window(QWidget *parent = nullptr);
    ~reclamation_window();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_22_clicked();




    void on_pushButton_26_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_30_clicked();

    void on_button_rechercher_reclamation_clicked();

    void on_radioButton_tri_croissant_clicked();

    void on_radioButton_tri_decroissant_clicked();



    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();

private:
    Ui::reclamation_window *ui;
    reclamation R;
};
#endif // RECLAMATION_WINDOW_H
