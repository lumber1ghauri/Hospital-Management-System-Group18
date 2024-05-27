#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>

using namespace std;

class Patient
{
public:
    int id;
    string name;
    string cnic;
    string phoneNumber;
    string disease;
    bool isAdmitted;

    Patient();
    Patient(int id, string name, string cnic, string phoneNumber, string disease, bool isAdmitted);

    void display() const;
};

#endif // PATIENT_H
