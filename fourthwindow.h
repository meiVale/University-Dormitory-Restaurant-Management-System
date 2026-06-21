#ifndef FOURTHWINDOW_H
#define FOURTHWINDOW_H

#include <QDialog>

namespace Ui {
class fourthWindow;
}

class fourthWindow : public QDialog
{
    Q_OBJECT

public:
    explicit fourthWindow(QWidget *parent = nullptr);
    ~fourthWindow();

private slots:
    void on_pushButton_saveMenu_clicked();

private:
    Ui::fourthWindow *ui;
};

#endif // FOURTHWINDOW_H
