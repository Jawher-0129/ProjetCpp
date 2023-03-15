#ifndef VISITE_WINDOW_H
#define VISITE_WINDOW_H
#include "visite.h"
#include <QMainWindow>

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

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::visite_window *ui;
    visite V;
};
#endif // VISITE_WINDOW_H
