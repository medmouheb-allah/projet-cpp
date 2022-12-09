#include "salle_workspace.h"
#include "ui_salle_workspace.h"
#include <iostream>
#include <string>



salle_workspace::salle_workspace(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::salle_workspace)
{
    ui->setupUi(this);
    ///////////////////////////////////////////////////
    ui->id_supprimer->setValidator(new QIntValidator(0,9999999,this)) ;
    ui->id_modifier->setValidator(new QIntValidator(0,9999999,this)) ;
    ui->id_ajouter->setValidator(new QIntValidator(0,9999999,this)) ;

    ui->comboBox_modifier->setModel(S.tester());
    ui->comboBox_supprimer->setModel(S.tester());
    //////////////////////////////////////////////////

}



salle_workspace::~salle_workspace()
{
    delete ui;
}


void salle_workspace::on_pushButton_ajouter_clicked()
{
    int num_salle;
    int capacite;
    QString localisation, style;
    QMessageBox messageBox;
    QPixmap img;

    num_salle=ui->id_ajouter->text().toInt();
    capacite=ui->capacite_ajouter->text().toInt();
    localisation=ui->localisation_ajouter->text();
    style=ui->style_ajouter->text();
    img=this->ui->salle_graphicsView->grab();


    Salle s(num_salle, capacite, localisation, style, img);
    bool test=s.ajouter();
    if (test)
    {
        messageBox.information(nullptr, messageBox.tr("Succès"), messageBox.tr("Ajout effectué"));
    }
     else
        messageBox.critical(nullptr, messageBox.tr("Echec"), messageBox.tr("Ajout non effectué"));

    ui->id_ajouter->clear();
    ui->capacite_ajouter->clear();
    ui->localisation_ajouter->clear();
    ui->style_ajouter->clear();

   ui->tableView_ajouter->setModel(Stmp.afficher());
   ui->tableView_modifier->setModel(Stmp.afficher());
   ui->tableView_supprimer->setModel(Stmp.afficher());

   ui->comboBox_modifier->setModel(S.tester());
   ui->comboBox_supprimer->setModel(S.tester());

}



void salle_workspace::on_comboBox_modifier_currentIndexChanged(const QString &arg1)
{
    QString test=ui->comboBox_modifier->currentText();
    QSqlQuery qry;
    qry.prepare("select * from SALLE_EVENEMENT where num_salle ='"+test+"' ");
    if(qry.exec())
    {
        while(qry.next())
        {
         ui->id_modifier->setText(qry.value(0).toString() );
        // ui->capacite_modifier->setText(qry.value(3).toString());
         ui->style_modifier->setText(qry.value(2).toString());
         ui->localisation_modifier->setText(qry.value(3).toString());

        //Afficher image
        image::showImage(ui->salle_graphicsView_2, qry.value(4).toByteArray() );
         //génération QR Code
         std::string infoQRCode ="num salle = "+ qry.value(0).toString().toStdString()
                     + "\nstyle = "+ qry.value(2).toString().toStdString()
                     + "\ncapacité = "+ qry.value(1).toString().toStdString()
                     + "\nlocalisation = "+ qry.value(3).toString().toStdString();

          //Afficher QR Code
          qrcodegen::showQRCode(ui->qr_graphicsView, infoQRCode);


        }
    }

}



void salle_workspace::on_modifier_clicked()
{
    int num_salle;
    int capacite;
    QString localisation, style;
    QMessageBox messageBox;
    QPixmap img;

    num_salle=ui->id_modifier->text().toInt();
    capacite=ui->capacite_modifier->text().toInt();
    localisation=ui->localisation_modifier->text();
    style=ui->style_modifier->text(); 
    img=this->ui->salle_graphicsView_2->grab();


    Salle s(num_salle, capacite, localisation, style, img);

    bool test=s.modifier();
    if (test)
    {
        messageBox.information(nullptr, messageBox.tr("Succès"), messageBox.tr("modification effectuée"));
    }
     else
        messageBox.critical(nullptr, messageBox.tr("Echec"), messageBox.tr("modification non effectuée"));

    ui->id_modifier->clear();
    ui->capacite_modifier->clear();
    ui->localisation_modifier->clear();
    ui->style_modifier->clear();

    ui->tableView_ajouter->setModel(Stmp.afficher());
    ui->tableView_modifier->setModel(Stmp.afficher());
    ui->tableView_supprimer->setModel(Stmp.afficher());

}

void salle_workspace::on_supprimer_clicked()
{
    int num_salle;
    QMessageBox messageBox;

    num_salle=ui->id_supprimer->text().toInt();
    bool test=Stmp.supprimer(num_salle);

    if (test)
    {
        messageBox.information(nullptr, messageBox.tr("Succès"), messageBox.tr("Suppression effectuée"));
    }
     else
        messageBox.critical(nullptr, messageBox.tr("Echec"), messageBox.tr("Suppression non effectuée"));

    ui->id_supprimer->clear();

    ui->tableView_ajouter->setModel(Stmp.afficher());
    ui->tableView_modifier->setModel(Stmp.afficher());
    ui->tableView_supprimer->setModel(Stmp.afficher());

    ui->comboBox_modifier->setModel(S.tester());
    ui->comboBox_supprimer->setModel(S.tester());

}


