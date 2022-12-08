#include "dialog.h"
#include "ui_dialog.h"
#include"employe.h"
#include<QMessageBox>
#include "connection.h"
#include"stat_combo.h"
#include<QWidget>
#include<QTime>
#include <QHostAddress>
#include"mainwindow.h"
#include"globals.h"



Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    employe emp ;
    //connection c ;
    //bool test ;
    //test= c.createconnection() ;
    ui->setupUi(this);

    ui->lineEdit_3->setValidator(new QIntValidator(1000000,999999999,this) ) ;
    ui->lineEdit_5->setValidator(new QIntValidator(1000,99999999,this)) ;

    QRegularExpression r1("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",QRegularExpression::CaseInsensitiveOption);

    ui->lineEdit->setValidator(new QRegularExpressionValidator(r1, this));

    QRegularExpression r2("\\b[A-Z._%+-]+@[A-Z.-]+\\.[A-Z]\\b",QRegularExpression::CaseInsensitiveOption);
    ui->lineEdit_2->setValidator(new QRegularExpressionValidator(r2, this));

    QRegularExpression r3("\\b[A-Z._%+-]+@[A-Z.-]*\\.[A-Z]\\b",QRegularExpression::CaseInsensitiveOption);
    ui->lineEdit_4->setValidator(new QRegularExpressionValidator(r3, this));




  /*  int CIN=ui->lineEdit_3->text().toInt() ;
    int num =ui->lineEdit_5->text().toInt() ;

    if(CIN < 9999999 || ui->lineEdit->text() == "" || ui->lineEdit_2->text() == "" || ui->lineEdit_4->text() == "" || num < 99999999)
    {
               ui->lineEdit_3->setStyleSheet("border: 1px solid red;");
               if(CIN > 999999 )
               {
                   ui->lineEdit_3->setStyleSheet("border: 1px solid black;");
               }

               ui->lineEdit->setStyleSheet("border: 1px solid red;") ;

               if( ui->lineEdit->text()!= "" )
                   ui->lineEdit->setStyleSheet("border: 1px solid black;") ;
               }*/



        ui->comboBox->addItem("CIN");
        ui->comboBox->addItem("Nom");
        ui->comboBox->addItem("Prenom");
        ui->comboBox_2->setModel(emp.tester());
        ui->comboBox_2->setModel(emp.tester());
        ui->affichage_employe->setModel(em.afficher()) ;


        ui->comboBox_4->setModel(em.afficher2()) ;
        //chat
            socket.connectToHost(QHostAddress("127.0.0.1"), 9999);
            connect(&socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));

            connect(ui->sendbutton, SIGNAL(pressed()), this, SLOT(onSendButtonPressed()));


        //Arduino
            int ret=A.connect_arduino(); // lancer la connexion à arduino
            switch(ret){
            case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
                break;
            case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
               break;
            case(-1):qDebug() << "arduino is not available";
            }
             QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));


}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_bouton1_clicked()
{
    QString nom =ui->lineEdit->text() ;
    QString prenom =ui->lineEdit_2->text() ;
    QString email = ui->lineEdit_4->text() ;
    QString genre = ui->comboBox_3->currentText() ;
    QString role = ui->role->currentText() ;
    int id=ui->lineEdit_3->text().toInt() ;
    int num =ui->lineEdit_5->text().toInt() ;
    employe emp(id,email,nom,prenom,num,genre,role) ;

    bool test=emp.ajouter() ;
    if (test)
       {
    QMessageBox :: information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectue.\n""click cancel to exit"),QMessageBox::Cancel) ;
    }
    else
    {
         QMessageBox :: critical(nullptr,QObject::tr("not ok"),QObject::tr("ajout non effectue.\n""click cancel to exit"),QMessageBox::Cancel) ;
    }
 ui->comboBox_2->setModel(emp.tester());
    ui->affichage_employe->setModel(emp.afficher()) ;

}


