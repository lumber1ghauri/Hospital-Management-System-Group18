#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Patient class definition
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
class PatientManager
{
public:
    void addPatient(const Patient &patient);
    void deletePatient(int id);
    void updatePatient(int id);
    void searchPatient(int id) const;
    void displayAllPatients() const;
    void loadPatients();


private:
    vector<Patient> patients;

        void savePatients() const;
};

void PatientManager::addPatient(const Patient &patient)
{
    patients.push_back(patient);
    savePatients();
    cout << "Patient added successfully." << endl;
}

void PatientManager::deletePatient(int id)
{
    for (size_t i = 0; i < patients.size(); ++i)
    {
        if (patients[i].id == id)
        {
            patients.erase(patients.begin() + i);
            savePatients();
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

            savePatients();
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

void PatientManager::loadPatients()
{
    ifstream file("PatientRecord.dat", ios::in | ios::binary);
    if (file.is_open())
    {
        Patient temp;
        while (file.read(reinterpret_cast<char *>(&temp), sizeof(Patient)))
        {
            patients.push_back(temp);
        }
        file.close();
    }
}

void PatientManager::savePatients() const
{
    ofstream file("PatientRecord.txt", ios::out | ios::binary | ios::trunc);
    if (file.is_open())
    {
        for (const auto &patient : patients)
        {
            file.write(reinterpret_cast<const char *>(&patient), sizeof(Patient));
        }
        file.close();
    }
}

// Main function
int main()
{
    PatientManager manager;
    manager.loadPatients();

    int choice;

    do
    {
        cout << "1. Add Patient\n";
        cout << "2. Delete Patient\n";
        cout << "3. Update Patient\n";
        cout << "4. Search Patient\n";
        cout << "5. Display All Patients\n";
        cout << "Enter your choice (0 to exit): ";
        cin >> choice;

        // Validate input
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number: ";
            cin >> choice;
        }

        switch (choice)
        {
        case 1:
        {
            int id;
            string name, cnic, phoneNumber, disease;
            bool isAdmitted;

            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter CNIC: ";
            getline(cin, cnic);
            cout << "Enter Phone Number: ";
            getline(cin, phoneNumber);
            cout << "Enter Disease: ";
            getline(cin, disease);
            cout << "Is Admitted (1 for Yes, 0 for No): ";
            cin >> isAdmitted;

            Patient patient(id, name, cnic, phoneNumber, disease, isAdmitted);
            manager.addPatient(patient);
            break;
        }
        case 2:
        {
            int id;
            cout << "Enter ID of patient to delete: ";
            cin >> id;
            manager.deletePatient(id);
            break;
        }
        case 3:
        {
            int id;
            cout << "Enter ID of patient to update: ";
            cin >> id;
            manager.updatePatient(id);
            break;
        }
        case 4:
        {
            int id;
            cout << "Enter ID of patient to search: ";
            cin >> id;
            manager.searchPatient(id);
            break;
        }
        case 5:
        {
            manager.displayAllPatients();
            break;
        }
        case 0:
        {
            cout << "Exiting..." << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
        }
        }
    } while (choice != 0);

    return 0;
}
