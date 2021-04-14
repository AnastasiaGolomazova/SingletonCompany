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
      return (this->employees = employees);

    }

    ostream& operator<< (ostream &out,  AbstractCompany* company){

        out << "Name: " << company->name.toStdString()<<endl;

        out << "Owners: " << endl;
        for(int i = 0; i < company->owners.count();i++ ){
            out << company->owners[i].toStdString() << endl;
        }
        out << "Profit: " <<company->profit <<endl;
        out << "Area: " <<company->area << endl;
        out << "Employees: " <<company->employees << endl;
        out << "Type of company: " << company->getCompanyTypeString(company->getTypeOfCompany()).c_str() << endl;
        out << "Tax: " << company->getTaxMounth() << endl;
        return out;
    }

    string AbstractCompany::getCompanyTypeString(TypeOfCompany type){
        switch(type){
        case Small_Business: return "Small business";
        case Big_Business: return "Big business";
        case Medium_Business: return "Medium business";
        default: return "Unknown";
       }
    }