void Dialog::on_pushButton_3_clicked()
{
    employe emp;
       emp.setID(ui->comboBox_2->currentText().toInt());
       bool test=emp.supprimer(emp.getID());
       QMessageBox msgBox;

       if(test)
       {
           QMessageBox::information(nullptr, QObject::tr("OK"),
                       QObject::tr("supp effectué.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
           ui->affichage_employe->setModel(emp.afficher());
            ui->comboBox_2->setModel(emp.tester());
             ui->comboBox_2->setModel(emp.tester());
       }
    if (test)
    {
    QMessageBox :: information(nullptr,QObject::tr("ok"),QObject::tr("suppression effectue.\n""click cancel to exit"),QMessageBox::Cancel) ;
    }
    else
    {
         QMessageBox :: critical(nullptr,QObject::tr("not ok"),QObject::tr("suppression non effectue.\n""click cancel to exit"),QMessageBox::Cancel) ;
    }
    ui->affichage_employe->setModel(em.afficher()) ;

}





void Dialog::on_b2_clicked()
{
    employe em ;

     int id,tel;
     QString nom,prenom,e_mail,genre,role;

        id=ui->lineEdit_3->text().toInt();
        nom=ui->lineEdit->text();
        prenom=ui->lineEdit_2->text();
        e_mail=ui->lineEdit_4->text();
        tel=ui->lineEdit_5->text().toInt();
        genre=ui->comboBox_3->currentText() ;
        role=ui->role->currentText() ;

        bool test= em.modifier(id,e_mail,nom,prenom,tel,genre,role);
      if (test)
       {
       QMessageBox :: information(nullptr,QObject::tr("ok"),QObject::tr("modification effectue.\n""click cancel to exit"),QMessageBox::Cancel) ;
       }
       else
       {
            QMessageBox :: critical(nullptr,QObject::tr("not ok"),QObject::tr("modification non effectue.\n""click cancel to exit"),QMessageBox::Cancel) ;
       }
        ui->affichage_employe->setModel(em.afficher());

}



void Dialog::on_affichage_employe_doubleClicked()
{
   // selected=ui->affichage_employe->model()
    QModelIndex index = ui->affichage_employe->currentIndex();
             QString ci = index.data(Qt::DisplayRole).toString();
              QString nom = ui->affichage_employe->model()->index(index.row(), 2).data(Qt::DisplayRole).toString();
              ui->lineEdit->setText(nom);
               QString prenom = ui->affichage_employe->model()->index(index.row(), 3).data(Qt::DisplayRole).toString();
                 ui->lineEdit_2->setText(prenom);
                QString email = ui->affichage_employe->model()->index(index.row(), 1).data(Qt::DisplayRole).toString();
                 ui->lineEdit_4->setText(email);
                 QString tel = ui->affichage_employe->model()->index(index.row(), 4).data(Qt::DisplayRole).toString();
                 ui->lineEdit_5->setText(tel) ;
                  QString cin = ui->affichage_employe->model()->index(index.row(), 0).data(Qt::DisplayRole).toString();
                  ui->lineEdit_3->setText(cin);
 QString genre = ui->affichage_employe->model()->index(index.row(), 5).data(Qt::DisplayRole).toString();
                  ui->comboBox_3->setCurrentText(genre) ;

}



//Affichage trier
void Dialog::on_pushButton_2_clicked()
{
    employe emp ;
    QString tri= ui->comboBox->currentText() ;

    if(tri=="Nom")
    {

        ui->affichage_employe->setModel(emp.AfficherTrieNom()) ;
    }  else
        if (tri=="CIN")
        {
        ui->affichage_employe->setModel(emp.AfficherTrieCIN()) ;
        }
        else
        {
        ui->affichage_employe->setModel(emp.AfficherTriePrenom()) ;
        }
    }




/*void Dialog::on_pushButton_8_clicked()
{
    employe emp;
    QString aff= ui->lineEdit_8->text() ;
    ui->affichage_employe->setModel(emp.rechercherafficher(aff)) ;
}
*/


//export pdf
void Dialog::on_pushButton_5_clicked()
{
    QString strStream;
                QTextStream out(&strStream);

                const int rowCount = ui->affichage_employe->model()->rowCount();
                const int columnCount = ui->affichage_employe->model()->columnCount();

                out <<  "<html>\n"
                    "<head>\n"
                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    <<  QString("<title>%1</title>\n").arg("strTitle")
                    <<  "</head>\n"
                    "<body bgcolor=#ffffff link=#5000A0>\n"

                    //     "<align='right'> " << datefich << "</align>"
                    "<center><h1 style='color:#732626;'>Liste des employes</h1></br></br><table border=1 cellspacing=0 cellpadding=2 color=#732626>\n";

                // headers

                //les noms des colonnes
                out << "<thead><tr bgcolor=#f0f0f0> <th style='color:#732626;'>Numero</th>";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->affichage_employe->isColumnHidden(column))
                        out << QString("<th style='color:#732626;'>%1</th>").arg(ui->affichage_employe->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";


                //remplir le tableau
                for (int row = 0; row < rowCount; row++)
                {
                    out << "<tr> <td  bkcolor=0>" << row + 1 << "</td>";
                    for (int column = 0; column < columnCount; column++)
                    {
                        if (!ui->affichage_employe->isColumnHidden(column))
                        {
                            QString data = ui->affichage_employe->model()->data(ui->affichage_employe->model()->index(row, column)).toString().simplified();
                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                        }
                    }
                    out << "</tr>\n";
                }
                out <<  "</table> </center>\n"
                    "</body>\n"
                    "</html>\n";

                QString fileName = QFileDialog::getSaveFileName((QWidget * )0, "Sauvegarder en PDF", QString(), "*.pdf");
                if (QFileInfo(fileName).suffix().isEmpty())
                {
                    fileName.append(".pdf");
                }

                QPrinter printer (QPrinter::PrinterResolution);
                printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setPaperSize(QPrinter::A4);

                printer.setOutputFileName(fileName);

                QTextDocument doc ;
                doc.setHtml(strStream);
                doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                doc.print(&printer);
    }




void Dialog::on_lineEdit_8_textChanged(const QString &arg1)
{
  employe emp ;

         ui->affichage_employe->setModel(emp.rechercherafficher(arg1));

}



//stat
void Dialog::on_pushButton_4_clicked()
{
     stat_combo *s = new stat_combo(); //constructeur par defaut creation instance

    s->setWindowTitle("Les Statistiques selon le Genre");
    s->choix_pie(); //la fonction elitesna3 pie
    s->show();


}




void Dialog::onReadyRead()
{
    QByteArray data = socket.readAll();

    ui->textEdit->append(QString::fromStdString(data.toStdString()));
}


void Dialog::onSendButtonPressed()
{
    if(ui->lineEdit_7->text() == "")
           ui->lineEdit_7->setStyleSheet("border: 1px solid red;");
       else{
        ui->lineEdit_7->setStyleSheet("");
        QTime t = t.currentTime();
        QString username;

           //    for(int i=0; i<ui->lineEdit->text().length()-10; i++)
                  // username = ui->lineEdit->text();
    //   QString  text = "[" + QString::number(t.hour()) + ":" + QString::number(t.minute()) + "] " + username + ": " + text;
       QString text = ui->lineEdit_7->text();
       QString time = "[" + QString::number(t.hour()) + ":" + QString::number(t.minute()) + "] : sent by :" + g_some_string + " : " ;
       text = time + text  ;
        ui->lineEdit_7->setText("");
        socket.write(QByteArray::fromStdString(text.toStdString()));


      }
}

void Dialog::on_pushButton_6_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Gestion-Des-Employes"),
                                          QObject::tr(" Déconnection avec succes!\n"
                                                      "Taper sur cancel pour fermer."), QMessageBox::Cancel);
        Dialog::close();
   //  MainWindow   a->show();
}

