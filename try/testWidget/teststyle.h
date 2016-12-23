#ifndef TESTSTYLE_H
#define TESTSTYLE_H

#include <QWidget>

namespace Ui {
class teststyle;
}

class teststyle : public QWidget
{
    Q_OBJECT

public:
    explicit teststyle(QWidget *parent = 0);
    ~teststyle();

private:
    Ui::teststyle *ui;
};

#endif // TESTSTYLE_H
