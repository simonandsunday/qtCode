#include "teststyle.h"
#include "ui_teststyle.h"

teststyle::teststyle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::teststyle)
{
    ui->setupUi(this);
}

teststyle::~teststyle()
{
    delete ui;
}
