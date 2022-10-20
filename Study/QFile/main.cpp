#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


   QTextStream out{stdout};

   QString name_file="file1.txt";

   QFile file(name_file);

   if(!file.exists()){
       qWarning("File not exists !");
       return 1;
   }

   if(!file.open(QIODevice::ReadOnly) && file.open(QIODevice::WriteOnly)){
       qWarning("Failed open file for reading and Writeing  !");
       return 1;
   }else{
       QTextStream in{&file};

       in<<"Read"
         <<"Blue"
         <<"Green";

    while(!in.atEnd()){ // atEnd() return true if it reached the end file 
        QString read_of_file=in.readLine(); 
        out<<read_of_file;
    }
  }

    QFile::copy(name_file,"myFile.txt"); // for copy file myFile.txt in name_file 

    QFileInfo fileInfo (name_file);

    QString current_name_file=fileInfo.fileName();
    QString base_name=fileInfo.baseName();
    QString suffix=fileInfo.suffix();
    QString absolutePath=fileInfo.absoluteFilePath();

    out<<"Name Current File: "<<current_name_file<<Qt::endl;
    out<<"File Base Name: "<<base_name<<Qt::endl;
    out<<"Suffix file: "<<suffix<<Qt::endl;
    out<<"AbsolutePath: "<<absolutePath<<Qt::endl;


      return a.exec();
}
