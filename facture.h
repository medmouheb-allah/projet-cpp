#ifndef FACTURE_H
#define FACTURE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QVBoxLayout>
#include <QDebug>
class Facture
{
public:
    Facture();
    Facture(QString,QString,QString ,QString);
    void set_description(QString );
    void set_quantite(QString );
    void set_prixunit(QString );
    void set_total(QString );
    QString get_description();
    QString get_quantite();
    QString get_prixunit();
    QString get_total();
    bool ajouter();
    QSqlQueryModel* afficher();
    bool modifier_facture(QString);

private:
    QString DESCRIPTION;
     QString QUANTITE;
     QString PRIXUNIT;
     QString TOTAL;



};

#endif // FACTURE_H
