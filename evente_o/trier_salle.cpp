#include "salle.h"


QSqlQueryModel * Salle::tricroissant_num_salle()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select num_salle, capacite, localisation, style from SALLE_EVENEMENT ORDER BY num_salle ASC");

    return model;

}


QSqlQueryModel * Salle::tricroissant_capacite()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select num_salle, capacite, localisation, style from SALLE_EVENEMENT ORDER BY capacite ASC");

    return model;
}

QSqlQueryModel * Salle::tricroissant_style()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select num_salle, capacite, localisation, style from SALLE_EVENEMENT ORDER BY style ASC");


    return model;
}

QSqlQueryModel * Salle::tricroissant_localisation()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select num_salle, capacite, localisation, style from SALLE_EVENEMENT ORDER BY localisation ASC ");

    return model;
}




QSqlQueryModel * Salle::tridecroissant_num_salle()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select num_salle, capacite, localisation, style from SALLE_EVENEMENT ORDER BY num_salle DESC");

    return model;

}


QSqlQueryModel * Salle::tridecroissant_capacite()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select num_salle, capacite, localisation, style from SALLE_EVENEMENT ORDER BY capacite DESC");

    return model;
}

QSqlQueryModel * Salle::tridecroissant_style()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select num_salle, capacite, localisation, style from SALLE_EVENEMENT ORDER BY style DESC");

    return model;
}

QSqlQueryModel * Salle::tridecroissant_localisation()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select num_salle, capacite, localisation, style from SALLE_EVENEMENT ORDER BY localisation DESC");

    return model;
}
