#include <string.h>
#include "Employee.h"

Employee * new_Employee(const char *pFName, const char *pLName, const char *pDepartment, const char *pCompany, int salary)    // constructor
{
    Employee *pEmpObj;
    Person *pPersonObj;

    pPersonObj = newPerson(pFName, pLName);        // calling base class construtor
    //allocating memory
    pEmpObj = malloc(sizeof(Employee));
    if (NULL == pEmpObj) {
        pPersonObj->delete(pPersonObj);
        return NULL;
    }
    pEmpObj->pSuper = pPersonObj;
    pEmpObj->base   =*pPersonObj;
    // Changing base class interface to access derived class functions
    pEmpObj->base.delete = delete_employee;       // Person destructor pointing to destrutor of Employee
    pEmpObj->base.display = employee_displayinfo;
    pEmpObj->base.writeToFile = employee_writetofile;

    // initialising derived class members
    pEmpObj->pDepartment = malloc(sizeof(char)*(strlen(pDepartment)+1));
    strcpy(pEmpObj->pDepartment, pDepartment);

    pEmpObj->pCompany = malloc(sizeof(char)*(strlen(pCompany)+1));
    strcpy(pEmpObj->pCompany, pCompany);

    pEmpObj->salary = salary;

    return pEmpObj;
}

static void delete_employee(void * pObj)    // destructor
{
    Employee *pEmpObj = (Employee *)pObj;
    Person *pPersonObj = pEmpObj->pSuper;

    // destroy derived obj
    free(pEmpObj->pCompany);
    free(pEmpObj->pDepartment);
    free(pEmpObj);

    // destroy super Obj
    pPersonObj->delete(pPersonObj);
}

static void employee_displayinfo(void * pObj)
{
    Employee *pEmpObj = (Employee *)pObj;
    Person *pPersonObj = pEmpObj->pSuper;

    // displaying Person info
    pPersonObj->display(pPersonObj);

    // displaying Employee specific info
    printf("Department: %s\n", pEmpObj->pDepartment);
    printf("Company: %s\n", pEmpObj->pCompany);
    printf("salary: %d\n", pEmpObj->salary);
}

static void employee_writetofile(void * pObj, const char *pFileName)
{
    Employee *pEmpObj = (Employee *)pObj;
    Person *pPersonObj = pEmpObj->pSuper;

    // writing Person information
    pPersonObj->writeToFile(pPersonObj, pFileName);

    // code to write Employee specific info
    printf("Write employee's specific information to file: %s\n", pFileName);
}