#include "projectmanager.h"

ProjectManager::ProjectManager(QTreeView* projectView, QWidget *parent) : QObject()
{
    this->projectView = projectView;
    this->parent = parent;
    this->fileManager = new FileManager();
}

void ProjectManager::chooseProject()
{
    qDebug() << "ProjectManager::chooseProject";

    // Find the root directory of the project
    QString projectPath = QFileDialog::getExistingDirectory(this->parent
                , tr("Open project directory")
                , ""
                , QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    // List files inside the folder
    QStringList listFiles = this->fileManager->listFiles(&projectPath);

    for(int i = 0; i < listFiles.length(); i++)
    {
        QString file = QString(listFiles.at(i));
        if(file.contains(".qm"))
        {
            // We find a project file
            QString* content = this->fileManager->readFile(new QString(projectPath + "/" + file));

            // Right now only one argument so we directly take it
            QString projectName = content->split(":")[1];

            // Load the project
            this->loadProject(projectName);
        }
    }
}

/**
 * Create the project from the info of project name and project path
 * @brief ProjectManager::createNewProject
 * @param projectName The name of the project
 * @param projectpath The path of the project
 */
void ProjectManager::createNewProject(QString projectName, QString projectPath)
{
    qDebug() << "ProjectManager::createNewProject";

    // Create the model with the starter resources for the project
    this->loadProject(projectName);

    // Create the project file
    this->fileManager->writeFile(&projectName, &projectPath, new QString("project: " + projectName));
}

/**
 * load the project, create the tree view and find the files
 * @brief ProjectManager::loadProject
 * @param projectName
 */
void ProjectManager::loadProject(QString projectName)
{
    qDebug() << "ProjectManager::loadProject";

    QStandardItemModel* model = new QStandardItemModel();

    QStandardItem* item0 = new QStandardItem(QIcon(":/rec/img/Project-48.png"), projectName);
    QStandardItem* item1 = new QStandardItem(QIcon(":/rec/img/SQL-48.png"), "SQL");
    QStandardItem* item2 = new QStandardItem(QIcon(":/rec/img/Mcd-48.png"), "MCD");

    model->appendRow(item0);
    item0->appendRow(item1);
    item0->appendRow(item2);

    // Set the items on the tree view and hide the header_
    this->projectView->header()->hide();
    this->projectView->setModel(model);

    // Expand the project view
    this->projectView->expand(model->indexFromItem(item0));
}
