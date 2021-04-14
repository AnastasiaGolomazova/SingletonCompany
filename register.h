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

  static void freeMemory(){
      if(instance){
          delete instance;
      }
  }
  int getSize ();
  AbstractCompany* getByName(QString companyName);
};

#endif


