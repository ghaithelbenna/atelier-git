#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "avion.h"
#include <QApplication>
#include <QMessageBox>
#include<QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_Num->setValidator(new QIntValidator(0,999,this));
    ui->le_vitesse->setValidator(new QIntValidator(0,920,this));
ui->tab_avion->setModel(a.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_LE_AJOUT_clicked()
{
    int Num=ui->le_Num->text().toInt();
    int vitesse=ui->le_vitesse->text().toInt();
    int nb_reparation=ui->le_nb_reparation->text().toInt();
    int nb_p_changer=ui->le_nb_p_changer->text().toInt();
    QString marque=ui->le_marque->text();
    float consom=ui->le_consom->text().toFloat();
    float prix_achat=ui->le_prix_achat->text().toFloat();
    QString etat=ui->le_etat->text();
 avion a(Num,vitesse,nb_reparation,nb_p_changer,marque,consom,prix_achat,etat);
 bool test=a.ajouter();

 if(test)
 {
  QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("AJOUT EFFECTUER.\n" "click Cancel to exit."), QMessageBox::Cancel);
 ui->tab_avion->setModel(a.afficher());
 }
 else
     QMessageBox::critical(nullptr, QObject::tr("NON"),QObject::tr("AJOUT NON EFFECTUER.\n " "click Cancel to exit ."), QMessageBox::Cancel);

}



void MainWindow::on_bt_sup_clicked()
{
    int n=ui->le_Num->text().toInt();
         bool test=a.supprimer(n);
         if (test)
         {
             ui->tab_avion->setModel(a.afficher());
            QMessageBox :: information (nullptr, QObject ::tr("OK"),
                          QObject ::tr("suppression effectué\n"
                                       "click cancel to exit"),
                     QMessageBox:: Cancel);

        }
         else
         {
             QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                  QObject::tr("try again.\n"
                                              "click cancel to exit."),QMessageBox::Cancel);
         }
    }




void MainWindow::on_bt_modif_clicked()
{
    int Num=ui->le_Num->text().toInt();
    int vitesse=ui->le_vitesse->text().toInt();
    int nb_reparation=ui->le_nb_reparation->text().toInt();
    int nb_p_changer=ui->le_nb_p_changer->text().toInt();
    QString marque=ui->le_marque->text();
    float consom=ui->le_consom->text().toFloat();
    float prix_achat=ui->le_prix_achat->text().toFloat();
    QString etat=ui->le_etat->text();

 avion a(Num,vitesse,nb_reparation,nb_p_changer,marque,consom,prix_achat,etat);
 bool test=a.modifier();

               if(test)

           {ui->tab_avion->setModel(a.afficher());


               QMessageBox :: information (nullptr, QObject ::tr("OK"),

                            QObject ::tr("modifier effectué\n"

                                         "click cancel to exit"),

                       QMessageBox:: Cancel);



       }

           else

           {

               QMessageBox::critical(nullptr,QObject::tr("not ok"),

                                    QObject::tr("try again.\n"

                                                "click cancel to exit."),QMessageBox::Cancel);

           }
}








void MainWindow::on_bt_rech_Num_clicked()
    {
       int Num=ui->chercher_Num->text().toInt();
              {  if (Num==0) {
                    QMessageBox::information(this, tr("Empty Field"),
                        tr("Please enter a Number."));
                    return;
                } else {
                ui->tab_recherche->setModel(atmp.recherche_ID(Num));
            }}
    }




void MainWindow::on_bt_rech_ETAT_clicked()
 {
         QString etat=ui->chercher_etat->text();
              {  if (etat==0) {
                    QMessageBox::information(this, tr("Empty Field"),
                        tr("Please enter a Number."));
                    return;
                } else {
                ui->tab_recherche->setModel(btmp.recherche_etat(etat));
            }}
    }



void MainWindow::on_bt_rech_MARQUE_clicked()
{

            QString marque=ui->chercher_marque->text();
                 {  if (marque==0) {
                       QMessageBox::information(this, tr("Empty Field"),
                           tr("Please enter a Number."));
                       return;
                   } else {
                   ui->tab_recherche->setModel(ctmp.recherche_MARQUE(marque));
               }}
}

void MainWindow::on_bt_tri_clicked()
{

    ui->tab_avion->setModel(.tri_num());

}

void MainWindow::on_bt_recH_PRIX_clicked()
 {

                QString prix_achat=ui->chercher_prix_achat->text().toFloat();
                     {  if (prix_achat==0) {
                           QMessageBox::information(this, tr("Empty Field"),
                               tr("Please enter a Number."));
                           return;
                       } else {
                       ui->tab_recherche->setModel(dtmp.recherche_prix(prix_achat));
                   }}
    }

