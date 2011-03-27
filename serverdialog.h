#ifndef SERVERDIALOG_H
#define SERVERDIALOG_H

#include <QDialog>

namespace Ui {
    class ServerDialog;
}

class ServerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ServerDialog(QWidget *parent = 0);
    ~ServerDialog();
    QString get_name();
    QString get_host();
    QString get_port();

private:
    Ui::ServerDialog *ui;
};

#endif // SERVERDIALOG_H
