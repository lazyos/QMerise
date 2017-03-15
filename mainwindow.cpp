#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create managers
    this->projectManager = new ProjectManager(this->ui->projectView, this);

    // Connections of toolbar's items
    QObject::connect(ui->actionNew_project, &QAction::triggered, this, &MainWindow::openNewProjectDialog);
    QObject::connect(ui->actionOpen_project, &QAction::triggered, this->projectManager, &ProjectManager::chooseProject);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * Open the project dialog to create a new project
 * @brief MainWindow::openNewProjectDialog
 */
void MainWindow::openNewProjectDialog()
{
    qDebug() << "MainWindow::openNewProjectDialog";

    DialogCreateProject *dialogCreateProject = new DialogCreateProject(this->projectManager, this);
    dialogCreateProject->setModal(true);
    dialogCreateProject->exec();
}
