#ifndef TESTTOOLBOX_H
#define TESTTOOLBOX_H

#include <QWidget>

namespace Ui {
class testToolBox;
}

class testToolBox : public QWidget
{
    Q_OBJECT

public:
    explicit testToolBox(QWidget *parent = 0);
    ~testToolBox();

private:
    Ui::testToolBox *ui;
};

#endif // TESTTOOLBOX_H
