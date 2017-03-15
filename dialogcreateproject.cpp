#include "dialogcreateproject.h"
#include "ui_dialogcreateproject.h"

DialogCreateProject::DialogCreateProject(ProjectManager *projectManager, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogCreateProject)
{
    ui->setupUi(this);
    this->projectManager = projectManager;

    // Connections of window's widgets
    QObject::connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &DialogCreateProject::checkInputs);
    QObject::connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &DialogCreateProject::reject);
    QObject::connect(ui->buttonFindLocation, &QPushButton::clicked, this, &DialogCreateProject::findNewLocation);
}

DialogCreateProject::~DialogCreateProject()
{
    delete ui;
}

/**
 * Let the user choose a location for the project
 * @brief DialogCreateProject::findNewLocation
 */
void DialogCreateProject::findNewLocation()
{
    qDebug() << "DialogCreateProject::findNewLocation";

    // Find the root directory of the project
    QString dir = QFileDialog::getExistingDirectory(this
                , tr("Open Directory")
                ,""
                ,QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    // Write the path in the location input
    ui->lineEditLocation->setText(dir);
}

/**
 * Check if the input s are correct before create the project
 * @brief DialogCreateProject::checkInputs
 */
void DialogCreateProject::checkInputs()
{
    qDebug() << "DialogCreateProject::checkInputs";
    bool isValid = true;

    // Check if all inputs are not empty
    if(ui->lineEditName->text() == "" && ui->lineEditLocation->text() == "")
    {
        isValid = false;
    }

    // Check if the path really exist
    if(ui->lineEditLocation->text() != "")
    {
        QDir dir(ui->lineEditLocation->text());
        if (!dir.exists()) {
            dir.mkpath(".");
        }

        // We check if the path exist now, if not then means the path isn't well formatted
        if (!dir.exists()) {
            isValid = false;
        }
    }

    // Check if the inputs are valid
    if(isValid)
    {
        this->projectManager->createNewProject(ui->lineEditName->text(), ui->lineEditLocation->text());
        accept();
    }
}
