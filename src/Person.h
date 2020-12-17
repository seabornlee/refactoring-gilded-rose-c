#include <stdio.h>
#include <stdlib.h>

typedef struct _person Person;

static void delete_person(void *pObj);

static void person_displayinfo(void *pObj);

static void person_writetofile(void *pObj, const char *pFileName);

static void delete_employee(void *pObj);

static void employee_displayinfo(void *pObj);

static void employee_writetofile(void *pObj, const char *pFileName);

struct _person {
    char *pFirstName;
    char *pLastName;

    // interface to access member functions
    void (*display)(void *);

    void (*writeToFile)(void *, const char *);

    void (*delete)(void *);
};

Person *newPerson(const char *pFName, const char *pLName);