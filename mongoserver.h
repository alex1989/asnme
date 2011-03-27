#ifndef MONGOSERVER_H
#define MONGOSERVER_H

#include <QStandardItem>
#include "mongo/client/dbclient.h"

class MongoServer : public QStandardItem
{

public:
    explicit MongoServer(QStringList a_serverSettings);
    ~MongoServer() { delete m_connection; }

signals:

public slots:

private:
    mongo::DBClientConnection *m_connection;

};

#endif // MONGOSERVER_H
