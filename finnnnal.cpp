#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Patient
{
public:
    string name;
    int age;
    string address;
    string mobileNumber;
    string symptoms;

    Patient(string n, int a, string addr, string mob, string symp)
        : name(n), age(a), address(addr), mobileNumber(mob), symptoms(symp) {}

    void displayDetails() const
    {
        cout << "Name: " << name << "\nAge: " << age << "\nAddress: " << address
             << "\nMobile Number: " << mobileNumber << "\nSymptoms/Disease: " << symptoms << "\n\n";
    }
};

void savePatientsToFile(const vector<Patient> &patients)
{
    ofstream outFile("patients.txt");

    if (outFile.is_open())
    {
        for (const auto &patient : patients)
        {
            outFile << patient.name << " " << patient.age << " " << patient.address
                    << " " << patient.mobileNumber << " " << patient.symptoms << "\n";
        }
        outFile.close();
        cout << "Patient data saved to 'patients.txt'.\n";
    }
    else
    {
        cout << "Unable to open the file for saving patient data.\n";
    }
}

void loadPatientsFromFile(vector<Patient> &patients)
{
    ifstream inFile("patients.txt");

    if (inFile.is_open())
    {
        string name, address, mobileNumber, symptoms;
        int age;

        while (inFile >> name >> age)
        {
            getline(inFile >> ws, address);
            inFile >> mobileNumber;
            getline(inFile >> ws, symptoms);

            patients.push_back(Patient(name, age, address, mobileNumber, symptoms));
        }

        inFile.close();
        cout << "Patient data loaded from 'patients.txt'.\n";
    }
    else
    {
        cout << "No existing patient data found.\n";
    }
}

void displayPatients(const vector<Patient> &patients)
{
    if (patients.empty())
    {
        cout << "No patients to display.\n\n";
    }
    else
    {
        cout << "Patient Details:\n";
        for (const auto &patient : patients)
        {
            patient.displayDetails();
        }
    }
}

void addPatient(vector<Patient> &patients)
{
    string name, address, mobileNumber, symptoms;
    int age;

    cout << "Enter patient name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter patient age: ";
    cin >> age;

    cout << "Enter patient address: ";
    cin.ignore();
    getline(cin, address);

    cout << "Enter patient mobile number: ";
    cin >> mobileNumber;

    cout << "Enter symptoms/disease description: ";
    cin.ignore();
    getline(cin, symptoms);

    patients.push_back(Patient(name, age, address, mobileNumber, symptoms));

    cout << "Patient added successfully!\n\n";
}

void displayContentsOfFile()
{
    ifstream inFile("patients.txt");

    if (inFile.is_open())
    {
        cout << "\nContents of 'patients.txt':\n";
        string line;
        while (getline(inFile, line))
        {
            cout << line << "\n";
        }
        inFile.close();
    }
    else
    {
        cout << "Unable to open the file for reading.\n";
    }
}

int main()
{
    vector<Patient> patients;

    loadPatientsFromFile(patients);

    char choice;

    do
    {
        cout << "1. Add Patient\n";
        cout << "2. Display Patients\n";
        cout << "3. Save and Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            addPatient(patients);
            break;

        case '2':
            displayPatients(patients);
            break;

        case '3':
            savePatientsToFile(patients);
            cout << "Patient data saved. Exiting the program.\n";
            break;

        default:
            cout << "Invalid choice. Please enter a valid option.\n\n";
        }

    } while (choice != '3');

    
    // displayContentsOfFile();

    return 0;
}
