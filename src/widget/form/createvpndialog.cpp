#include "createvpndialog.h"
#include "ui_createvpndialog.h"

CreateVPNDialog::CreateVPNDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateVPNDialog)
{
    ui->setupUi(this);
}

CreateVPNDialog::~CreateVPNDialog()
{
    delete ui;
}
