#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "AbstractView.h"
#include "GUIView.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_reservationButton_clicked();

    void on_cancellationButton_clicked();

    void on_firstRadio_clicked();

    void on_economyRadio_clicked();



    void on_flightInquiry_clicked();

    void on_refreshButton_clicked();

    void on_passengerInquiry_clicked();

private:
    Ui::MainWindow *ui;
    AbstractView* m_view;
};

#endif // MAINWINDOW_H





