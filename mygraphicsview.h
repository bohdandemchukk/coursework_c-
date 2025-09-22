#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsView>

class MyGraphicsView: public QGraphicsView {
    Q_OBJECT
public:
    explicit MyGraphicsView(QWidget *parent = nullptr)
        : QGraphicsView(parent) {}

signals:
    void zoomChanged(double scale);

protected:
    void wheelEvent(QWheelEvent *event) override {
        if (event->angleDelta().y() > 0) {
            scale(1.1, 1.1);
        } else {
            scale(0.9, 0.9);
        }

        emit zoomChanged(transform().m11());
    }


};

#endif // MYGRAPHICSVIEW_H
