#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connections of toolbar's items
    QObject::connect(ui->actionNew_project, &QAction::triggered, this, &MainWindow::createNewProject);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createNewProject()
{
    qDebug() << "Wow ! I can create a new project !";
}
