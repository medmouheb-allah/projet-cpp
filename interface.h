#ifndef INTERFACE_H
#define INTERFACE_H
#include "fournisseur.h"
#include "facture.h"
#include <QDialog>
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



private:
    Ui::Interface *ui;
    Fournisseur F;
    Facture A;

};

#endif // INTERFACE_H
