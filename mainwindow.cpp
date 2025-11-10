#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , currentValue(0)
{
    ui->setupUi(this);
    
    // Connect button signals to slots
    connect(ui->incrementButton, &QPushButton::clicked, this, &MainWindow::onIncrementClicked);
    connect(ui->decrementButton, &QPushButton::clicked, this, &MainWindow::onDecrementClicked);
    
    // Set initial LCD value
    ui->lcdNumber->display(currentValue);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onIncrementClicked()
{
    if (currentValue < 10) {
        currentValue++;
        ui->lcdNumber->display(currentValue);
    }
}

void MainWindow::onDecrementClicked()
{
    if (currentValue > -10) {
        currentValue--;
        ui->lcdNumber->display(currentValue);
    }
}
