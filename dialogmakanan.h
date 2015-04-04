#ifndef DIALOGMAKANAN_H
#define DIALOGMAKANAN_H

#include <QWidget>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QDebug>

namespace Ui {
class DialogMakanan;
}

class DialogMakanan : public QWidget
{
    Q_OBJECT

public:
    explicit DialogMakanan(QWidget *parent = 0);
    ~DialogMakanan();

private slots:
    void on_pushButton_clicked();

    void on_listWidget_currentRowChanged(int currentRow);

    void on_pushButton_2_clicked();

signals:
    void panggilFaktur(QString a, QString b);
public:
    void isiFaktur();
private:
    Ui::DialogMakanan *ui;
    QString a,b;
};

#endif // DIALOGMAKANAN_H
