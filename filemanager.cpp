#include "filemanager.h"

FileManager::FileManager()
{

}

/**
 * Write a file
 * @brief FileManager::writeFile
 * @param fileName The file's name
 * @param filePath The file's path
 * @param content The content to write in file
 */
void FileManager::writeFile(QString* fileName, QString* filePath, QString* content)
{
    qDebug() << "FileManager::writeFile";

    QDir dir;
    QFile file(*filePath + "/" + *fileName + ".qm");

    if(dir.exists(*filePath))
    {
        qDebug() << "FileManager::writeFile -> Writing of the file "+ *fileName;

        if(file.open(QIODevice::ReadWrite))
        {
            QTextStream out(&file);
            out << *content;
        }
    }
}

/**
 * Read the content of a file
 * @brief FileManager::readFile
 * @param fullPath file's full path
 * @return content of file
 */
QString* FileManager::readFile(QString* fullPath)
{
    qDebug() << "FileManager::readFile";

    QFile file(*fullPath);
    if(file.open(QIODevice::ReadWrite))
    {
        return new QString(file.readAll());
    }

    return new QString("");
}

/**
 * List all files in a folder
 * @brief FileManager::listFiles
 * @param filePath the file's path
 * @return List of file's name inside the folder
 */
QStringList FileManager::listFiles(QString* filePath)
{
    qDebug() << "FileManager::listFiles";

    QDir dir;

    if(dir.exists(*filePath))
    {
        dir.setPath(*filePath);
        return dir.entryList();
    }

    return QStringList();
}
