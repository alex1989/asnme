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

//!  A representation of a MongoDB Server
/*!
  This class is used by the MongoExplorerModel to represent a MongoDB server.
  This class holds the connection to the server as a private member.
*/

class MongoServer : public QStandardItem
{

public:
    //! Standard constructor
    /*!
      This is the standard constructor for this class.
      \param a_serverSettings a QStringList which contains the name, host and port number for the server in 3 strings
    */
    explicit MongoServer(QStringList a_serverSettings);

    //! Return the current connection to the server
    /*!
      \returns a pointer to the server's mongo::DBClientConnection
    */
    mongo::DBClientConnection *get_connection() {return m_connection; }

    //! Connect to the MongoDB Server
    void connect();

    //! Destructor
    /*!
      Destroys the connection to the server
    */
    ~MongoServer() { delete m_connection; }

private:
    mongo::DBClientConnection *m_connection;
    QString m_hostName;

};

#endif // MONGOSERVER_H
