#include "interface.h"
#include "ui_interface.h"
#include<QIntValidator>
#include<QMessageBox>
#include <QString>
#include"fournisseur.h"

Interface::Interface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Interface)
{

    ui->setupUi(this);
      ui->le_id->setValidator(new QIntValidator(100, 999999999, this));
      ui->le_num->setValidator(new QIntValidator(100, 999999999, this));
      ui->tableView->setModel(F.afficher());
}
Interface::~Interface()
{
    delete ui;
}

void Interface::on_pb_ajouter_clicked()

    {
        QString ID_FOURNISSEUR = ui->le_id->text();
        QString NOM=ui->le_nom->text();
        QString PRENOM =ui->le_prenom ->text();
        QString EMAIL = ui ->le_mail ->text();
        QString NUMERO = ui->le_num->text();

            Fournisseur B(ID_FOURNISSEUR,NOM,PRENOM,EMAIL,NUMERO);
            bool test=B.ajouter();
            QMessageBox msgBox;
            if(test)
            {msgBox.setText("ajout avec succes");
            ui->tableView->setModel(F.afficher());
            }
            else
                msgBox.setText("Echec d'ajout");
            msgBox.exec();
        }

        //

void Interface::on_pb_supprimer_clicked()
    {
        Fournisseur F1; F1.setid(ui->supprimer->text());
        bool test = F1.supprimer(F1.getid());
        QMessageBox msgBox;
        if (test){
            msgBox.setText("suppression ");
        ui->tableView->setModel(F.afficher());
        }
        else {
            msgBox.setText("echec");
            msgBox.exec();
    }
    }




void Interface::on_pb_modifier_clicked()
{
    QString ID_FOURNISSEUR = ui->le_id->text();
    QString NOM=ui->le_nom->text();
    QString PRENOM =ui->le_prenom ->text();
    QString EMAIL = ui ->le_mail ->text();
    QString NUMERO = ui->le_num->text();

        Fournisseur B(ID_FOURNISSEUR,NOM,PRENOM,EMAIL,NUMERO);
        if(B.modifier_fournisseur(ID_FOURNISSEUR))
           {
                    QMessageBox::information(nullptr, QObject::tr("Modifier un FOURNISSEUR"),
                                QObject::tr("Vol modifié.\n"), QMessageBox::Cancel);
                    ui->tableView->setModel(B.afficher());



           }
           else
           {
              QMessageBox::critical(nullptr, QObject::tr("Modifier un FOURNISSEUR"),

                                    QObject::tr("Erreur !!!!!!!!\n"), QMessageBox::Cancel);
              ui->le_id->setText("");
              ui->le_nom->setText("");
              ui->le_prenom->setText("");
              ui->le_mail->setText("");
              ui->le_num->setText("");

           }

}
