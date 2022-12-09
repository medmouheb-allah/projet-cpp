#ifndef FOURNISSEUR_WORKSPACE_H
#define FOURNISSEUR_WORKSPACE_H
#include "fournisseur.h"
#include "facture.h"
#include "arduino_fournisseur.h"
#include <QDialog>
#include <QSerialPort>
namespace Ui {
class fournisseur_workspace;
}

class fournisseur_workspace : public QDialog
{
    Q_OBJECT

public:
    explicit fournisseur_workspace(QWidget *parent = nullptr);
    ~fournisseur_workspace();

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

    void on_pushButton_6_clicked();

private:
    Ui::fournisseur_workspace *ui;
    Fournisseur F;
    Facture A ;
    QByteArray data;

    arduino_fournissseur C; // objet temporaire
};

#endif // FOURNISSEUR_WORKSPACE_H
