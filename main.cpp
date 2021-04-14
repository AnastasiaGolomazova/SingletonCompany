#include <QCoreApplication>
#include "register.h"
#include "mediumBusiness.h"
#include "smallBusiness.h"
#include "bigBusiness.h"
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
    QString name1 = "FFFM";
    QString name2 = "FVVVF";
    QString name3 = "LFF";
    QList<QString> owners =  {"Пирожков А.Е", "Марташев А.К"};



    Register Tester = Register::GetInstance();
    Tester.addCompany(new MediumBusiness(name, owners, 4444,55, 653));
    cout<< "Size (add 1 company)" << endl;
    cout<< Tester.getSize()<< endl;
    SmallBusiness* mmm = new SmallBusiness(name1, owners, 44,55, 653);
    SmallBusiness* mn = new SmallBusiness(name2, owners, 44,55, 653);
    BigBusiness* mt = new BigBusiness(name3, owners, 44,55, 653);
    Tester.addCompany(mmm);
    Tester.addCompany(mn);
    Tester.addCompany(mt);
    cout<< "Size (add 3 company)"<< endl;
    cout<< Tester.getSize()<< endl;
    cout<< "_______________________"<< endl;
    cout<< "delete 1 company"<< endl;
    Tester.delCompany(name1);
    if(!Tester.doesCompanyExist(name1)){
        cout<<"name1 doesn't exist"<<endl;
    }else{
        cout<<"name1 exists"<<endl;
    }
    cout<< "_______________________"<< endl;
    cout<< "delete 1 company"<< endl;
    Tester.delCompany(mn);
    if(!Tester.doesCompanyExist(name2)){
        cout<<"name1 doesn't exist"<<endl;
    }else{
        cout<<"name1 exists"<<endl;
    }
    cout<<"Size (del 2 company)"<<endl;
    cout<< Tester.getSize()<< endl;

   return a.exec();
   }
