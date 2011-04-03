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

#include <QCoreApplication>
#include <QSettings>
#include <QStringList>
#include "preferences.h"

Preferences* Preferences::_instance = 0;

Preferences::Preferences(QObject *parent) :
    QObject(parent)
{
    QCoreApplication::setOrganizationName("Jeffrey Jones");
    QCoreApplication::setApplicationName("asnme");
    QSettings settings;
}

Preferences* Preferences::instance()
{
    if (_instance == 0)
        _instance = new Preferences();

    return _instance;
}

void Preferences::addServer(QString a_name, QString a_host, QString a_port)
{
    bool exists = false;
    foreach(QStringList srv, m_servers)
    {
        if(a_host == srv.at(1) && a_port == srv.at(2))
        {
            exists = true;
        }
    }

    if(exists == false)
    {
        QStringList server;
        server.append(a_name);
        server.append(a_host);
        server.append(a_port);
        m_servers.append(server);
        emit serversUpdated();
    }
}

void Preferences::deleteServer(QString a_name)
{
    if(m_servers.size() > 0)
    {
        for(int i= (m_servers.size() - 1) ; i >= 0; i--)
        {
            QStringList server = m_servers.at(i);
            QString server_name = server.at(i);
            if(server_name == a_name)
            {
               m_servers.removeAt(i);
            }
        }
    }
    emit serversUpdated();
}

