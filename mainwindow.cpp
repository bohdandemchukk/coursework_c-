#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene{new QGraphicsScene(this)}
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);

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
            scene->clear();
            scene->addPixmap(pixmap);
            scene->setSceneRect(pixmap.rect());
        }
    }
}



