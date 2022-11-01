#ifndef INTERFACE_H
#define INTERFACE_H
#include "fournisseur.h"
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

private:
    Ui::Interface *ui;
    Fournisseur F;
};

#endif // INTERFACE_H
