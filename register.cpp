#include "register.h"

QList<AbstractCompany*> Register:: getCompanies(){
    return companies;
}
bool Register::addCompany(AbstractCompany* company){
    if(!doesCompanyExist(company->getName())){
        companies.push_back(company);
        return true;
    }
    return false;

    //& this->companies[i]->getArea() == company->getArea() &
    //this->companies[i]->getOwners() == company->getOwners()&
    //this->companies[i]->getProfit() == company->getProfit()&
    //this->companies[i]->getEmployees() == company->getEmployees()
}
bool  Register::delCompany(AbstractCompany* company){
    if(doesCompanyExist(company->getName())){
        for(int i=0; i < companies.count()-1; i++){
            if(this->companies[i]->getName() == company->getName()){
                this->companies.removeAt(i);
                return true;
                }
            }
        }
    return false;

    }

AbstractCompany*  Register::getByIndex(int index){
    return companies[index];
}
AbstractCompany*  Register::getByName(QString companyName){
    for(int i=0; i < companies.count()-1; i++){
        if(this->companies[i]->getName() == companyName){
            return companies[i];
            }
        }
}
bool Register::doesCompanyExist(QString companyName){
    for(int i=0; i < companies.count()-1; i++){
        if(companies[i]->getName() == companyName){
            return true;
        }
    }
    return false;
}
int Register::getSize (){
    return companies.count();
}
