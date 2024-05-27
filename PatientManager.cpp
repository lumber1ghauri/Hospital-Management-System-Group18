#include "PatientManager.h"

void PatientManager::addPatient(const Patient &patient)
{
    patients.push_back(patient);
    ofstream file("PatientRecord.dat", ios::out | ios::binary | ios::trunc);
    if (file.is_open()) {
        savePatients(file);
    }
    file.close();
    cout << "Patient added successfully." << endl;
}

void PatientManager::deletePatient(int id)
{
    for (size_t i = 0; i < patients.size(); ++i)
    {
        if (patients[i].id == id)
        {
            patients.erase(patients.begin() + i);
            ofstream file("PatientRecord.dat", ios::out | ios::binary | ios::trunc);
            if (file.is_open()) {
                savePatients(file);
            }
            file.close();
            cout << "Patient deleted successfully." << endl;
            return;
        }
    }
    cout << "No record found." << endl;
}

void PatientManager::updatePatient(int id)
{
    for (auto &patient : patients)
    {
        if (patient.id == id)
        {
            cout << "Enter updated information:" << endl;
            cout << "Name: ";
            cin.ignore();
            getline(cin, patient.name);
            cout << "CNIC: ";
            getline(cin, patient.cnic);
            cout << "Phone Number: ";
            getline(cin, patient.phoneNumber);
            cout << "Disease: ";
            getline(cin, patient.disease);
            cout << "Is Admitted (1 for Yes, 0 for No): ";
            cin >> patient.isAdmitted;

            ofstream file("PatientRecord.dat", ios::out | ios::binary | ios::trunc);
            if (file.is_open()) {
                savePatients(file);
            }
            file.close();
            cout << "Patient updated successfully." << endl;
            return;
        }
    }

    cout << "No record found." << endl;
}

void PatientManager::searchPatient(int id) const
{
    for (const auto &patient : patients)
    {
        if (patient.id == id)
        {
            patient.display();
            return;
        }
    }

    cout << "No record found." << endl;
}

void PatientManager::displayAllPatients() const
{
    if (patients.empty())
    {
        cout << "No record found." << endl;
    }
    else
    {
        for (const auto &patient : patients)
        {
            patient.display();
            cout << "------------------------" << endl;
        }
    }
}

void PatientManager::loadPatients(istream &file)
{
    if (file.good())
    {
        Patient temp;
        while (file.read(reinterpret_cast<char *>(&temp), sizeof(Patient)))
        {
            patients.push_back(temp);
        }
    }
}

void PatientManager::savePatients(ostream &file) const
{
    if (file.good())
    {
        for (const auto &patient : patients)
        {
            file.write(reinterpret_cast<const char *>(&patient), sizeof(Patient));
        }
    }
}
