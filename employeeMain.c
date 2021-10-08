//gcc employeeMain.c employeeTable.c employeeOne.c
//gcc employeeMain.c employeeTable.c employeeTwo.c
#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void){
    //defined in employeeOne.c or employeeTwo.c
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);
    PtrToEmployee searchEmployeeByPhone(const Employee table[], int sizeTable, char * phoneToFind);
    PtrToEmployee searchEmployeeBySalary(const Employee table[], int sizeTable, double salaryToFind);

    //defined in employeeTable.c
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr; //Declaration

    //Number
    matchPtr = searchEmployeeByNumber(EmployeeTable, EmployeeTableEntries, 5054l);
    if (matchPtr != NULL)
        printf("Employee ID 5054 is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee ID is NOT found in the record\n");
        
    //Name
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Tony Bobcat");
    if (matchPtr != NULL)
        printf("Employee Tony Bobcat is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Tony Bobcat is NOT found in the record\n");

    //Phone
    matchPtr = searchEmployeeByPhone(EmployeeTable, EmployeeTableEntries, "310-555-1215");
    if (matchPtr != NULL)
        printf("Employee Phone Number is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Phone Number is NOT found in the record\n");

    //Salary
    matchPtr = searchEmployeeBySalary(EmployeeTable, EmployeeTableEntries, 4.50);
    if (matchPtr != NULL)
        printf("Employee Salary is in record %d\n", matchPtr - EmployeeTable);
    else
        printf("Employee Salary is NOT found in the record\n");

    return EXIT_SUCCESS;
}