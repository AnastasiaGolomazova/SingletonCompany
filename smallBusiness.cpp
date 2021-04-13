#include "smallBusiness.h"

SmallBusiness::SmallBusiness(QString name,QList<QString> owners,double profit,double area, int employees):
    AbstractCompany(name,owners, profit,area, employees){};

TypeOfCompany SmallBusiness::getTypeOfCompany(){
    return TypeOfCompany::Small_Business;
}

double SmallBusiness::getTaxMounth(){
    return getArea()*getProfit()*0.18;
}
