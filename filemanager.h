#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QString>
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <QDebug>
#include <QByteArray>

class FileManager
{
public:
    FileManager();

    void writeFile(QString* fileName, QString* filePath, QString* content);
    QStringList listFiles(QString* filePath);
    QString* readFile(QString* fullPath);
};

#endif // FILEMANAGER_H
