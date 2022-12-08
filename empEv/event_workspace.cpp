#include "event_workspace.h"
#include "ui_event_workspace.h"
#include <QMessageBox>
#include "connection.h"

event_workspace::event_workspace(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::event_workspace)
{
    ui->setupUi(this);

    int ret=a.connect_arduino();
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< a.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<a.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(a.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));

   /* connection c;
     c.createconnection();
*/


     ui->emp->setModel(ev.get_id_emp());
     ui->client->setModel(ev.get_id_client());
     ui->salle->setModel(ev.get_salle());


    show_table();

    //maps
    QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                       QCoreApplication::organizationName(), QCoreApplication::applicationName());

    ui->WebBrowser->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place/ESPRIT/@36.9016729,10.1713215,15z");



}

event_workspace::~event_workspace()
{
    delete ui;
}


int event_workspace::code() const{

    return ui->code->value();
}

QString event_workspace::nom() const {

    return ui->nom_2->text();
}

QString event_workspace::description() const {
    return ui->description->toPlainText();
}

QString event_workspace::type() const {

    return ui->type->currentText();
}

QString event_workspace::client() const {
    return ui->client->currentText();
}

QString event_workspace::emp() const {

    return ui->emp->currentText();
}

QString event_workspace::salle() const {

    return ui->salle->currentText();
}

QString event_workspace::get_date() const {
    return ui->dateEdit->date().toString("dd.MM.yyyy");
}

void event_workspace::update_label()
{
      data=a.read_from_arduino();
      if (data == "2")
      {

          QMessageBox::information(nullptr, QObject::tr("OK"),
                      QObject::tr("Une voiture veut sortir.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
ui->ouvrir->setEnabled(true);
ui->tabWidget->setCurrentIndex(2);




      }
    if(ev.count()=="-1"){
        a.write_to_arduino("-1");
    }


    else{





     if (data == "1")
     {


         QMessageBox::information(nullptr, QObject::tr("OK"),
                     QObject::tr("Une voiture veut entrer.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

         ui->ouvrir_2->setEnabled(true);
         ui->tabWidget->setCurrentIndex(2);


     }


 }}


void event_workspace::fill_form(int selected ) {
    QSqlQuery query;
    query.prepare("select * from EVENEMENT where CODE= :code");
    query.bindValue(":code", selected);
    query.exec();
    while(query.next()){
        ui->dateEdit->setDate(QDate::fromString(query.value(4).toString(),"dd.MM.yyyy"));
 ui->description->setText(query.value(2).toString());
  ui->nom_2->setText(query.value(1).toString());
   ui->type->setCurrentText(query.value(3).toString());
   ui->client->setCurrentText(query.value(5).toString());
   ui->emp->setCurrentText(query.value(6).toString());
   ui->salle->setCurrentText(query.value(7).toString());
       ui->code->setValue(selected);
    }
}




void event_workspace::show_table(){

    proxy = new QSortFilterProxyModel();


   proxy->setSourceModel(tmp.afficher());


    proxy->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxy->setFilterKeyColumn(-1);

    ui->tableau->setModel(proxy);

}


void event_workspace::on_tableau_doubleClicked(const QModelIndex &index)
{
    selected=ui->tableau->model()->data(index).toInt();
     fill_form(selected);
}

void event_workspace::on_comboBox_currentIndexChanged(int index)
{
    search_col = ui->comboBox->currentIndex()-1;
    proxy->setFilterKeyColumn(search_col);
}


void event_workspace::on_add_clicked()
{

      int r=code();
      QString s1=nom();
      QString s2=description();
      QString s3=type();
      QString s4=get_date();
      QString s5=client();
      QString s6=emp();
      QString s7=salle();


      evenement mc(r,s1,s2,s3,s4,s5,s6,s7);
      mc.ajouter();




     show_table();
}

void event_workspace::on_update_clicked()
{

    QString s1=nom();
    QString s2=description();
    QString s3=type();
    QString s4=get_date();
    QString s5=client();
    QString s6=emp();
    QString s7=salle();


    evenement mc(selected,s1,s2,s3,s4,s5,s6,s7);
    mc.modifier(selected);




   show_table();
}


void event_workspace::on_delete_2_clicked()
{
    evenement mc;
  mc.supprimer(selected);


   show_table();
}




void event_workspace::on_recherche_textChanged(const QString &arg1)
{
 proxy->setFilterFixedString(arg1);
}


//stat
void event_workspace::on_pushButton_clicked()
{
    s = new stat_combo();

  s->setWindowTitle("statistique par Type");
  s->choix_pie();
  s->show();
}

//pdf
void event_workspace::on_pushButton_2_clicked()
{

    QString strStream;
            QTextStream out(&strStream);

            const int rowCount = ui->tableau->model()->rowCount();
            const int columnCount = ui->tableau->model()->columnCount();

            out <<  "<html>\n"
                "<head>\n"
                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                <<  QString("<title>%1</title>\n").arg("strTitle")
                <<  "</head>\n"
                "<body bgcolor=#ffffff link=#5000A0>\n"

                //     "<align='right'> " << datefich << "</align>"
                "<center><h1 style='color:#732626;'>Liste des clients</h1></br></br><table border=1 cellspacing=0 cellpadding=2 color=#732626>\n";

            // headers

            //les noms des colonnes
            out << "<thead><tr bgcolor=#f0f0f0> <th style='color:#732626;'>Numero</th>";
            for (int column = 0; column < columnCount; column++)
                if (!ui->tableau->isColumnHidden(column))
                    out << QString("<th style='color:#732626;'>%1</th>").arg(ui->tableau->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";



            for (int row = 0; row < rowCount; row++)
            {
                out << "<tr> <td  bkcolor=0>" << row + 1 << "</td>";
                for (int column = 0; column < columnCount; column++)
                {
                    if (!ui->tableau->isColumnHidden(column))
                    {
                        QString data = ui->tableau->model()->data(ui->tableau->model()->index(row, column)).toString().simplified();
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
            doc.setPageSize(printer.pageRect().size());
            doc.print(&printer);
}

//calendrier
void event_workspace::on_calander_clicked()
{
    QProcess *process = new QProcess(this);
    QString file = proj_path+"/calendar/calendar.exe";
    process->start(file);
}

void event_workspace::on_pushButton_3_clicked()
{

}

void event_workspace::on_ouvrir_clicked()
{
    ev.incrParking();
               data2.clear();
               data2.append("5");
                a.write_to_arduino(data2);
                  ui->ouvrir->setDisabled(true);
ui->lcdNumber->display(ev.count());
}

void event_workspace::on_ouvrir_2_clicked()
{
    ev.decrParking();
    data2.clear();
    data2.append("6");
     a.write_to_arduino(data2);
     ui->ouvrir_2->setDisabled(true);
     ui->lcdNumber->display(ev.count());
}

void event_workspace::on_pushButton_6_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Gestion-Des-Employes"),
                                          QObject::tr(" Déconnection avec succes!\n"
                                                      "Taper sur cancel pour fermer."), QMessageBox::Cancel);
        event_workspace::close();
}
