#include "Person.h"

typedef struct _employee Employee;

struct _employee {
    Person base;
    Person *pSuper;
    char *pDepartment;
    char *pCompany;
    int salary;
};

Employee *
new_Employee(const char *pFName, const char *pLName, const char *pDepartment, const char *pCompany, int salary);