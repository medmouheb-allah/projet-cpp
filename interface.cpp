#include "interface.h"
#include "ui_interface.h"
#include "ui_stat.h"
#include<QIntValidator>
#include<QMessageBox>
#include <QString>
#include <QtPrintSupport>
#include "smtp.h"
#include "facture.h"
#include"fournisseur.h"

Interface::Interface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Interface)
{

    ui->setupUi(this);
      ui->le_id->setValidator(new QIntValidator(100, 999999999, this));
      ui->le_num->setValidator(new QIntValidator(100, 999999999, this));
      ui->tableView->setModel(F.afficher());
      ui->le_prix->setValidator(new QIntValidator(100, 999999999, this));
      ui->le_total->setValidator(new QIntValidator(100, 999999999, this));
      ui->tableView->setModel(A.afficher());
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
                                QObject::tr("FOURNISSEUR modifié.\n"), QMessageBox::Cancel);
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







void Interface::on_recherche_textChanged(const QString &arg1)
{
    ui->tableView->setModel(F.rechercherID(arg1));
}

void Interface::on_comboBox_currentIndexChanged(int index)
{
    {
        if(index == 1)
            ui->tableView->setModel(F.Trieid());
        else if(index == 2)
               ui->tableView->setModel(F.Trienom());
           else if(index == 3)
               ui->tableView->setModel(F.TriePrenom());
        else
           ui->tableView->setModel(F.afficher());
    }
}


void Interface::on_pushButton_5_clicked()
{
    Fournisseur F;
    QString text=F.exporter();
    ui->print->setText(text);
    QPrinter printer ;
    printer.setPrinterName("imprim");
    QPrintDialog dialog (&printer,this);
    if(dialog.exec()==QDialog::Rejected) return ;
    ui->print->print(&printer);

}

void Interface::on_sendBtn_clicked()
{
    Smtp* smtp = new Smtp("sarra.benhamouda@esprit.tn", "211JFT2523", "smtp.gmail.com", 465);

        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

        QString a=ui->rcpt->text();

        QString b=ui->subject->text();

        QString c=ui->msq->text();



        smtp->sendMail("sarra.benhamouda@esprit.tn", a , b,c);
}

void Interface::on_pushButton_7_clicked()
{
    QString DESCRIPTION = ui->le_description->text();
    QString QUANTITE=ui->le_quantite->text();
    QString PRIXUNIT =ui->le_prix ->text();
    QString TOTAL = ui ->le_total ->text();


        Facture C(DESCRIPTION,QUANTITE,PRIXUNIT,TOTAL);
        bool test=C.ajouter();
        QMessageBox msgBox;
        if(test)
        {msgBox.setText("ajout avec succes");
        ui->table_facture->setModel(A.afficher());
        }
        else
            msgBox.setText("Echec d'ajout");
        msgBox.exec();
}

void Interface:: on_pushButton_clicked()
{
QString DESCRIPTION = ui->le_description->text();
QString QUANTITE=ui->le_quantite->text();
QString PRIXUNIT =ui->le_prix ->text();
QString TOTAL = ui ->le_total ->text();


    Facture C(DESCRIPTION,QUANTITE,PRIXUNIT,TOTAL);
    if(C.modifier_facture(DESCRIPTION))
       {
                QMessageBox::information(nullptr, QObject::tr("Modifier une FACTURE"),
                            QObject::tr("FACTURE modifié.\n"), QMessageBox::Cancel);
                ui->table_facture->setModel(C.afficher());



       }
       else
       {
          QMessageBox::critical(nullptr, QObject::tr("Modifier une FACTURE"),

                                QObject::tr("Erreur !!!!!!!!\n"), QMessageBox::Cancel);
          ui->le_description->setText("");
          ui->le_quantite->setText("");
          ui->le_prix->setText("");
          ui->le_total->setText("");


       }

}


