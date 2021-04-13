#include <QCoreApplication>
#include "register.h"
#include "mediumBusiness.h"
#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //QString name;
    //QList<QString> owners;
    //double profit;
    //double area;
    //int employees;
    QString name = "FFFF";
    QList<QString> owners =  {"Пирожков А.Е", "Марташев А.К"};;


    Register r = Register::GetInstance();
    r.addCompany(new MediumBusiness(name, owners, 4444,55, 653));

    cout<< r.getSize();

   return a.exec();
   }
