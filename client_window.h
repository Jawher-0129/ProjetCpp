#ifndef CLIENT_WINDOW_H
#define CLIENT_WINDOW_H
#include <QDebug>
#include "client.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class client_window; }
QT_END_NAMESPACE

class client_window : public QMainWindow
{
    Q_OBJECT

public:
    client_window(QWidget *parent = nullptr);
    ~client_window();

private slots:


     



    void on_client_recherche_clicked();

    void on_client_supprimer_clicked();

    void on_client_modifier_clicked();

    void on_recherche_affiche_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_client_ajouter_button_clicked();

    

    void on_ajouter_client_clicked();

   

  

    void on_client_convert_to_pdf_clicked();

   

    void on_afficher_stats_client_clicked();

private:
    Ui::client_window *ui;
    client c;
};
#endif // CLIENT_WINDOW_H
