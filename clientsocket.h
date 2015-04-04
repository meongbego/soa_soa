#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <QWidget>
#include <QTcpSocket>
#include "dialogmakanan.h"
#include "daftarminuman.h"

namespace Ui {
class ClientSocket;
}

class ClientSocket : public QWidget
{
    Q_OBJECT

public:
    explicit ClientSocket(QWidget *parent = 0);
    ~ClientSocket();

signals:


private slots:
    void on_pushButton_3_clicked();
    void isiFaktur(QString a, QString b);
    void isiFakturMinuman(QString a, QString b);
    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ClientSocket *ui;
    QString pesanan,jumlah,jumlahminuman,pesananminuman;
    DialogMakanan *dialMakanan;
    DaftarMinuman *dialMinuman;
    QTcpSocket *socket;
    void kirimData();
};

#endif // CLIENTSOCKET_H
