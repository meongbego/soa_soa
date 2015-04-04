#include "dialogmakanan.h"
#include "ui_dialogmakanan.h"

DialogMakanan::DialogMakanan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DialogMakanan)
{
    ui->setupUi(this);
}

DialogMakanan::~DialogMakanan()
{
    delete ui;
}

void DialogMakanan::isiFaktur()
{
    b = this->ui->spinBox->text();
    emit panggilFaktur(a,b);
}

void DialogMakanan::on_pushButton_clicked()
{
    isiFaktur();
    this->close();
}

void DialogMakanan::on_listWidget_currentRowChanged(int currentRow)
{
    if (currentRow == 0){
       a = "Nasi Goreng Ayam";
    }
    else if (currentRow == 1){
       a = "Nasi Goreng Biji";
    }
}


void DialogMakanan::on_pushButton_2_clicked()
{
    b="";
    a="";
    this->close();
    emit panggilFaktur(a,b);
}
