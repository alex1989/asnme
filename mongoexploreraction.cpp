#include "mongoexploreraction.h"

MongoExplorerAction::MongoExplorerAction(QString text, int a_row, QObject *parent) :
    QAction(text, parent)
{
    m_row = a_row;
    connect(this, SIGNAL(triggered()),
            this,SLOT(trigger_with_row()));
}

void MongoExplorerAction::trigger_with_row()
{
    emit this->triggered_with_row(m_row);
}
