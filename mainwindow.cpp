#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QSlider>
#include "mygraphicsview.h"
#include <QTransform>
#include <QGraphicsItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene{new QGraphicsScene(this)}
{


    ui->setupUi(this);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setResizeAnchor(QGraphicsView::AnchorUnderMouse);



    connect(ui->scaleSlider, &QSlider::valueChanged, this, [this](int value) {
        double scale = static_cast<double>(value) / 100.0;
        QTransform t;
        t.scale(scale, scale);
        ui->graphicsView->setTransform(t);
    });

    connect(ui->graphicsView, &MyGraphicsView::zoomChanged, this, [this] (double scale) {
        ui->scaleSlider->setValue(static_cast<int>(scale * 100));
    });
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
        scene->clear();
        ui->graphicsView->setPixmap(fileName);
    }
}

void MainWindow::on_actionCrop_triggered() {
    ui->graphicsView->setCropMode(true);
}


void MainWindow::on_actionRotateLeft_triggered() {
    QTransform t{};
    t.rotate(-90);
    ui->graphicsView->setPixmap(ui->graphicsView->getPixmap().transformed(t));

}

void MainWindow::on_actionRotateRight_triggered() {
    QTransform t{};
    t.rotate(90);
    ui->graphicsView->setPixmap(ui->graphicsView->getPixmap().transformed(t));
}

void MainWindow::on_actionFlipHorizontally_triggered() {
    QTransform t{};
    t.scale(-1, 1);
    ui->graphicsView->setPixmap(ui->graphicsView->getPixmap().transformed(t));
}

void MainWindow::on_actionFlipVertically_triggered() {
    QTransform t{};
    t.scale(1, -1);
    ui->graphicsView->setPixmap(ui->graphicsView->getPixmap().transformed(t));
}


