#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mScene(new QGraphicsScene)
    , mItem(new TextSceneItem)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(mScene);
    mScene->addItem(mItem);


    connect(ui->enableShadow, &QPushButton::toggled, [this](bool isChecked){
        mItem->setShadowEnabled(isChecked);
    });

    connect(ui->drawBackground, &QPushButton::toggled, [this](bool isChecked){
        mItem->setDrawBackground(isChecked);
    });
}

MainWindow::~MainWindow()
{
    delete mScene;
    delete ui;
}

