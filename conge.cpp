#include "conge.h"

conge::conge(){}

bool conge::ajouter(){
    QSqlQuery query;
        query.prepare("INSERT INTO CONGE (ID, NOMEMPLOYE, DATED, DATEF, TYPE) VALUES (:ID, :NOMEMPLOYE, :DATED, :DATEF,:TYPE)");
        query.bindValue(":ID", id);
        query.bindValue(":NOMEMPLOYE", nom);
        query.bindValue(":DATED", dated);
        query.bindValue(":DATEF", datef);
        query.bindValue(":TYPE", type);
        return query.exec();

}
bool conge::supprimer(QString idconge){
    QSqlQuery qry;
        qry.prepare("Delete from CONGE where ID = :ID");
        qry.bindValue(":ID",idconge);
        return qry.exec();

}
QSqlQueryModel *conge::afficher(){
    QSqlQueryModel *model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM CONGE");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("NOMEMPLOYE"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("DATED"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATEF"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("TYPE"));
        return model;
}


void conge::setid(QString n){id=n;}
void conge::setnom(QString n){nom=n;}
void conge::setdated(QString n){dated=n;}
void conge::setdatef(QString n){datef=n;}
void conge::settype(QString n){type=n;}


QString conge::get_id(){return id;}
QString conge::get_nom(){return nom;}
QString conge::get_dated(){return dated;}
QString conge::get_datef(){return datef;}
QString conge::get_type(){return type;}


QSqlQueryModel *conge::recherche(QString num)
{

    QSqlQueryModel *model= new QSqlQueryModel;
    model->setQuery("SELECT * FROM CONGE WHERE ID LIKE'"+num+"%'");
    return model;
}

QSqlQueryModel * conge::rechercher_type(QString TYPE)
{
    QSqlQuery qry;
    qry.prepare("SELECT * FROM CONGE WHERE TYPE = :TYPE");
    qry.bindValue(":TYPE",TYPE);
    qry.exec();

    QSqlQueryModel *model= new QSqlQueryModel;
    model->setQuery(qry);


    return model;
}

QSqlQueryModel *conge::rechercher_nomemploye(QString NOMEMPLOYE)
{

    QSqlQueryModel *model= new QSqlQueryModel;
    model->setQuery("SELECT * FROM CONGE WHERE NOMEMPLOYE LIKE'"+NOMEMPLOYE+"%'");

    return model;
}

QSqlQueryModel * conge::rechercher_combinaison_all(QString ID,QString NOMEMPLOYE,QString TYPE)
{
    QSqlQuery *qry=new QSqlQuery();
    qry->prepare("SELECT * FROM CONGE WHERE ID=:ID and NOMEPLOYE=:NOMEMPLOYE and TYPE=:TYPE");
    qry->bindValue(":ID",ID);
    qry->bindValue(":NOMEMPLOYE",NOMEMPLOYE);
    qry->bindValue(":TYPE",TYPE);
    qry->exec();

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(*qry);
    return model;
}

QSqlQueryModel * conge::rechercher_combinaison_id_nom(QString ID, QString NOMEMPLOYE)
{
    QSqlQuery *qry=new QSqlQuery();
    qry->prepare("SELECT * FROM CONGE WHERE ID=:ID and NOMEMPLOYE=:NOMEMPLOYE");
    qry->bindValue(":ID",ID);
    qry->bindValue(":NOMEMPLOYE",NOMEMPLOYE);
    qry->exec();

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(*qry);
    return model;
}

QSqlQueryModel * conge::rechercher_combinaison_id_type(QString ID, QString TYPE)
{
    QSqlQuery *qry=new QSqlQuery();
    qry->prepare("SELECT * FROM CONGE WHERE ID=:ID and TYPE=:TYPE");
    qry->bindValue(":ID",ID);
    qry->bindValue(":TYPE",TYPE);
    qry->exec();

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(*qry);
    return model;
}

QSqlQueryModel * conge::rechercher_combinaison_nom_type(QString NOMEMPLOYE, QString TYPE)
{
    QSqlQuery *qry=new QSqlQuery();
    qry->prepare("SELECT * FROM CONGE WHERE NOMEMPLOYE=:NOMEMPLOYE and TYPE=:TYPE");
    qry->bindValue(":NOMEMPLOYE",NOMEMPLOYE);
    qry->bindValue(":TYPE",TYPE);
    qry->exec();

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(*qry);
    return model;
}
QSqlQueryModel * conge::chercher_emp(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from conge where ((id ) LIKE '%"+aux+"%')");
    model->setHeaderData(0,Qt::Vertical,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Vertical,QObject::tr("nomemploye"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("DATED"));
    model->setHeaderData(4,Qt::Vertical,QObject::tr("DATEF"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("TYPE"));

    return model;
}




QSqlQueryModel * conge::chercher_emp2(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from conge where ((nomemploye ) LIKE '%"+aux+"%')");
    model->setHeaderData(0,Qt::Vertical,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Vertical,QObject::tr("NOMEMPLOYE"));
    model->setHeaderData(3,Qt::Vertical,QObject::tr("DATED"));
    model->setHeaderData(4,Qt::Vertical,QObject::tr("DATEF"));
    model->setHeaderData(2,Qt::Vertical,QObject::tr("TYPE"));

    return model;
}

int conge::stati1()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from CONGE where type='CONGE PAYE'") ;
    while(requete.next())
    {
            count++ ;
    }
return(count);
}

int conge::stati2()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from CONGE where type='CONGE ANNUEL'") ;
    while(requete.next())
    {
            count++ ;
    }

return(count);
}

int conge::stati3()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from CONGE where type= 'CONGE MALADIE'") ;
    while(requete.next())
    {
            count++ ;
    }

return(count);
}
int conge::stati4()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from CONGE where type= 'CONGE MATERNITE'") ;
    while(requete.next())
    {
            count++ ;
    }

return(count);
}

int conge::nb_total()
{
    QSqlQuery query;
    int count=0 ;
    QSqlQuery requete("select * from  CONGE") ;
    while(requete.next())

    {
            count++ ;
    }

return(count);
}


void conge::exporter(QTableView *table)
{

    QString filters("CSV files (*.csv);;All files (*.*)");
    QString defaultFilter("CSV files (*.csv)");
    QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                                    filters, &defaultFilter);
    QFile file(fileName);
    QAbstractItemModel *model =  table->model();
    if (file.open(QFile::WriteOnly | QFile::Truncate))
    {
        QTextStream data(&file);
        QStringList strList;
        for (int i = 0; i < model->columnCount(); i++)
        {
            if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
            else
                strList.append("");
        }
        data << strList.join(";") << "\n";
        for (int i = 0; i < model->rowCount(); i++)
        {
            strList.clear();
            for (int j = 0; j < model->columnCount(); j++)
            {

                if (model->data(model->index(i, j)).toString().length() > 0)
                    strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                else
                    strList.append("");
            }
            data << strList.join(";") + "\n";
        }
        file.close();
    }
}
