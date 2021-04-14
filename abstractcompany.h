#ifndef ABSTRACT_COMPANY_H
#define ABSTRACT_COMPANY_H
#include <iostream>
#include <QString>
#include <QList>

using namespace std;

enum TypeOfCompany{
    Small_Business, Medium_Business, Big_Business
};


class AbstractCompany
{

    QString name;
    QList<QString> owners;
    double profit;
    double area;
    int employees;

public:
    AbstractCompany(QString name,QList<QString> owners,double profit,double area, int employees){
        this->name =name;
        this->owners =owners;
        this->profit =profit;
        this->area =area;
        this->employees =employees;
    };

    virtual ~AbstractCompany(){}

    QString getName();

    void setName(QString name);

    QList<QString> getOwners();

    void setOwners (QList<QString> owners);

    double getProfit();

    void setProfit(double profit);

    double getArea();

    void setArea(double area);

    int getEmployees();

    int setEmployees(int employees);

    virtual TypeOfCompany getTypeOfCompany() = 0;
    virtual double getTaxMounth() = 0;

    friend ostream& operator<< (ostream &out,  AbstractCompany* company);

    static string getCompanyTypeString(TypeOfCompany type);
};



#endif
