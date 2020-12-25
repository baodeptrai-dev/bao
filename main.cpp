#include <iostream>
#include "BusinessObject/Employee.h"
#include "DataAccess/EmployeeData.h"
#include "UI/UI_Choose.h"
using namespace std;

int main() {
    Employee e1("Chau1", "Bao", "Ngo", 111222333, "1975-10-03", "Chicago", "M", 10000, -1, 6);
    Employee e2("Chau2", "Bao", "Ngo", 111222333, "1975-10-03", "Chicago", "M", 10000, -1, 6);
    EmployeeData ed;
    ed.PushBack(e1);
    ed.PushBack(e2);
    ed.ExportToFile("bao.data");
    ed.Read("bao.data");
    cout<<ed.Get(0).ToString()<<endl;
    cout<<ed.Get(1).ToString()<<endl;
    return 0;
}
