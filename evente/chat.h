/*#ifndef CHAT_H
#define CHAT_H

#include <QDialog>
//#include"server/mainwindow.h"
namespace Ui {
class chat;
}

class chat : public QDialog
{
    Q_OBJECT

public:
    explicit chat(QWidget *parent = nullptr);
    ~chat();
void onReadyRead() ;
private slots:
    void on_pushButton_2_pressed();

private:
    Ui::chat *ui;
};

#endif // CHAT_H*/
