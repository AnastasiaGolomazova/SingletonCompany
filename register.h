#ifndef REGISTER_H
#define REGISTER_H
#include <QList>
#include "abstractcompany.h"

class Register
{
    QList<AbstractCompany*> companies;
protected:
    Register();

public:
  QList<AbstractCompany*> getCompanies();
  bool addCompany(AbstractCompany* company);
  bool delCompany(AbstractCompany* company);
  AbstractCompany* getByIndex(int index);
  bool doesCompanyExist(QString company);
  static Register& GetInstance(){
      static Register instance;
      return instance;
  };
  int getSize ();
  AbstractCompany* getByName(QString companyName);
};

#endif


