#include "bigBusiness.h"

BigBusiness::BigBusiness(QString name,QList<QString> owners,double profit,double area, int employees):
    AbstractCompany(name,owners, profit,area, employees){};

TypeOfCompany BigBusiness::getTypeOfCompany(){
    return TypeOfCompany::Big_Business;
}

double BigBusiness::getTaxMounth(){
    return (getProfit()/getEmployees())*0.18;
}
