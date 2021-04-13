#ifndef ABSTRACT_COMPANY_H
#define ABSTRACT_COMPANY_H



#include <QString>
#include <QList>


enum TypeOfCompany{Small_Business, Big_Business, Medium_Business};

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
};



#endif
