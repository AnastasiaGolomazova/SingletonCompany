#include "abstractcompany.h"

    QString AbstractCompany::getName(){
        return name;
    }

    void AbstractCompany::setName(QString name){
      this->name = name;
    }


    QList<QString> AbstractCompany::getOwners(){
        return owners;
    }

    void AbstractCompany::setOwners (QList<QString> owners){
      this->owners = owners;
    }


    double AbstractCompany::getProfit(){
        return profit;
    }

    void AbstractCompany::setProfit(double profit){
      this->profit = profit;
    }

    double AbstractCompany::getArea(){
        return profit;
    }

    void AbstractCompany::setArea(double area){
      this->area = area;
    }

    int AbstractCompany::getEmployees(){
        return profit;
    }

    int AbstractCompany::setEmployees(int employees){
      this->employees = employees;
    }