/*void Dialog::on_pushButton_9_clicked()
{
     A.write_to_arduino("1");
} */

/*void Dialog::on_bouton1_3_clicked()
{
     A.write_to_arduino("2");
}*/


void Dialog::update_label()
{
    data=A.read_from_arduino();

     int result = data.split( ',' )[0].toInt();

    if(result==1)

        ui->label_19->setText("SAFE");

    else if (result==0)

        ui->label_19->setText("DANGER");

}


/*void Dialog::on_bouton1_4_clicked()
{
     A.write_to_arduino("4") ;
}*/

void Dialog::on_pushButton_signal_clicked()
{
    data2.clear() ;

    QSqlQuery q ;
    QString id_salle=ui->comboBox_4->currentText() ;
    q.prepare("select * from salle_evenement ");
        if(q.exec())
           {
               while(q.next())
               {
                   //Remplir tous les champs par les données concernées

       if(q.value(0).toString()==id_salle)
       {
                   ui->lineEdit_9->setText(q.value(6).toString());


       }
       }
       }
          int securite=ui->lineEdit_9->text().toInt();

          if (securite==3)
          {
              ui->label_36->setText("Not safe") ;
          }  else

          {
              ui->label_36->setText("Safe ") ;
          }
          QByteArray data ;
          data.setNum(securite) ;



  if(securite==3)
    A.write_to_arduino("s") ;
}
