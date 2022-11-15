#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "connexion.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Connexion c;
     c.createconnect();


     evenement ev;
     ui->emp->setModel(ev.get_id_emp());
     ui->client->setModel(ev.get_id_client());
     ui->salle->setModel(ev.get_salle());


    show_table();

    //maps
    QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                       QCoreApplication::organizationName(), QCoreApplication::applicationName());

    ui->WebBrowser->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place/ESPRIT/@36.9016729,10.1713215,15z");



}

MainWindow::~MainWindow()
{
    delete ui;
}




int MainWindow::code() const{

    return ui->code->value();
}

QString MainWindow::nom() const {

    return ui->nom_2->text();
}

QString MainWindow::description() const {
    return ui->description->toPlainText();
}

QString MainWindow::type() const {

    return ui->type->currentText();
}

QString MainWindow::client() const {
    return ui->client->currentText();
}

QString MainWindow::emp() const {

    return ui->emp->currentText();
}

QString MainWindow::salle() const {

    return ui->salle->currentText();
}

QString MainWindow::get_date() const {
    return ui->dateEdit->date().toString("dd.MM.yyyy");
}



void MainWindow::fill_form(int selected ) {
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




void MainWindow::show_table(){

    proxy = new QSortFilterProxyModel();


   proxy->setSourceModel(tmp.afficher());


    proxy->setFilterCaseSensitivity(Qt::CaseInsensitive);
    proxy->setFilterKeyColumn(-1);

    ui->tableau->setModel(proxy);

}


void MainWindow::on_tableau_doubleClicked(const QModelIndex &index)
{
    selected=ui->tableau->model()->data(index).toInt();
     fill_form(selected);
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    search_col = ui->comboBox->currentIndex()-1;
    proxy->setFilterKeyColumn(search_col);
}


void MainWindow::on_add_clicked()
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

void MainWindow::on_update_clicked()
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


void MainWindow::on_delete_2_clicked()
{
    evenement mc;
  mc.supprimer(selected);


   show_table();
}




void MainWindow::on_recherche_textChanged(const QString &arg1)
{
 proxy->setFilterFixedString(arg1);
}


//stat
void MainWindow::on_pushButton_clicked()
{
    s = new stat_combo();

  s->setWindowTitle("statistique par Type");
  s->choix_pie();
  s->show();
}

//pdf
void MainWindow::on_pushButton_2_clicked()
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
void MainWindow::on_calander_clicked()
{
    QProcess *process = new QProcess(this);
    QString file = proj_path+"/calendar/calendar.exe";
    process->start(file);
}
