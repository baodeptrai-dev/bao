#include "EmployeeData.h"
#include <iostream>
#include <fstream>
#include "../libs/json.hpp"
using namespace std;

using json = nlohmann::json;

EmployeeData::EmployeeData(){
    _maxId = 0;
    _employeeArr.resize(0);
}

void EmployeeData::Read(string filename){
    _maxId = 0;
    _employeeArr.resize(0);
    ifstream inFile(filename);
    const int maxSize = 255;
    char buff[maxSize]; 
    while (inFile.getline(buff,maxSize)) {
        json j = json::parse(buff);
        //string sex = j["Sex"];
        Employee e(
            j["Fname"],
            j["Minit"],
            j["Lname"],
            j["Ssn"],
            j["Bdate"],
            j["Address"],
            j["Sex"],
            j["Salary"],
            j["Superssn"],
            j["Dno"]
        );
        e.IncreaseId();
        _employeeArr.push_back(e);
    }
    inFile.close();
}

int EmployeeData::GetMaxId(){
    return _maxId;
}
int EmployeeData::PushBack(Employee e){
    e.IncreaseId();
    if (_maxId < e.GetId()){
        _maxId = e.GetId();
    }
    _employeeArr.push_back(e);
    return _maxId;
}


Employee& EmployeeData::Get(int i) {
    return _employeeArr[i];
}

void EmployeeData::Delete(int i) {
    _employeeArr.erase(_employeeArr.begin() + i - 1);
    _maxId = _employeeArr.size();
    for (int j = i-1; j < _maxId; j++){
        _employeeArr[j].GetId() = j + 1;
    }
    _employeeArr.back().GetIdNew() = _maxId;
}

void EmployeeData::Add() {
    Employee e;
    cin >> e;
    e.IncreaseId();
    _employeeArr.push_back(e);
}

void EmployeeData::Edit(int i) {
    cin >> _employeeArr[i];
}


int EmployeeData::GetSize() {
    return _employeeArr.size();
}

int EmployeeData::ExportToFile(string filename){
    ofstream outFile(filename, ios::out);
    if (!outFile) return 0;
    for (Employee e :_employeeArr){
        outFile << e.ToJson() << endl;
    }
    outFile.close();
    return 1;
}