void salle_workspace::on_qr_code_clicked()
{
  std::string infoQRCode;
  QGraphicsScene *scene = new QGraphicsScene();
  //génération QR Code
  infoQRCode="Daoud ben jebara";
  scene=qrcodegen::genQRCode(infoQRCode);
  //Affichage QR Code
  ui->qr_graphicsView->setScene(scene);
  ui->qr_graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
  ui->qr_graphicsView->show();

}


void salle_workspace::on_trier_clicked()
{
    QString type_tri = "num";
    QString test_ordre ="croissant" ;

    type_tri = ui->comboBox_type_trier->currentText();
    test_ordre = ui->comboBox_ordre->currentText() ;

        if ((type_tri == "num") && (test_ordre == "croissant") )

        ui->tableView_consulter->setModel(S.tricroissant_num_salle());

        else if ((type_tri == "style" ) && (test_ordre == "croissant") )
        ui->tableView_consulter->setModel(S.tricroissant_style());

        else if ((type_tri == "capacite" ) && (test_ordre == "croissant") )
        ui->tableView_consulter->setModel(S.tricroissant_capacite());

        else if ((type_tri == "localisation" ) && (test_ordre == "croissant") )
        ui->tableView_consulter->setModel(S.tricroissant_localisation());

////////////////////////////////////////////////////////////////////////////////////////////

        if ((type_tri == "num") && (test_ordre == "decroissant") )
        ui->tableView_consulter->setModel(S.tridecroissant_num_salle());

        else if ((type_tri == "style" ) && (test_ordre == "decroissant") )
        ui->tableView_consulter->setModel(S.tridecroissant_style());

        else if ((type_tri == "capacite" ) && (test_ordre == "decroissant") )
        ui->tableView_consulter->setModel(S.tridecroissant_capacite());

        else if ((type_tri == "localisation" ) && (test_ordre == "decroissant") )
        ui->tableView_consulter->setModel(S.tridecroissant_localisation());

}




void salle_workspace::on_reset_clicked()
{
    Salle S1;

            bool test=S1.supprimerTout();

            QMessageBox msgBox;

            if(test)
               { msgBox.setText("reset  avec succes.");
                ui->tableView_consulter->setModel(S1.afficher());
                ui->tableView_ajouter->setModel(S1.afficher());
                ui->tableView_modifier->setModel(S1.afficher());
                ui->tableView_supprimer->setModel(S1.afficher());

               }
            else
                msgBox.setText("Echec du reset.!!!");


            msgBox.exec();

            ui->comboBox_modifier->setModel(S.tester());
            ui->comboBox_supprimer->setModel(S.tester());

}


void salle_workspace::on_rechercher_bouton_clicked()
{
    QString type_recherche = ui->comboBox_type_rechercher->currentText();
    QString recherche=ui->rechercher->text();

    if (type_recherche =="num")
    ui->tableView_consulter->setModel(S.recherchernumsalle(recherche) ) ;
    else if (type_recherche =="capacite")
    ui->tableView_consulter->setModel(S.recherchercapacite(recherche) ) ;
    else if (type_recherche =="style")
    ui->tableView_consulter->setModel(S.rechercherstyle(recherche) ) ;
    else if (type_recherche =="localisation")
    ui->tableView_consulter->setModel(S.rechercherlocalisation(recherche) ) ;


}

/////////////////////////////////////////////////////



static inline QString picturesLocation()
{
    return QStandardPaths::standardLocations(QStandardPaths::PicturesLocation).value(0, QDir::currentPath());
}


void salle_workspace::on_load_ajouter_clicked()
{
    //to do
    QString m_currentPath;
    //récupérer file name
    QFileDialog fileDialog(this);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setMimeTypeFilters(QStringList() << "image/png"); //<< "image/png"
    fileDialog.setWindowTitle(tr("Open PNG File"));
    if (m_currentPath.isEmpty())
        fileDialog.setDirectory(picturesLocation());

  while (fileDialog.exec() != QDialog::Accepted )
        ;

    m_currentPath=fileDialog.selectedFiles().constFirst() ; //charger image

    QGraphicsScene * scene=new QGraphicsScene(QRect(10, 10, 680, 520));


    QGraphicsItem * image=new QGraphicsPixmapItem(QPixmap(m_currentPath));
    scene ->addItem(image);

    ui->salle_graphicsView->setScene(scene);
    ui->salle_graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    ui->salle_graphicsView->show();


}



