#ifndef DAFTARMINUMAN_H
#define DAFTARMINUMAN_H

#include <QWidget>

namespace Ui {
class DaftarMinuman;
}

class DaftarMinuman : public QWidget
{
    Q_OBJECT

public:
    explicit DaftarMinuman(QWidget *parent = 0);
    ~DaftarMinuman();

signals:
    void panggilFaktur(QString a,QString b);
public:
    void isiFaktur();
private slots:
    void on_listWidget_currentRowChanged(int currentRow);
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::DaftarMinuman *ui;
    QString a,b;
};

#endif // DAFTARMINUMAN_H
