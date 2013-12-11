#ifndef MANAGEBDD_H
#define MANAGEBDD_H

#include <QPointer>
#include <QStandardPaths>
#include <QCoreApplication>
#include <QObject>
#include <QString>
#include <QVariant>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QList>
#include <QFile>
#include <QtSql>

class ManageBDD : public QObject
{
    Q_OBJECT
public:
    ManageBDD();
    ~ManageBDD();

    bool    openDatabase(const QString& dbName);
signals:
    void    resultFromSQLQuery(QList<QSqlRecord>, QPointer<QObject> receiver, int id, QPointer<QObject> data);
public slots:
    void    executeSQLQuery(const QString& Query, QPointer<QObject> sender, int id, const QString &dbName, QPointer<QObject> data);
private :
    QString         localDBName;
    QString         previousDbName;
    QString         field;
    QString         username;
    QSqlDatabase    *dataBase;
    QList<QString>  fieldName ;
    QList<QString>  value;
    QString         applicationPath;
    QString         databasePath;
    QHash<QString, QString> nameToPathHash;

    void    copyDatabaseToWritableDirectory(const QString& dbName);
};

#endif // MANAGEBDD_H
