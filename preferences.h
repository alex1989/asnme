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

class Preferences : public QObject
{
    Q_OBJECT
public:
    Preferences(QObject *parent = 0);
    static Preferences* instance();

    void addServer(QString a_name, QString a_host, QString a_port);
    void deleteServer(QString a_name);
    QList<QStringList> servers() { return m_servers; }

signals:
    void serversUpdated();

private:
    static Preferences* _instance;
    QList<QStringList> m_servers;
};

#endif // PREFERENCES_H
