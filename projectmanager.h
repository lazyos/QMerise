#ifndef PROJECTMANAGER_H
#define PROJECTMANAGER_H

#include <QStandardItemModel>
#include <QTreeView>
#include <QDebug>
#include <QHeaderView>
#include <QObject>
#include <QString>
#include <QWidget>
#include <filemanager.h>
#include <QStringList>

class ProjectManager: public QObject
{

public:
    ProjectManager(QTreeView* projectView, QWidget *parent = 0);

    void createNewProject(QString projectName, QString projectpath);

public slots:
    void chooseProject();

private:
    void loadProject(QString projectName);

private:
    QTreeView* projectView;
    QWidget* parent;

    FileManager* fileManager;
};

#endif // PROJECTMANAGER_H
