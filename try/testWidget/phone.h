#ifndef PHONE_H
#define PHONE_H

#include <QWidget>

namespace Ui {
class phone;
}

class phone : public QWidget
{
    Q_OBJECT

public:
    explicit phone(QWidget *parent = 0);
    ~phone();

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_0_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_audio_clicked();

    void on_pushButton_video_clicked();

private:
    Ui::phone *ui;
};

#endif // PHONE_H
