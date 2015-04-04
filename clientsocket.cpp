#include "clientsocket.h"
#include "ui_clientsocket.h"
#include <QDebug>
ClientSocket::ClientSocket(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientSocket)
{
    ui->setupUi(this);
    dialMakanan = new DialogMakanan;
    dialMinuman = new DaftarMinuman;
    socket = new QTcpSocket;

    connect(dialMakanan, SIGNAL(panggilFaktur(QString,QString)), this, SLOT(isiFaktur(QString,QString)));
    connect(dialMinuman, SIGNAL(panggilFaktur(QString,QString)), this, SLOT(isiFakturMinuman(QString,QString)));

}

ClientSocket::~ClientSocket()
{
    delete ui;
}

void ClientSocket::on_pushButton_3_clicked()
{
    dialMakanan->show();
}

void ClientSocket::isiFaktur(QString a, QString b)
{
    jumlah =b;
    pesanan =a;
    this->ui->fakturMakanan->setText("<body style=\" font-family:'Sans Serif'; font-size:10pt; font-weight:400; font style:normal;\"><p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600;\">Daftar Pemesanan Anda</span></p></body></html>");
    this->ui->fakturMakanan->append("Nama Makanan : "+a);
    this->ui->fakturMakanan->append("Jumlah Pesanan : "+b);
}

void ClientSocket::isiFakturMinuman(QString a, QString b)
{
    jumlahminuman =b;
    pesananminuman =a;
    this->ui->textEdit_2->setText("<body style=\" font-family:'Sans Serif'; font-size:10pt; font-weight:400; font style:normal;\"><p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:600;\">Daftar Pemesanan Anda</span></p></body></html>");
    this->ui->textEdit_2->append("Nama Minuman : "+a);
    this->ui->textEdit_2->append("Jumlah Pesanan : "+b);
}

void ClientSocket::on_pushButton_4_clicked()
{
    dialMinuman->show();
}

void ClientSocket::on_pushButton_2_clicked()
{
    kirimData();
}

void ClientSocket::kirimData()
{
     socket->connectToHost("127.0.0.1",1234);
    if(socket->waitForConnected(3000)) {
        socket->write(jumlah.toLatin1());
        socket->write("\n");
        socket->write(pesanan.toLatin1());
        socket->write("\n");
        socket->write(jumlahminuman.toLatin1());
        socket->write("\n");
        socket->write(pesananminuman.toLatin1());
        socket->waitForBytesWritten(1000);
        socket->waitForReadyRead(3000);
        socket->bytesAvailable();
        socket->close();
    }
    else{
        QMessageBox::warning(0, "Peringatan","Pemesanan Anda Tidak Terkirim");
    }
}
