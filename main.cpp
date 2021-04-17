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
    QString CocaCola = "CocaCola";
    QString Lipton = "Lipton";
    QString Mercury = "Mercury";
    QString Olympus = "Olympus";
    QList<QString> owners =  {"Henkel Rus", "Gee Johnson"};
    QList<QString> owners1 =  {"Procter Gamble", "Gee Johnson"};
    QList<QString> owners2 =  {"Procter Gamble", "Philip Morris"};



    Register* Tester = Register::GetInstance();
    MediumBusiness* odj = new MediumBusiness(Lipton, owners, 44,55, 11);
    Tester->addCompany(odj);
    cout<< "Size (add 1 company)" << endl;
    cout<< Tester->getSize()<< endl;

    SmallBusiness* odj1 = new SmallBusiness(Lipton, owners, 5,7, 5);
    SmallBusiness* odj2 = new SmallBusiness(Mercury, owners1, 4,5, 5);
    BigBusiness* odj3 = new BigBusiness(Olympus, owners2, 121,10000, 100);
    Tester->addCompany(odj1);
    Tester->addCompany(odj2);
    Tester->addCompany(odj3);
    cout<< "Size (add 3 company)"<< endl;
    cout<< Tester->getSize()<< endl;

    cout<< "_______________________"<< endl;
    cout<< "delete 1 company"<< endl;
    if(!Tester->doesCompanyExist(CocaCola)){
        cout<<"CocaCola doesn't exist"<<endl;
    }else{
        cout<<"CocaCola exists"<<endl;
    }

    cout<< "_______________________"<< endl;
    cout<< "delete 1 company"<< endl;
    //Tester->delCompany(mn);
    if(!Tester->doesCompanyExist(Mercury)){
        cout<<"Mercury doesn't exist"<<endl;
    }else{
        cout<<"Mercury exists"<<endl;
    }

    cout<< "_______________________"<< endl;
    cout<<"Size (del 2 company)"<<endl;
    cout<< Tester->getSize()<< endl;

    printCompanyByType(Small_Business);
    printCompanyByOwner("Gee Johnson");
    printAverageByType();


   Tester->freeMemory();
   return a.exec();
   }
