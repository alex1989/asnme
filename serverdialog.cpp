#include <QPushButton>
#include <QRegExp>
#include <QRegExpValidator>
#include "serverdialog.h"
#include "ui_serverdialog.h"

ServerDialog::ServerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ServerDialog)
{
    ui->setupUi(this);
    QPushButton *ok = ui->buttonBox->button(QDialogButtonBox::Ok);
    ok->setDisabled(true);
}

ServerDialog::~ServerDialog()
{
    delete ui;
}

QString ServerDialog::get_name()
{
    QString name = this->ui->nameLineEdit->text();
    Q_ASSERT(name.size() > 0);
    return name;
}


QString ServerDialog::get_host()
{
    QString host = this->ui->hostLineEdit->text();
    Q_ASSERT(host > 0);
    return host;
}

QString ServerDialog::get_port()
{
    QString port;
    port.setNum(this->ui->portSpinBox->value());
    Q_ASSERT(port > 0);
    return port;
}

void ServerDialog::checkFields()
{
    if( this->ui->nameLineEdit->text().size() > 0 && this->ui->hostLineEdit->text().size() > 0)
    {
        this->ui->buttonBox->button(QDialogButtonBox::Ok)->setDisabled(false);
    }
    else
    {
        this->ui->buttonBox->button(QDialogButtonBox::Ok)->setDisabled(true);
    }
}

