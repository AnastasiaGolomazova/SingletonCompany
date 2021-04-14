#include <QCoreApplication>
#include "register.h"
#include "mediumBusiness.h"
#include "smallBusiness.h"
#include "bigBusiness.h"
#include <iostream>
using namespace std;


void printCompanyByType(TypeOfCompany type){
    cout << "-----------_PRINT COMPANY BY TYPE---------------" << endl;
    Register* Tester = Register::GetInstance();
    QList<AbstractCompany*> companies = Tester->getCompanies();
    for(QList<AbstractCompany*>::iterator i = companies.begin(); i != companies.end(); i++){
        if((*i)->getTypeOfCompany() == type){
            cout << *i << endl;

        }
    }
}

void printCompanyByOwner(QString owner){
    cout << "-----------_PRINT COMPANY BY OWNER---------------" << endl;
    Register* Tester = Register::GetInstance();
    QList<AbstractCompany*> companies = Tester->getCompanies();
    for(QList<AbstractCompany*>::iterator i = companies.begin(); i != companies.end(); i++){
        if((*i)->getOwners().contains(owner)){
            cout << *i << endl;
        }
    }
}

void printAverageByType(){
    cout << "-----------_PRINT AVERAGE BY TYPE---------------" << endl;
    Register* Tester = Register::GetInstance();
    QList<AbstractCompany*> companies = Tester->getCompanies();


    for ( int i = Small_Business; i <= Big_Business; i++ )
    {
       TypeOfCompany type = static_cast<TypeOfCompany>(i);
       QList<AbstractCompany*> listByType;

       for(QList<AbstractCompany*>::iterator i = companies.begin(); i != companies.end(); i++){
           if((*i)->getTypeOfCompany() == type){
               listByType.push_back(*i);
           }
       }

       double avgProfit = 0;
       double avgArea = 0;
       int avgEmployees = 0;

       for(QList<AbstractCompany*>::iterator i = listByType.begin(); i != listByType.end(); i++){
           avgProfit += (*i)->getProfit();
           avgArea += (*i)->getArea();
           avgEmployees += (*i)->getEmployees();
       }


       cout << AbstractCompany::getCompanyTypeString(type) << " average statistics" << endl;
       cout << "Profit: " << avgProfit/listByType.count() << endl;
       cout << "Area: " << avgArea/listByType.count() << endl;
       cout << "Employees: " << avgEmployees/listByType.count() << endl;
       cout << "Count of companies: " << listByType.count() << endl;
       cout << "---------------------------" << endl;


    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString name = "FFFF";
    QString name1 = "FFFM";
    QString name2 = "FVVVF";
    QString name3 = "LFF";
    QList<QString> owners =  {"NNNNNNN", "MMMMMM"};
    QList<QString> owners1 =  {"NNfg", "MMfgd"};
    QList<QString> owners2 =  {"NNfg", "MMMMMM"};



    Register* Tester = Register::GetInstance();
    Tester->addCompany(new MediumBusiness(name, owners, 4444,55, 653));
    cout<< "Size (add 1 company)" << endl;
    cout<< Tester->getSize()<< endl;
    SmallBusiness* mmm = new SmallBusiness(name1, owners, 44,55, 653);
    SmallBusiness* mn = new SmallBusiness(name2, owners1, 44,55, 653);
    BigBusiness* mt = new BigBusiness(name3, owners2, 44,55, 653);
    Tester->addCompany(mmm);
    Tester->addCompany(mn);
    Tester->addCompany(mt);
    cout<< "Size (add 3 company)"<< endl;
    cout<< Tester->getSize()<< endl;
    cout<< "_______________________"<< endl;
    cout<< "delete 1 company"<< endl;
    //Tester->delCompany(name1);
    if(!Tester->doesCompanyExist(name1)){
        cout<<"name1 doesn't exist"<<endl;
    }else{
        cout<<"name1 exists"<<endl;
    }
    cout<< "_______________________"<< endl;
    cout<< "delete 1 company"<< endl;
    //Tester->delCompany(mn);
    if(!Tester->doesCompanyExist(name2)){
        cout<<"name1 doesn't exist"<<endl;
    }else{
        cout<<"name1 exists"<<endl;
    }
    cout<<"Size (del 2 company)"<<endl;
    cout<< Tester->getSize()<< endl;

    printCompanyByType(Small_Business);
    printCompanyByOwner("MMfgd");
    printAverageByType();


    Tester->freeMemory();
   return a.exec();
   }
