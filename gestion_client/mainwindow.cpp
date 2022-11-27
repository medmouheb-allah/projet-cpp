#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include<QDebug>
#include "client.h"
#include <iostream>
#include<QIntValidator>
#include<QComboBox>
#include<QPrinter>
#include<QPainter>
#include "date.h"
#include <ctime>
#include<QImage>
#include<QMediaPlayer>
#include <QFileDialog>
#include"smtp.h"


using namespace date;
using namespace std::chrono;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    mMediaPlayer=new QMediaPlayer(this);
    ui->setupUi(this);

    int ret=a.connect_arduino();
        switch (ret) {
        case(0):qDebug()<<"arduino is available and connected to :"<<a.getarduino_port_name();
            break;
        case(1):qDebug()<<"arduino is available but not connected to :"<<a.getarduino_port_name();
            break;
        case(-1):qDebug()<<"arduino is not available";
        }
  QObject::connect(a.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));// yestana fi ma3louma mel arduino

    ui->le_id->setValidator(new QIntValidator(0,9999999,this)) ;
    ui->le_tel->setValidator(new QIntValidator(0,99999999,this)) ;
    ui->le_tab->setModel(c.afficher());
    ui->table->setModel(c.aff());

    ui->listView->setModel(afficherHistorique());
    ui->comboBox->setModel(c.tester());
    ui->comboBox_2->setModel(c.tester());
    //ui->gen->addItem("Femme");
    //ui->gen->addItem("Homme");
    ui->age->addItem("18-25");
    ui->age->addItem("26-33");
    ui->age->addItem("34-41");
    ui->age->addItem(">41");
    ui->genremod->addItem("Femme");
    ui->genremod->addItem("Homme");
    ui->agemod->addItem("18-25");
    ui->agemod->addItem("26-33");
    ui->agemod->addItem("34-41");
    ui->agemod->addItem(">41");
    ui->triii->addItem("ID_CLIENT");
        ui->triii->addItem("NOM");
        ui->triii->addItem("PHONE");
        connect(mMediaPlayer,&QMediaPlayer::positionChanged,[&](qint64 pos)
               {
                    ui->progressBar->setValue(pos);
                });
                connect(mMediaPlayer, &QMediaPlayer::durationChanged,[&](qint64 dur){
                ui->progressBar->setMaximum(dur);
                } );
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::update_label()
{
      data=a.read_from_arduino();
      if (data == "2")
      {

          QMessageBox::information(nullptr, QObject::tr("OK"),
                      QObject::tr("Une voiture veut sortir.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
ui->ouvrir->setEnabled(true);
ui->ajouter_client->setCurrentIndex(7);




      }
    if(c.count()=="-1")
    {
        data3.append("-1");
        a.write_to_arduino(data3);
    }


    else{





     if (data == "1")
     {


         QMessageBox::information(nullptr, QObject::tr("OK"),
                     QObject::tr("Une voiture veut entrer.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

         ui->ouvrir_2->setEnabled(true);
         ui->ajouter_client->setCurrentIndex(7);


     }


 }}




void MainWindow::on_pushButton_2_clicked()
{


    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString e_mail=ui->le_email->text();
    QString tel=ui->le_tel->text();
    QString dest=ui->gen->currentText();
    QString age=ui->age->currentText();
    Client C(id,nom,prenom,e_mail,tel,dest,age);

        //controle saisie nom
        QRegExp nomex("\\b[A-Z]{2,40}\\b");
        nomex.setCaseSensitivity(Qt::CaseInsensitive);
        nomex.setPatternSyntax(QRegExp::RegExp);
        if(nomex.exactMatch(nom))
        {
            //controle saisie email
            QRegExp mailREX("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,4}\\b");
            mailREX.setCaseSensitivity(Qt::CaseInsensitive);
            mailREX.setPatternSyntax(QRegExp::RegExp);
            if(mailREX.exactMatch(e_mail))
            {
                bool test=C.ajouter();
                addToHistory("ajout","d'un client",ui->le_id->text());

                if(test)
                {
                    QMessageBox::information(nullptr, QObject::tr("OK"),
                                QObject::tr("Ajout effectué.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
                }
                else
                {
                    QMessageBox::critical(nullptr, QObject::tr(" not ok"),
                                QObject::tr("Ajout non effectué.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
                }
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr(" not ok"),
                            QObject::tr("Adresse mail erroné.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            }
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr(" not ok"),
                        QObject::tr("Nom invalide.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }






ui->le_tab->setModel(c.afficher());
ui->comboBox->setModel(c.tester());
 ui->comboBox_2->setModel(c.tester());

  ui->listView->setModel(afficherHistorique());

}


void MainWindow::on_bouton_supp_clicked()
{
    Client c;
    c.setid(ui->comboBox->currentText().toInt());
    bool test=c.supprimer(c.getid());
    QMessageBox msgBox;

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("supp effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->le_tab->setModel(c.afficher());
         //ui->comboBox->setModel(c.tester());
          ui->comboBox_2->setModel(c.tester());
          addToHistory("suppression","d'un client ", ui->le_id_supp->text());
          ui->listView->setModel(afficherHistorique());

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr(" not ok"),
                    QObject::tr("supp non effectué.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}


void MainWindow::on_pushButton_clicked()
{
    int id;
    QString nom,prenom,e_mail,tel,dest,age;

    id=ui->le_id_2->text().toInt();
    nom=ui->le_nom_2->text();
    prenom=ui->le_prenom_2->text();
    e_mail=ui->le_email_2->text();
     tel=ui->le_tel_2->text();
      dest=ui->genremod->currentText();
      age=ui->agemod->currentText();
    c.modifier(id,nom,prenom,e_mail,tel,dest,age);
    ui->le_tab->setModel(c.afficher());
    addToHistory("modification","d'un client ",ui->le_id_2->text());
    ui->listView->setModel(afficherHistorique());

}

void MainWindow::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    QString name=ui->comboBox_2->currentText();
    QSqlQuery qry;
    qry.prepare("select *from CLIENT_ where id_client='"+name+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
         ui->le_id_2->setText(qry.value(0).toString());
         ui->le_nom_2->setText(qry.value(1).toString());
          ui->le_prenom_2->setText(qry.value(2).toString());
          ui->le_email_2->setText(qry.value(3).toString());
         ui->le_tel_2->setText(qry.value(4).toString());
          ui->genremod->setCurrentText(qry.value(5).toString());
          ui->agemod->setCurrentText(qry.value(6).toString());
                  //->setText(qry.value(5).toString());
        }
    }





}

void MainWindow::on_pushButton_3_clicked()
{
    statistique *MainWindow=new statistique(this);
                  MainWindow->show();
}




void MainWindow::on_pushButton_4_clicked()
{
    QString strStream;
        QTextStream out(&strStream);

        const int rowCount = ui->le_tab->model()->rowCount();
        const int columnCount = ui->le_tab->model()->columnCount();

        out <<  "<html>\n"
            "<head>\n"
            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
            <<  QString("<title>%1</title>\n").arg("strTitle")
            <<  "</head>\n"
            "<body bgcolor=#ffffff link=#5000A0>\n"

            //     "<align='right'> " << datefich << "</align>"
                "<p align='center'><img src='C:/Users/emna/Desktop/logoooo/logo apppp123.png'></p>"
            "<center><h1 style='color:#732626;'>Liste des clients</h1></br></br><table border=1 cellspacing=0 cellpadding=2 color=#732626>\n";


        // headers

        //les noms des colonnes
        out << "<thead><tr bgcolor=#f0f0f0> <th style='color:#732626;'>Numero</th>";
        for (int column = 0; column < columnCount; column++)
            if (!ui->le_tab->isColumnHidden(column))
                out << QString("<th style='color:#732626;'>%1</th>").arg(ui->le_tab->model()->headerData(column, Qt::Horizontal).toString());
        out << "</tr></thead>\n";


        //remplir le tableau
        for (int row = 0; row < rowCount; row++)
        {
            out << "<tr> <td  bkcolor=0>" << row + 1 << "</td>";
            for (int column = 0; column < columnCount; column++)
            {
                if (!ui->le_tab->isColumnHidden(column))
                {
                    QString data = ui->le_tab->model()->data(ui->le_tab->model()->index(row, column)).toString().simplified();
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

        QTextDocument doc;
        doc.setHtml(strStream);
        doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);
}

void MainWindow::on_pushButton_5_clicked()
{
    PieChartWidget *MainWindow=new PieChartWidget(this);
                  MainWindow->show();
}

void MainWindow::on_triii_currentIndexChanged(const QString &arg1)
{
    QString name=ui->triii->currentText();
         if(name=="ID_CLIENT")
         {
              ui->le_tab->setModel(c.triid());
         }
         else if( name=="PHONE")
         {
                ui->le_tab->setModel(c.triphone());

         }
         else
         {
           ui->le_tab->setModel(c.trinom());
         }
}


void MainWindow::on_rechercher_clicked()
{
    QString search=ui->search->text();
        ui->le_tab->setModel(c.rechercher(search));
        if(search==" ")
        {
             ui->le_tab->setModel(c.afficher());
        }

}
void MainWindow::on_rech_textChanged(const QString &arg1)
{

            if(ui->rech->text() == "")
                {
                    ui->le_tab->setModel(c.afficher());
                }
                else
                {
                     ui->le_tab->setModel(c.rechercher_client(ui->rech->text()));
                }
}
void MainWindow::on_excelll_2_textChanged(const QString &arg1)
{
    if(ui->excelll_2->text() == "")
        {
            ui->table->setModel(c.aff());
        }
        else
        {
             ui->table->setModel(c.rech(ui->excelll_2->text()));
        }
}




void MainWindow::on_excelll_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                        tr("Excel Files (*.xls)"));
        if (fileName.isEmpty())
            return;

        ExportExcelObject obj(fileName, "mydata", ui->table);

        //colums to export
        obj.addField(0, "Identifiant", "char(20)");
        obj.addField(1, "Nom", "char(20)");
        obj.addField(2, "Prenom", "char(20)");
        obj.addField(3, "Adr_email", "char(80)");
        obj.addField(4, "Phone", "char(90)");



        int retVal = obj.export2Excel();
        if( retVal > 0)
        {
            QMessageBox::information(this, tr("Done"),
                                     QString(tr("%1 records exported!")).arg(retVal)
                                     );
        }
}


void MainWindow::addToHistory(QString action, QString type, QString id)
{


    QSqlQuery query,qry;
    QString date=QDateTime::currentDateTime().toString("dddd, dd MMMM yyyy");
    QString date1=QDateTime::currentDateTime().toString("dd-MMM-yy");
    QString time=QDateTime::currentDateTime().toString("hh:mm");
    QString activity;



    activity="\n    "+date1+"   -   "+time+" \t    "+ action +" "+type+" d'identifiant:  "+id+" \n";

          query.prepare("INSERT INTO history (activity, DATE_ACTIVITE_HISTORIQUE) VALUES (:activity, :sysdate)");
          query.bindValue(":activity", activity);
          query.bindValue(":sysdate",date1);

    query.exec();

    activity="\n\t\t\t\t"+date+"\n";

}
QSqlQueryModel* MainWindow::afficherHistorique()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    QString historyType="";
    switch (ui->deleteee->currentIndex())
    {
    case 1:  historyType="ajout";break;
    case 2:  historyType="suppression";break;
    case 3:  historyType="modification";break;
    }
    //qDebug() << "test";
         query.prepare("SELECT activity FROM history where activity like '%"+historyType+"%'  order by date_activite_historique desc");
         query.exec();
         model->setQuery(query);
    return model;
}


bool MainWindow::historyDelete()
{
    QSqlQuery query;
    int periode;

    switch (ui->history->currentIndex())
    {
    case 0: periode=(1)*(-1); break;
    case 1: periode=(7)*(-1); break;
    case 2: periode=-28; break;
    case 3: periode=-999999; break;
    }
    //qDebug()<< periode;
    QDateTime lastdate=QDateTime::currentDateTime().addDays(periode);
    //qDebug()<< lastdate;


    query.prepare("Delete from history where date_activite_historique > :lastdate ");
    query.bindValue(":lastdate",lastdate);
    //qDebug() << delete_id;

    return query.exec();
}



void MainWindow::on_history_activated(const QString &arg1)
{
     ui->listView->setModel(afficherHistorique());
}


void MainWindow::on_del_clicked()
{
    bool test=historyDelete();
        if(test){
            QMessageBox::information(this,"Success","suppression terminée");
            ui->listView->setModel(afficherHistorique());
        }
        else{
            QMessageBox::information(this,"Success","suppression non effectuée");
        }
}

void MainWindow::on_deleteee_activated(const QString &arg1)
{
    ui->listView->setModel(afficherHistorique());
}

void MainWindow::on_listView_indexesMoved(const QModelIndexList &indexes)
{

}






void MainWindow::on_son_clicked()
{
    QString filename= QFileDialog::getOpenFileName(this,"music");
       if (filename.isEmpty())//si le fichier existe
       {return;}
       mMediaPlayer->setMedia(QUrl::fromLocalFile(filename));//chercher la chonson
       mMediaPlayer->setVolume(ui->horizontalSlider->value());//Volume selon slide
       on_start_clicked();//la musique commence
}

void MainWindow::on_start_clicked()
{
mMediaPlayer->play();
}


void MainWindow::on_stop_clicked()
{
    mMediaPlayer->stop();
}


void MainWindow::on_mute_clicked()
{
    if(ui->mute->text() == "Mute")
    {
            mMediaPlayer->setMuted(true);
            ui->mute->setText("Unmute");
    }
        else
        { mMediaPlayer->setMuted(false);
            ui->mute->setText("Mute");
    }
}


void MainWindow::on_horizontalSlider_valueChanged(int valeur)
{
    mMediaPlayer->setVolume(valeur);
}

void MainWindow::on_message_clicked()
{
    Smtp* smtp = new Smtp("emna.ghariani@esprit.tn","emna1003", "smtp.gmail.com");
        //connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


            smtp->sendMail("emna.ghariani@esprit.tn", "emna.ghariani@esprit.tn" , ui->msg->text()," ");
}



void MainWindow::on_ouvrir_clicked() //sortie
{
    c.incrParking();
                   data2.clear();
                   data2.append("5");
                    a.write_to_arduino(data2);
                      ui->ouvrir->setDisabled(true);
    ui->lcdNumber->display(c.count());
}

void MainWindow::on_ouvrir_2_clicked()
{
    c.decrParking();
        data2.clear();
        data2.append("6");
         a.write_to_arduino(data2);
         ui->ouvrir_2->setDisabled(true);
         ui->lcdNumber->display(c.count());

}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString name=ui->comboBox->currentText();
    QSqlQuery qry;
    qry.prepare("select  ID_CLIENT from CLIENT_ where id_client='"+name+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
         ui->le_id_supp->setText(qry.value(0).toString());

        }
    }


}
