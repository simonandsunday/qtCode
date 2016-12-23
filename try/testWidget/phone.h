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


    void on_toolButton_1_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_3_clicked();

    void on_toolButton_4_clicked();

    void on_toolButton_5_clicked();

    void on_toolButton_6_clicked();

    void on_toolButton_7_clicked();

    void on_toolButton_8_clicked();

    void on_toolButton_9_clicked();

    void on_toolButton_0_clicked();

    void on_toolButton_10_clicked();

    void on_toolButton_12_clicked();

    void on_toolButton_audio_clicked();

    void on_toolButton_video_clicked();

    void on_toolButton_clicked();

private:
    Ui::phone *ui;
};

#endif // PHONE_H
