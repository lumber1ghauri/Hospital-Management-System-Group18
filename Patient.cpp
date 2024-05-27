#include "Patient.h"

Patient::Patient() : id(0), isAdmitted(false) {}

Patient::Patient(int id, string name, string cnic, string phoneNumber, string disease, bool isAdmitted)
    : id(id), name(name), cnic(cnic), phoneNumber(phoneNumber), disease(disease), isAdmitted(isAdmitted) {}

void Patient::display() const
{
    cout << "ID: " << id << "\n"
         << "Name: " << name << "\n"
         << "CNIC: " << cnic << "\n"
         << "Phone Number: " << phoneNumber << "\n"
         << "Disease: " << disease << "\n"
         << "Is Admitted: " << (isAdmitted ? "Yes" : "No") << "\n";
}
