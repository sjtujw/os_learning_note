#include "qtwidgetsapplication1.h"

QtWidgetsApplication1::QtWidgetsApplication1(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.CheckBox,SIGNAL(clicked()),this,SLOT(on_checkBox_clicked()));
    connect(ui.CheckBox_2, SIGNAL(clicked()), this, SLOT(on_checkBox_2_clicked()));
    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));

}

void QtWidgetsApplication1::on_checkBox_clicked()
{
    if (ui.checkBox->isCheckd())
    {
        ui.lineEdit->setReadOnly(true);
    }
}

void QtWidgetsApplication1::on_checkBox_2_clicked()
{
    if (ui.checkBox_2->isChecked())
    {
        ui.lineEdit->setEchoMode(QLineEdit::Password);
    }
    else
    {
		ui.lineEdit->setEchoMode(QLineEdit::Normal);
    }
}

void QtWidgetsApplication1::on_pushButton_clicked()
{
    ui.label->setText(ui.lineEdit->text());
}
