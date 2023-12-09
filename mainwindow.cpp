#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPixmap>
#include <QTimer>
#include <QElapsedTimer>
#include <QString>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Scale the AED image.
    ui->AED->setScaledContents(true);

    //Set the display to be off.
    ui->self_test_succeeded->setVisible(false);
    ui->shock_label->setVisible(false);
    ui->shock_count->setVisible(false);
    ui->elapsed_time->setVisible(false);

    //Set the elapsed timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(elapsed_time()));
    time_seconds = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
    /*
    QMainWindow::resizeEvent(event);
    // Retrieve the new size of the window
    QSize newSize = event->size();

    // Scale the pixmap to the new window size
    QPixmap scaledPix = QPixmap(":/AED_Image.jpg").scaled(newSize, Qt::KeepAspectRatio);

    // Set the scaled pixmap to the QLabel
    ui->AED->setPixmap(scaledPix);
    */
}

void MainWindow::on_power_button_released()
{
    //Power on or off the device.
    if(aed.power() == true){
        if(aed.performSelfTest() == true){
            ui->self_test_succeeded->setVisible(true);
            ui->shock_label->setVisible(true);
            ui->shock_count->setVisible(true);
            ui->display_message->setVisible(true);
            ui->elapsed_time->setVisible(true);

            timer->start(1000);

            ui->display_message->setStyleSheet("font-weight: bold; background-color: transparent;");
            ui->display_message->setText("Stay calm");

            QTimer::singleShot(500, [=]() {
                ui->display_message->setText("CHECK RESPONSIVENESS");
                ui->led_indicator_1->setEnabled(true);
            });

            QTimer::singleShot(1000, [=]() {
                ui->led_indicator_1->setEnabled(false);
            });

            QTimer::singleShot(1500, [=]() {
                ui->led_indicator_1->setEnabled(true);
            });

            QTimer::singleShot(2000, [=]() {
                ui->display_message->setText("CALL FOR HELP");
                ui->led_indicator_1->setEnabled(false);
                ui->led_indicator_2->setEnabled(true);
            });

            QTimer::singleShot(2500, [=]() {
                ui->led_indicator_2->setEnabled(false);
            });

            QTimer::singleShot(3000, [=]() {
                ui->led_indicator_2->setEnabled(true);
            });

            QTimer::singleShot(3500, [=]() {
                ui->led_indicator_2->setEnabled(false);
            });

            QTimer::singleShot(4000, [=]() {
                ui->led_indicator_2->setEnabled(true);
            });


            QTimer::singleShot(4500, [=]() {
                ui->display_message->setText("ATTACH ELECTRODE PADS");
                ui->led_indicator_2->setEnabled(false);
                ui->led_indicator_3->setEnabled(true);
            });

            QTimer::singleShot(5000, [=]() {
                ui->led_indicator_3->setEnabled(false);
            });

            QTimer::singleShot(5500, [=]() {
                ui->led_indicator_3->setEnabled(true);
            });

            QTimer::singleShot(6000, [=]() {
                ui->led_indicator_3->setEnabled(false);
            });

            QTimer::singleShot(6500, [=]() {
                ui->led_indicator_3->setEnabled(true);
            });
        }else{

        }
    }else{
        //Stop all timer
        timer->stop();
        time_seconds = 0;
        ui->elapsed_time->setText("00:00");

        //Turn off display
        ui->shock_label->setVisible(false);
        ui->shock_count->setVisible(false);
        ui->display_message->setVisible(false);
        ui->elapsed_time->setVisible(false);

        ui->self_test_succeeded->setVisible(false);

        //Turn off led indicator lights
        ui->led_indicator_1->setEnabled(false);
        ui->led_indicator_2->setEnabled(false);
        ui->led_indicator_3->setEnabled(false);
        ui->led_indicator_4->setEnabled(false);
        ui->led_indicator_5->setEnabled(false);
    }
}


void MainWindow::on_shock_button_released()
{
    qInfo("Shock Button Pushed");
}

void MainWindow::elapsed_time()
{
    time_seconds++;

    int minutes = time_seconds / 60;
    int seconds = time_seconds % 60;

    QString minutes_string;
    QString seconds_string;

    if(minutes <= 9){
        minutes_string = "0" + QString::number(minutes);
    }else{
        minutes_string = QString::number(minutes);
    }
    if(seconds <= 9){
        seconds_string = "0" + QString::number(seconds);
    }else{
        seconds_string = QString::number(seconds);
    }

    QString current_time = minutes_string + ":" + seconds_string;
    ui->elapsed_time->setText(current_time);
}

