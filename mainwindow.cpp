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

    //Set the led indicator lights to turn on and off
    ledIndicatorTimer = new QTimer(this);
    connect(ledIndicatorTimer, SIGNAL(timeout()), this, SLOT(led_indicator_lights()));
    led_indicator_counter = 0;
    analyzing_led_indicator_counter = 0;

    //Set up shockable and non-shockable rhythm function
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
            ledIndicatorTimer->start(500);

            ui->display_message->setStyleSheet("font-weight: bold; background-color: transparent;");
            ui->display_message->setText("Stay calm");
        }else{

        }
    }else{
        //Stop all timer
        timer->stop();
        ledIndicatorTimer->stop();
        time_seconds = 0;
        ui->elapsed_time->setText("00:00");

        //Reset shock and led indicator count
        aed.setShockCount(0);
        ui->shock_count->setText("00");
        led_indicator_counter = 0;
        user.setPadsApplied(false);

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

    aed.increaseShockCount();

    QString shockCountString;

    if(aed.getShockCount() <= 9){
        shockCountString = "0" + QString::number(aed.getShockCount());
    }else{
        shockCountString = QString::number(aed.getShockCount());
    }

    ui->shock_count->setText(shockCountString);
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


void MainWindow::on_compression_strength_sliderReleased()
{
    qInfo() << QString::number(ui->compression_strength->value());
}

void MainWindow::led_indicator_lights()
{
    if(led_indicator_counter < 4){
        ui->display_message->setText("CHECK RESPONSIVENESS");
        ui->led_indicator_1->setEnabled(!ui->led_indicator_1->isEnabled());

    }else if(led_indicator_counter < 12){
        ui->display_message->setText("CALL FOR HELP");
        ui->led_indicator_2->setEnabled(!ui->led_indicator_2->isEnabled());

    }else if(user.getPadsApplied() == false){
        ui->display_message->setText("ATTACH ELECTRODE PADS");
        ui->led_indicator_3->setEnabled(!ui->led_indicator_3->isEnabled());

    }else if(user.getPadsApplied() == true && analyzing_led_indicator_counter < 10){
        ui->led_indicator_3->setEnabled(false);
        ui->display_message->setText("DON'T TOUCH PATIENT ANALYZING");
        ui->led_indicator_4->setEnabled(!ui->led_indicator_4->isEnabled());
        analyzing_led_indicator_counter++;

    }else if(patient.getHeartCondition() == "ventricular_fibrillation" || patient.getHeartCondition() == "ventricular_tachycardia"){
        ui->led_indicator_4->setEnabled(false);
        ui->display_message->setText("SHOCK ADVISED");
        ui->led_indicator_6->setEnabled(true);
    }
    led_indicator_counter++;
}

void MainWindow::on_defib_pads_button_released()
{
    user.setPadsApplied(true);
}


void MainWindow::on_VF_button_released()
{
    patient.setHeartCondition("ventricular_fibrillation");
}

void MainWindow::on_VT_button_released()
{
    patient.setHeartCondition("ventricular_tachycardia");
}

void MainWindow::on_PEA_button_released()
{
    patient.setHeartCondition("sinus_rhythm_or_PEA");
}

void MainWindow::on_asystole_button_released()
{
    patient.setHeartCondition("asystole");
}
