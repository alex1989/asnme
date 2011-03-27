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
    QStringList server;
    server.append(a_name);
    server.append(a_host);
    server.append(a_port);
    m_servers.append(server);
    emit serversUpdated();
}

