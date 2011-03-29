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

#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QObject>
#include <QStringList>

//!  Application preferences storage
/*!
  This is a singleton class used to store application settings.
  It uses QSettings under the hood to store app settings and persists Mongo related information.
*/

class Preferences : public QObject
{
    Q_OBJECT
public:
    //! Standard constructor
    /*!
      This is the standard constructor for this class
      \param parent The parent of this object
    */
    Preferences(QObject *parent = 0);

    //! Return the instance of this singleton class
    /*!
      \returns Preferences singleton instance
    */
    static Preferences* instance();

    //! Add a server to the saved MongoDB servers
    /*!
      \param a_name The user defined name for the server
      \param a_host The host string as an IP address or FQDN
      \param a_port The port that the server is listening on
    */
    void addServer(QString a_name, QString a_host, QString a_port);

    //! Delete a server from the saved MongoDB servers
    /*!
      \param a_name The user defined name for the server
    */
    void deleteServer(QString a_name);

    //! Return all saved MongoDB server information
    /*!
      Return all the saved MongoDB server information in a stringlist
      \returns A list of of QStringLists, each one containing the name, host and port of the server
    */
    QList<QStringList> servers() { return m_servers; }

signals:
    //! This signal is emitted whenever the list of servers has been edited.
    /*!
      It is mainly received by the MongoExplorerModel::updateTree() slot to update
      the model information to fall in line with the information stored here
    */
    void serversUpdated();

private:
    static Preferences* _instance;
    QList<QStringList> m_servers;
};

#endif // PREFERENCES_H
