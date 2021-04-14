#include "register.h"

enum Exception {out_of_the_array};


Register* Register::instance = nullptr;

Register::Register(){
    cout << "New register created" << endl;
}
QList<AbstractCompany*> Register:: getCompanies(){
    return companies;
}
bool Register::addCompany(AbstractCompany* company){
    if(!doesCompanyExist(company->getName())){
        companies.push_back(company);
        return true;
    }
    return false;
}

bool  Register::delCompany(AbstractCompany* company){
    if(!doesCompanyExist(company->getName())){
        return false;
    }

    for(int i=0; i < companies.count()-1; i++){
        if(this->companies[i]->getName() == company->getName()){
            this->companies.removeAt(i);
            return true;
        }
    }
    return false;
}

bool  Register::delCompany(QString companyName){
    if(!doesCompanyExist(companyName)){
        return false;
    }

    for(int i=0; i < companies.count()-1; i++){
        if(companies[i]->getName() == companyName){
            this->companies.removeAt(i);
            return true;
        }
    }
    return false;
}

AbstractCompany*  Register::getByIndex(int index){
    if(index>=getSize() || index < 0){
        throw new Exception(out_of_the_array);
    }
    return companies[index];
}
AbstractCompany*  Register::getByName(QString companyName){
    for(int i=0; i < companies.count()-1; i++){
        if(this->companies[i]->getName() == companyName){
            return companies[i];
            }
        }
    return nullptr;
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
