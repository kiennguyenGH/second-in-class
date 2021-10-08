#include <string.h>
#include "employee.h"

//ptr - points to table to be searched
//tableSize - size of the table
//targetPtr - points to value that will be searched for in table
//functionPtr - points to a comparison function below and will perform the associated check

//functionPtr is the address of the functoin just use the name
//()(The second set of parentheses is arguments of function call)
static PtrToEmployee searchEmployeeTable(PtrToConstEmployee ptr, int tableSize, const void *targetPtr,
                                         int (*functionPtr)(const void *, PtrToConstEmployee))
{
    PtrToConstEmployee endPtr = ptr + tableSize;

    for(; ptr < endPtr; ptr++)
        if ((*functionPtr)(targetPtr, ptr) == 0)
            return (PtrToEmployee) ptr;
    return NULL; 
}

static int compareEmployeeNumber(const void *targetPtr, PtrToConstEmployee tableValuePtr)
{
    return *(long *) targetPtr != tableValuePtr -> number; //const void *targetPtr ==> typecast as int pointer
}

static int compareEmployeeName(const void *targetPtr, PtrToConstEmployee tableValuePtr)
{
    return strcmp((char *) targetPtr, tableValuePtr -> name); //const void *targetPtr ==> typecast as char
}

static int compareEmployeePhone(const void *targetPtr, PtrToConstEmployee tableValuePtr)
{
    return strcmp((char *) targetPtr, tableValuePtr -> phone); //const void *targetPtr ==> typecast as char
}

static int compareEmployeeSalary(const void *targetPtr, PtrToConstEmployee tableValuePtr)
{
    return *(double *) targetPtr != tableValuePtr -> salary; //const void *targetPtr ==> typecast as int pointer
}

//Wrappers
PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int size, long number)
{
    return searchEmployeeTable(ptr, size, &number, compareEmployeeNumber);
}

PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int size, char* name){
    return searchEmployeeTable(ptr, size, name, compareEmployeeName);
}

PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr, int size, char* phone){
    return searchEmployeeTable(ptr, size, phone, compareEmployeePhone);
}

PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int size, double salary)
{
    return searchEmployeeTable(ptr, size, &salary, compareEmployeeSalary);
}