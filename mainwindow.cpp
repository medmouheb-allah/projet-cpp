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


     ui->tableau->setModel(evenement().afficher());
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
 ui->description->setText(query.value(2).toString());
  ui->nom_2->setText(query.value(1).toString());
   ui->type->setCurrentText(query.value(3).toString());
    ui->dateEdit->setDate(QDate::fromString(query.value(4).toString(),"dd.MM.yyyy"));
   ui->client->setCurrentText(query.value(5).toString());
   ui->emp->setCurrentText(query.value(6).toString());
   ui->salle->setCurrentText(query.value(7).toString());
       ui->code->setValue(selected);
    }
}



void MainWindow::on_tableau_doubleClicked(const QModelIndex &index)
{
     selected=ui->tableau->model()->data(index).toInt();
     fill_form(selected);
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




      ui->tableau->setModel(evenement().afficher());
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

    //mofication
    evenement mc(selected,s1,s2,s3,s4,s5,s6,s7);
    mc.modifier(selected);




    ui->tableau->setModel(evenement().afficher());
}


void MainWindow::on_delete_2_clicked()
{
    evenement mc;
  mc.supprimer(selected);


  ui->tableau->setModel(evenement().afficher());
}


















void MainWindow::on_comboBox_currentIndexChanged(int index)
{}
void MainWindow::on_recherche_textChanged(const QString &arg1)
{}
void MainWindow::on_pushButton_clicked()
{}
void MainWindow::on_pushButton_2_clicked()
{}


