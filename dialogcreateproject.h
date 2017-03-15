#ifndef DIALOGCREATEPROJECT_H
#define DIALOGCREATEPROJECT_H

#include <QDialog>
#include <QDebug>
#include <projectmanager.h>
#include <QFileDialog>
#include <QStringList>

namespace Ui {
class DialogCreateProject;
}

class DialogCreateProject : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCreateProject(ProjectManager *projectManager, QWidget *parent = 0);
    ~DialogCreateProject();

public slots:
    void checkInputs();
    void findNewLocation();

private:
    Ui::DialogCreateProject *ui;
    ProjectManager *projectManager;
};

#endif // DIALOGCREATEPROJECT_H
