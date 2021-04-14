#ifndef MEDIUMBUSINESS_H
#define MEDIUMBUSINESS_H
#include "abstractcompany.h"

class MediumBusiness : public AbstractCompany
{
public:


    MediumBusiness(QString name,QList<QString> owners,double profit,double area, int employees);

    ~MediumBusiness(){}

    TypeOfCompany getTypeOfCompany();

    double getTaxMounth();
};

#endif
