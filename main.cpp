#include <iostream>
#include "PatientManager.cpp"

using namespace std;

int main()
{
    PatientManager manager;
    ifstream inFile("PatientRecord.dat", ios::in | ios::binary);
    if (inFile.is_open()) {
        manager.loadPatients(inFile);
    }
    inFile.close();

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
