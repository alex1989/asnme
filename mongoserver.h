#ifndef MONGOSERVER_H
#define MONGOSERVER_H

#include <QStandardItem>
#include "mongo/client/dbclient.h"

class MongoServer : public QStandardItem
{

public:
    explicit MongoServer(QStringList a_serverSettings);

signals:

public slots:

private:
    mongo::DBClientConnection *m_connection;

};

#endif // MONGOSERVER_H
