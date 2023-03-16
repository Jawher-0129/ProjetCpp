#ifndef EMPWINDOW_H
#define EMPWINDOW_H
#include "emp.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class empWindow; }
QT_END_NAMESPACE

class empWindow : public QMainWindow
{
    Q_OBJECT

public:
    empWindow(QWidget *parent = nullptr);
    ~empWindow();

private slots:



    void on_ajouter_clicked();

    void on_supprimer1_clicked();

    void on_supprimer2_clicked();

    void on_modifier_clicked();

    void on_modifier2_clicked();



    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton1_clicked();

    void on_pushButton_13_clicked();

private:
    Ui::empWindow *ui;
    Emp e;
};
#endif // EMPWINDOW_H
