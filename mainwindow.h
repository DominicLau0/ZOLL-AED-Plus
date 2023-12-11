#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QResizeEvent>
#include "AEDSimulator.h"
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent* event) override;

private slots:
    void on_power_button_released();
    void on_shock_button_released();
    void elapsed_time();
    void led_indicator_lights();

    void on_compression_strength_sliderReleased();

    void on_defib_pads_button_released();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    AEDSimulator aed;
    int time_seconds;

    int led_indicator_count;
    QTimer *ledIndicatorTimer;
};
#endif // MAINWINDOW_H
