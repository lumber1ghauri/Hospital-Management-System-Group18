#ifndef PATIENTMANAGER_H
#define PATIENTMANAGER_H

#include "Patient.h"
#include <vector>
#include <fstream>

using namespace std;

class PatientManager
{
public:
    void addPatient(const Patient &patient);
    void deletePatient(int id);
    void updatePatient(int id);
    void searchPatient(int id) const;
    void displayAllPatients() const;
    void loadPatients(istream &file);
    void savePatients(ostream &file) const;

private:
    vector<Patient> patients;
};

#endif // PATIENTMANAGER_H
