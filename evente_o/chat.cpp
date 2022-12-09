/*#include "chat.h"
#include "ui_chat.h"
#include<QTime>
chat::chat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chat)
{
    ui->setupUi(this);
}

chat::~chat()
{
    delete ui;
}

void chat::onReadyRead()
{
    QByteArray data = socket.readAll();

    ui->textEdit->append(QString::fromStdString(data.toStdString()));
}

void chat::on_pushButton_2_pressed()
{
    if(ui->lineEdit_8->text() == "")
          ui->lineEdit_8->setStyleSheet("border: 1px solid red;");
      else{
          ui->lineEdit_8->setStyleSheet("");
          QTime t = t.currentTime();
          QString text = ui->lineEdit_8->text();
          QString username;
          for(int i=0; i<ui->lineEdit_9->text().length()-10; i++)
              username[i] = ui->lineEdit_9->text()[i];
          text = "[" + QString::number(t.hour()) + ":" + QString::number(t.minute()) + "] " + username + ": " + text;
          ui->lineEdit_8->setText("");
          socket.write(QByteArray::fromStdString(text.toStdString()));
     }
}
*/
