#include "mongoserver.h"

MongoServer::MongoServer(QStringList a_serverSettings) :
    QStandardItem()
{
    this->setData(a_serverSettings.at(0),Qt::DisplayRole);
    this->setData(QIcon(":icons/server_connect"),Qt::DecorationRole);
}
