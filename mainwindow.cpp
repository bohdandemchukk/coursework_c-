#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered() {
    QString fileName { QFileDialog::getOpenFileName(
        this,
        "Open Image",
        "",
            "Images (*.png *.jpg *.jpeg *.webp *.bmp)")};

    if (!fileName.isEmpty()) {
        QPixmap pixmap (fileName);
        if (!pixmap.isNull()) {
            ui->imageLabel->setPixmap(pixmap);
        }
    }
}



