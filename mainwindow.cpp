#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), m_scene(new QGraphicsScene(this)),
      m_view(new QGraphicsView(m_scene, this)), m_trainSpeed(2.0) {
    ui->setupUi(this);
    setCentralWidget(m_view);
    setFixedSize(600, 200);

    // set sence
    m_scene->setSceneRect(0, 0, 600, 200);

    // add a line
    QGraphicsLineItem* track = m_scene->addLine(50, 100, 550, 100, QPen(Qt::black, 2));

    // add train
    m_train = new Train(50, 90, 20, 20);
    m_scene->addItem(m_train);

    // add timeer
    connect(&m_timer, &QTimer::timeout, this, &MainWindow::moveTrain);
    m_timer.start(30); // 每30ms更新一次
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::moveTrain() {
    // 每次移动 m_trainSpeed 像素
    m_train->moveBy(m_trainSpeed, 0);

    // 如果到终点就回到起点
    if (m_train->x() > 530) { // 550-20
        m_train->setX(50);
    }
}
