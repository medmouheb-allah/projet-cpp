#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QSqlQueryModel>
#include <QVBoxLayout>
#include <QDebug>

class Fournisseur
{
public:
    Fournisseur();
    Fournisseur(QString,QString,QString,QString,QString);
    QString getid();
    QString getnum();
    QString getnom();
    QString getprenom();
    QString getemail();
    void setid(QString);
    void setnum(QString);
    void setnom(QString);
    void setprenom(QString);
    void setemail(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString);
    bool modifier_fournisseur(QString);
      QSqlQueryModel * rechercherID(QString);
      QSqlQueryModel * Trieid();
      QSqlQueryModel * Trienom();
      QSqlQueryModel * TriePrenom();
      QString exporter();

private:
    QString ID_FOURNISSEUR;
     QString NOM;
     QString PRENOM;
     QString EMAIL;
     QString NUMERO;


};
#endif // FOURNISSEUR_H
