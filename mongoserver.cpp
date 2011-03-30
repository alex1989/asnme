/*
This file is part of asnme.

asnme is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

asnme is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with asnme.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "mongoserver.h"

MongoServer::MongoServer(QStringList a_serverSettings) :
    QStandardItem()
{
    setData(a_serverSettings.at(0),Qt::DisplayRole);
    setData(QIcon(":icons/server_connect"),Qt::DecorationRole);
    setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    m_hostName = a_serverSettings.at(1);
}

void MongoServer::connect()
{
    m_connection = new mongo::DBClientConnection;
    m_connection->connect(m_hostName.toStdString());
    Q_ASSERT(m_connection);
}
