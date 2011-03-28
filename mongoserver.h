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

#ifndef MONGOSERVER_H
#define MONGOSERVER_H

#include <QStandardItem>
#include "mongo/client/dbclient.h"

class MongoServer : public QStandardItem
{

public:
    explicit MongoServer(QStringList a_serverSettings);
    ~MongoServer() { delete m_connection; }

private:
    mongo::DBClientConnection *m_connection;

};

#endif // MONGOSERVER_H
