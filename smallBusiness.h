#ifndef SMALLBUSINESS_H
#define SMALLBUSINESS_H
#include "abstractcompany.h"

class SmallBusiness : public AbstractCompany
{
public:
    SmallBusiness(QString name,QList<QString> owners,double profit,double area, int employees);

    ~SmallBusiness(){}

    TypeOfCompany getTypeOfCompany();

    double getTaxMounth();
};

#endif
