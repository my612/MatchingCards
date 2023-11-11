#ifndef LOGIWINDOW_H
#define LOGIWINDOW_H

#include <QDialog>

namespace Ui {
class Logiwindow;
}

class Logiwindow : public QDialog
{
    Q_OBJECT

public:
    explicit Logiwindow(QWidget *parent = nullptr);
    ~Logiwindow();

private:
    Ui::Logiwindow *ui;
};

#endif // LOGIWINDOW_H
