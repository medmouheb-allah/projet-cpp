#ifndef INTERFACE_H
#define INTERFACE_H
#include "fournisseur.h"
#include "facture.h"
#include "arduino.h"
#include <QDialog>
#include <QSerialPort>
namespace Ui {
class Interface;
}

class Interface : public QDialog
{
    Q_OBJECT

public:
    explicit Interface(QWidget *parent = nullptr);
    ~Interface();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_recherche_textChanged(const QString &arg1);

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_5_clicked();

    void on_sendBtn_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_clicked();
    void update_label();// slot permettant la mise à jour du label état de la lampe 1,
    // ce slot est lancé à chaque réception d'un message de Arduino

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_refreshButton_clicked();

    void on_offButton_clicked();

private:
    Ui::Interface *ui;
    Fournisseur F;
    Facture A ;
    QByteArray data;

    arduino C; // objet temporaire
};

#endif // INTERFACE_H
