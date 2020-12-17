#include "Person.h"
#include <string.h>

Person * newPerson(const char *pFName, const char *pLName)   // constructor
{
    Person *pObj = NULL;

    // allocating memory
    pObj = (Person *)malloc(sizeof(Person));
    if (pObj == NULL) return NULL;

    pObj->pFirstName = malloc(sizeof(char)*(strlen(pFName)+1));
    strcpy(pObj->pFirstName, pFName);

    pObj->pLastName = malloc(sizeof(char)*(strlen(pLName)+1));
    strcpy(pObj->pLastName, pLName);

    // Initializing interface for access to functions
    pObj->delete = delete_person;          // destructor pointing to destrutor of itself
    pObj->display = person_displayinfo;
    pObj->writeToFile = person_writetofile;

    return pObj;
}

static void delete_person(void * pObj)          // destructor
{
    Person *pPersonObj = (Person *)pObj;

    if(NULL != pPersonObj)
    {
        free(pPersonObj->pFirstName);
        free(pPersonObj->pLastName);
        free(pPersonObj);
    }
}

static void person_displayinfo(void * pObj)
{
    Person *pPersonObj = (Person *)pObj;

    printf("FirstName: %s\n", pPersonObj->pFirstName);
    printf("LastName: %s\n", pPersonObj->pLastName);
}

static void person_writetofile(void * pObj, const char *pFileName)
{
    Person *pPersonObj = (Person *)pObj;

    // code for writing Person information to file
    printf("Write person's information to file: %s\n", pFileName);
}