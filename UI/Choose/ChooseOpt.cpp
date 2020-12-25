#include "ChooseOpt.h"
void ChooseOpt(int n)
{
    cout <<"              EMPLOYEE MANAGEMENT PROGRAM\n";
    cout <<"*************************MENU**************************\n";
    cout <<"**1. Add information                              = 1**\n";
    cout <<"**2. Edit information                             = 2**\n";
    cout <<"**3. Delete information                           = 3**\n";
    cout <<"**4. Read information                             = 4**\n";
    cout <<"**0. Exit                                         = 0**\n";
    cout <<".......................................................\n";
    int x;
    cout <<"Press a number :";
    cin>>x;
    EmployeeData employeedata;
    AddEmployee(employeedata);
    switch (x){ 
        case 1:
            if (n == 1) {
                employeedata.Add();
                DisplayEmployees(employeedata);  
            }
            break;
        case 2:
            if (n == 1) {
                int id;
                cout << "Enter the person who idou want to edit: ";
                cin >> id;
                employeedata.Edit(id - 1);    
                DisplayEmployees(employeedata);  
            }
            break;
        case 3:
            if (n == 1) {
                int id;
                cout << "Enter the person who yoid want to delete: ";
                cin >> id;
                employeedata.Delete(id);
                DisplayEmployees(employeedata);
            }
            break;
        case 4:
            if (n == 1) {
                employeedata.Read();
            }
            break;
        default:
            break;
    } 
}