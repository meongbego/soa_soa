#include "daftarminuman.h"
#include "ui_daftarminuman.h"

DaftarMinuman::DaftarMinuman(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DaftarMinuman)
{
    ui->setupUi(this);
}

DaftarMinuman::~DaftarMinuman()
{
    delete ui;
}

void DaftarMinuman::isiFaktur()
{
    b = this->ui->spinBox->text();
    emit panggilFaktur(a,b);
}

void DaftarMinuman::on_listWidget_currentRowChanged(int currentRow)
{
    if (currentRow == 0){
        a="Air ES";
    }
    else if (currentRow == 1){
        a="Es Jeruk";
    }
    else if(currentRow==2){
        a="KOPI";
    }
}

void DaftarMinuman::on_pushButton_2_clicked()
{
    b="";
    a="";
    this->close();
    emit panggilFaktur(a,b);
}

void DaftarMinuman::on_pushButton_clicked()
{
    isiFaktur();
    this->close();
}
