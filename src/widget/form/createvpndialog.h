#ifndef CREATEVPNDIALOG_H
#define CREATEVPNDIALOG_H

#include <QDialog>
#include "ui_createvpndialog.h"

namespace Ui {
class CreateVPNDialog;
}

class CreateVPNDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateVPNDialog(QWidget *parent = 0);
    ~CreateVPNDialog();
    QString getSubnetString() const { return ui->subnetLineEdit->text(); }
private:
    Ui::CreateVPNDialog *ui;
};

#endif // CREATEVPNDIALOG_H
