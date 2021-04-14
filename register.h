#ifndef REGISTER_H
#define REGISTER_H
#include <QList>
#include "abstractcompany.h"

class Register
{
    QList<AbstractCompany*> companies;
protected:
    Register();
    static Register* instance;

public:
  QList<AbstractCompany*> getCompanies();
  bool addCompany(AbstractCompany* company);
  bool delCompany(AbstractCompany* company);
  bool delCompany(QString companyName);
  AbstractCompany* getByIndex(int index);
  bool doesCompanyExist(QString company);
  static Register* GetInstance(){
      if(!instance){
          instance = new Register;
      }
      return instance;
  };

  void freeMemory(){
      for(int i = 0; i < companies.count(); i++){
          delete companies[i];
      }

      if(instance){
          cout << "Singletone memory is free" << endl;
          delete instance;
      }
  }
  int getSize ();
  AbstractCompany* getByName(QString companyName);
};

#endif


