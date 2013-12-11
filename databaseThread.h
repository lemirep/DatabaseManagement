#ifndef DATABASETHREAD_H
#define DATABASETHREAD_H

#include <QThread>
#include "manageBDD.h"
#include "DatabaseServiceUserInterface.h"

#define SERVICE_ID 2
#define SERVICE_VERSION "1.0.0"

class DatabaseThread : public QThread
{
    Q_OBJECT

public:
    DatabaseThread();
    ~DatabaseThread();
    void        run();
    Q_INVOKABLE void        stop();

    int         getServiceId() const;
    void        initLibraryConnection(QObject *parent);
    bool        connectServiceToUser(QObject *user);
    bool        disconnectServiceFromUser(QObject *user);
    QString     getServiceVersion() const;
    QObject*    getLibraryQObject();

private slots:
    void        transmitSQLResult(QList<QSqlRecord> result, QPointer<QObject> receiver, int, QPointer<QObject> data);
signals:
    void        executeSQLQuery(const QString& query, QPointer<QObject> sender, int, const QString &, QPointer<QObject>);
    void        threadInitialized();
};

#endif // DATABASETHREAD_H
