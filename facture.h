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
    Facture(QString,QString,QString ,QString,QString,int);
    void set_description(QString );
    void set_quantite(QString );
    void set_prixunit(QString );
    void set_ID_FOURNISSEUR(QString );
    void set_CODE_EVENNEMENT(int );
    void set_total(QString );
    QString get_description();
    QString get_ID_FOURNISSEUR();
    int get_CODE_EVENNEMENT();
    QString get_quantite();
    QString get_prixunit();
    QString get_total();
    bool ajouter();
    QSqlQueryModel* afficher();
    bool modifier_facture(QString);
    QSqlQueryModel * combo_evenement();
    QSqlQueryModel * combo_fournisseur();
private:
    QString DESCRIPTION;
     QString QUANTITE;
     QString PRIXUNIT;
     QString TOTAL;
    QString ID_FOURNISSEUR;
    int CODE_EVENNEMENT;


};

#endif // FACTURE_H