void salle_workspace::on_load_modifier_clicked()
{
    //to do
    QString m_currentPath;
    //récupérer file name
    QFileDialog fileDialog(this);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setMimeTypeFilters(QStringList() << "image/png");
    fileDialog.setWindowTitle(tr("Open PNG File"));

    if (m_currentPath.isEmpty())
        fileDialog.setDirectory(picturesLocation());

  while (fileDialog.exec() != QDialog::Accepted )
        ;

    m_currentPath=fileDialog.selectedFiles().constFirst() ; //charger image

    QGraphicsScene * scene=new QGraphicsScene(QRect(10, 10, 680, 520));


    QGraphicsItem * image=new QGraphicsPixmapItem(QPixmap(m_currentPath));
    scene ->addItem(image);

    ui->salle_graphicsView_2->setScene(scene);
    ui->salle_graphicsView_2->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    ui->salle_graphicsView_2->show();
}

void salle_workspace::on_consulter_clicked()
{
    QString num_salle= ui->id_consulter->text() ;

    QSqlQuery qry;
    qry.prepare("select * from SALLE_EVENEMENT where num_salle = :num_salle") ;
    qry.bindValue(":num_salle", num_salle);

    if (!qry.exec())
        cout << "erreur";
        qry.next();
         ui->num_consulter->setText(qry.value(0).toString() );
         ui->style_consulter->setText(qry.value(2).toString());
         ui->capacite_consulter->setText(qry.value(1).toString());
         ui->localisation_consulter->setText(qry.value(3).toString());


         //afficher image
         image::showImage(ui->graphicsView_image_consulter, qry.value(4).toByteArray() );


        //générer QR Code
        std::string infoQRCode ="num salle = "+ qry.value(0).toString().toStdString()
                    + "\nstyle = "+ qry.value(2).toString().toStdString()
                    + "\ncapacité = "+ qry.value(1).toString().toStdString()
                    + "\nlocalisation = "+ qry.value(3).toString().toStdString();

         //afficher QR Code
         qrcodegen::showQRCode(ui->qr_graphicsView_consulter, infoQRCode);


}

void salle_workspace::on_statistique_clicked()
{
    statistique_salle stat ;
    stat.exec();
}

void salle_workspace::on_PDF_clicked()
{
    QString strStream;
                  QTextStream out(&strStream);
                  const int rowCount = ui->tableView_consulter->model()->rowCount();
                  const int columnCount =ui->tableView_consulter->model()->columnCount();


                  out <<  "<html>\n"
                          "<head>\n"
                          "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                          <<  QString("<title>%1</title>\n").arg("eleve")
                          <<  "</head>\n"
                          "<body bgcolor=#CFC4E1 link=#5000A0>\n"
                              "<h1>Liste des Salles :</h1>"

                              "<table border=1 cellspacing=0 cellpadding=2>\n";

                  // headers
                      out << "<thead><tr bgcolor=#f0f0f0>";
                      for (int column = 0; column < columnCount; column++)
                          if (!ui->tableView_consulter->isColumnHidden(column))
                              out << QString("<th>%1</th>").arg(ui->tableView_consulter->model()->headerData(column, Qt::Horizontal).toString());
                      out << "</tr></thead>\n";
                      // data table
                         for (int row = 0; row < rowCount; row++) {
                             out << "<tr>";
                             for (int column = 0; column < columnCount; column++) {
                                 if (!ui->tableView_consulter->isColumnHidden(column)) {
                                     QString data = ui->tableView_consulter->model()->data(ui->tableView_consulter->model()->index(row, column)).toString().simplified();
                                     out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                 }
                             }
                             out << "</tr>\n";
                         }
                         out <<  "</table>\n"
                             "</body>\n"
                             "</html>\n";



          QTextDocument *document = new QTextDocument();
          document->setHtml(strStream);


          //QTextDocument document;
          //document.setHtml(html);
          QPrinter printer(QPrinter::PrinterResolution);
          printer.setOutputFormat(QPrinter::PdfFormat);
          printer.setOutputFileName("D:\pdf_projet_achraf.pdf");
          document->print(&printer);

          cout<<"Done !\n"<<endl;
}

void salle_workspace::on_comboBox_supprimer_currentIndexChanged(const QString &arg1)
{
    QString test=ui->comboBox_supprimer->currentText();
    QSqlQuery qry;
    qry.prepare("select * from SALLE_EVENEMENT where num_salle ='"+test+"' ");
    if(qry.exec())
    {
        while(qry.next())
        {
         ui->id_supprimer->setText(qry.value(0).toString() );
        }
    }

}

//////////////////////////arduino////////////////////////////////////////


void salle_workspace::on_Regulateur_temp_clicked()
{
    Regulateur_temperature_salle Reg ;
    Reg.exec();
}

void salle_workspace::on_pushButton_6_clicked()
{
    close();
}
