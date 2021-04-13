#include "mediumBusiness.h"

MediumBusiness::MediumBusiness(QString name,QList<QString> owners,double profit,double area, int employees):
    AbstractCompany(name,owners, profit,area, employees){};

TypeOfCompany MediumBusiness::getTypeOfCompany(){
    return TypeOfCompany::Medium_Business;
}

double MediumBusiness::getTaxMounth(){
    return (getEmployees()/getArea())*getProfit()*0.2;
}
