#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "train/train.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

private slots:
    void moveTrain();

private:
    QGraphicsScene* m_scene;
    QGraphicsView* m_view;
    Train* m_train;

    QTimer m_timer;
    qreal m_trainSpeed; // 每帧移动多少像素

private:
    Ui::MainWindow* ui;
};
#endif // MAINWINDOW_H
