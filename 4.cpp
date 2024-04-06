#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Patient {
public:
    string name;
    int age;
    string address;

    Patient(string n, int a, string addr) : name(n), age(a), address(addr) {}

    void displayDetails() const {
        cout << "Name: " << name << "\nAge: " << age << "\nAddress: " << address << "\n\n";
    }
};

int main() {
    vector<Patient> patients;

    char choice;

    do {
        cout << "1. Add Patient\n";
        cout << "2. Display Patients\n";
        cout << "3. Retrieve Patient Data\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                string name, address;
                int age;

                cout << "Enter patient name: ";
                cin.ignore();
                getline(cin, name);

                cout << "Enter patient age: ";
                cin >> age;

                cout << "Enter patient address: ";
                cin.ignore();
                getline(cin, address);

                patients.push_back(Patient(name, age, address));

                cout << "Patient added successfully!\n\n";
                break;
            }

            case '2': {
                if (patients.empty()) {
                    cout << "No patients to display.\n\n";
                } else {
                    cout << "Patient Details:\n";
                    for (const auto &patient : patients) {
                        patient.displayDetails();
                    }
                }
                break;
            }

            case '3': {
                if (patients.empty()) {
                    cout << "No patients to retrieve.\n\n";
                } else {
                    int index;
                    cout << "Enter the index of the patient to retrieve: ";
                    cin >> index;

                    if (index >= 0 && index < patients.size()) {
                        cout << "Retrieved Patient Details:\n";
                        patients[index].displayDetails();
                    } else {
                        cout << "Invalid index.\n";
                    }
                }
                break;
            }

            case '4':
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n\n";
        }
    } while (choice != '4');

    return 0;
}
