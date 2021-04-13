#ifndef BIGBUSINESS_H
#define BIGBUSINESS_H
#include "abstractcompany.h"

class BigBusiness : public AbstractCompany
{
public:
    BigBusiness(QString name,QList<QString> owners,double profit,double area, int employees);

    TypeOfCompany getTypeOfCompany();

    double getTaxMounth();
};

#endif
