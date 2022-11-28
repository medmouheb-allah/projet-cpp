#include "interface.h"
#include "ui_interface.h"
#include "ui_stat.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include<QIntValidator>
#include<QMessageBox>
#include <QString>
#include <QtPrintSupport>
#include "smtp.h"
#include "facture.h"
#include"fournisseur.h"
#include "arduino.h"

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
      ui->table_facture->setModel(A.afficher());
      ui->comboBox_2->setModel(A.combo_fournisseur());
      ui->comboBox_3->setModel(A.combo_evenement());
      int ret=C.connect_arduino(); // lancer la connexion à arduino
      switch(ret){
      case(0):qDebug()<< "arduino is available and connected to : "<< C.getarduino_port_name();
          break;
      case(1):qDebug() << "arduino is available but not connected to :" <<C.getarduino_port_name();
         break;
      case(-1):qDebug() << "arduino is not available";
      }
       QObject::connect(C.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
       //le slot update_label suite à la reception du signal readyRead (reception des données).



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
    int CODE_EVENNEMENT=ui->comboBox_3->currentText().toInt();
    QString ID_FOURNISSEUR=ui->comboBox_2->currentText();
    QString DESCRIPTION = ui->le_description->text();
    QString QUANTITE=ui->le_quantite->text();
    QString PRIXUNIT =ui->le_prix ->text();
    QString TOTAL = ui ->le_total ->text();


        Facture C(DESCRIPTION,QUANTITE,PRIXUNIT,TOTAL,ID_FOURNISSEUR,CODE_EVENNEMENT);
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
    QString ID_FOURNISSEUR =ui->comboBox_2->currentText();
    int CODE_EVENNEMENT=ui->comboBox_3->currentText().toInt();

QString DESCRIPTION = ui->le_description->text();
QString QUANTITE=ui->le_quantite->text();
QString PRIXUNIT =ui->le_prix ->text();
QString TOTAL = ui ->le_total ->text();


    Facture C(DESCRIPTION,QUANTITE,PRIXUNIT,TOTAL,ID_FOURNISSEUR,CODE_EVENNEMENT);
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
          ui->comboBox_2->currentText();
          ui->comboBox_3->currentText();
          ui->setupUi(this);

       }
ui->table_facture->setModel(A.afficher());
}
void Interface::update_label()
{

    data=C.read_from_arduino();
//QString x=QString::fromStdString(data.toStdString());
       // ui->labelmsg->setText(data);

       // QString data = C.read_from_arduino();
        int result = data.split( ',' )[0].toInt();
        qDebug()<< result;
        if (result == 0 )
            ui->fireLabel->setText("FIRE");
        else if (result == 1)
            ui->fireLabel->setText("NO FIRE");

 /* if(data=="1")
  {
      ui->labelmsg->setText("ON"); // si les données reçues de arduino via la liaison série sont égales à 1
  // alors afficher ON
  }

   /* else if (data=="0")
  {
      ui->label->setText("OFF");   // si les données reçues de arduino via la liaison série sont égales à 0
   //alors afficher off
  }

  else if(data=="2")
  {
      ui->label->setText("AUTO");   // si les données reçues de arduino via la liaison série sont égales à 2
   //alors afficher auto
  }*/
}


void Interface::on_pushButton_2_clicked()
{
    C.write_to_arduino("0"); //envoyer 0 à arduino

}

void Interface::on_pushButton_3_clicked()
{
    C.write_to_arduino("1"); //envoyer 1 à arduino
}

void Interface::on_pushButton_4_clicked()
{
    /* data=C.read_from_arduino();
     int x=data.toInt();
     if(x>73)
     C.write_to_arduino("1"); //envoyer 1 à arduino
     else
      C.write_to_arduino("0"); //envoyer 0 à arduino*/
   //  mod auto
     C.write_to_arduino("2"); //envoyer 2 à arduino*/


}

void Interface::on_refreshButton_clicked()
{
}

void Interface::on_offButton_clicked()
{
        C.write_to_arduino("s");
    }


