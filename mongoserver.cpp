#include "mongoserver.h"

MongoServer::MongoServer(QStringList a_serverSettings) :
    QStandardItem()
{
    setData(a_serverSettings.at(0),Qt::DisplayRole);
    setData(QIcon(":icons/server_connect"),Qt::DecorationRole);
    setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
}
