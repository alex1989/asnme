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
