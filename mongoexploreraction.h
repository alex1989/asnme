#ifndef MONGOEXPLORERACTION_H
#define MONGOEXPLORERACTION_H

#include <QAction>

class MongoExplorerAction : public QAction
{
    Q_OBJECT
public:
    explicit MongoExplorerAction(QString text, int row, QObject *parent = 0);

signals:
    void triggered_with_row(int row);

public slots:
    void trigger_with_row();

private:
    int m_row;
};

#endif // MONGOEXPLORERACTION_H
