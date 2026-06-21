#ifndef THIRDWINDOW_H
#define THIRDWINDOW_H

#include <QDialog>
#include <QListWidgetItem>
#include <QMessageBox>

namespace Ui {
class thirdWindow;
}

class thirdWindow : public QDialog
{
    Q_OBJECT

public:
    explicit thirdWindow(QWidget *parent = nullptr);
    ~thirdWindow();

private slots:

    void on_pushButton_add_clicked();

    void on_pushButton_remove_clicked();

    void on_pushButton_display_clicked();

    void on_pushButton_find_clicked();

private:
    Ui::thirdWindow *ui;
};

#endif // THIRDWINDOW_H
