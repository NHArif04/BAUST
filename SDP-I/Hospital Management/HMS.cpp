/** 
** This Program is for Hospital Management System
** Language used: C++(OOP concept)
** Features: 
*/

#include <iostream>
#include <vector>

using namespace std;

// Function to clear the screen based on the operating system
void clearScreen(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

struct Appointment{
    string doctorName;
    string patientName;
    string date;
    string time;
};

struct MedicalRecord{
    string diagnosis;
    string treatment;
};

struct Patient{
    long long ID;
    string firstName;
    string lastName;
    int age;
    string blood;
    char gender;
    vector<MedicalRecord> medicalRecords;
};

class Hospital{
private:
    int count, MAX_PATIENTS = 1000;
    vector<Patient> patients;
    vector<Appointment> appointments;

public:
    Hospital() { count = 0; }
    void addPatient();
    void scheduleAppointment();
    void displayAppointments();
    void displayPatients();
    void generateReport();
    void addMedicalRecord();
    void displayMedicalRecord();
};

void Hospital::addPatient(){
    Patient p;

    cout << "Enter patient details:\n";
    cout << "First name: ";
    cin >> p.firstName;
    cout << "Last name: ";
    cin >> p.lastName;
    cout << "Age: ";
    cin >> p.age;
    cout << "Blood group: ";
    cin >> p.blood;
    cout << "Gender (m/f): ";
    cin >> p.gender;
    cout << "ID: ";
    cin >> p.ID;

    if (count == MAX_PATIENTS){
        cout << "Hospital full!" << endl;
        return;
    }
    // patients.resize(count + 1); // resize vector to accommodate new patient
    patients.push_back(p);
    count++;
    cout << "Patient added successfully!\nPress 'Enter' to return to 'Main Menu'\n";
    getchar();
}

void Hospital::displayPatients(){
    cout << "List of patients:\n";
    cout << "---------------------------------------" << endl;
    for (int i = 0; i < count; i++){
        cout << "ID: " << patients[i].ID << endl;
        cout << "Name: " << patients[i].firstName << " " << patients[i].lastName << endl;
        cout << "Age: " << patients[i].age << endl;
        cout << "Blood group: " << patients[i].blood << endl;
        cout << "Gender: " << patients[i].gender << endl;
        cout << "---------------------------------------" << endl;
    }
    cout << "Press 'Enter' to return to 'Main Menu'" << endl;
}

void Hospital::addMedicalRecord(){
    long long ID;
    cout << "Enter patient ID: ";
    cin >> ID;

    for (int i = 0; i < patients.size(); i++){
        if (patients[i].ID == ID){
            MedicalRecord record;
            cout << "Enter diagnosis: ";
            cin >> record.diagnosis;
            cout << "Enter treatment: ";
            cin >> record.treatment;
            patients[i].medicalRecords.push_back(record);
            cout << "Medical record added successfully!\n";
            return;
        }
    }
    cout << "Patient not found!\n";
}

void Hospital::displayAppointments(){
    cout << "List of appointments:\n";
    for (int i = 0; i < appointments.size(); i++){
        cout << "Doctor name: " << appointments[i].doctorName << endl;
        cout << "Patient name: " << appointments[i].patientName << endl;
        cout << "Date: " << appointments[i].date << endl;
        cout << "Time: " << appointments[i].time << endl;
        cout << "------------------------" << endl;
    }
}

void Hospital::displayMedicalRecord(){
    long long ID;
    cout << "Enter patient ID: ";
    cin >> ID;
    for (int i = 0; i < patients.size(); i++){
        if (patients[i].ID == ID){
            cout << "Medical Records:\n";
            for (int j = 0; j < patients[i].medicalRecords.size(); j++){
                cout << "Diagnosis: " << patients[i].medicalRecords[j].diagnosis << endl;
                cout << "Treatment: " << patients[i].medicalRecords[j].treatment << endl;
                cout << "------------------------" << endl;
            }
            return;
        }
    }
    cout << "Patient not found!\n";
}

void Hospital::scheduleAppointment(){
    Appointment a;
    cout << "Enter appointment details:\n";
    cout << "Doctor name: ";
    cin >> a.doctorName;
    cout << "Patient name: ";
    cin >> a.patientName;
    cout << "Date (dd/mm/yyyy): ";
    cin >> a.date;
    cout << "Time (hh:mm): ";
    cin >> a.time;
    appointments.push_back(a);
    cout << "Appointment scheduled successfully!\n";
}

void Hospital::generateReport(){
    long long ID;
    cout << "Enter patient ID: ";
    cin >> ID;
    for (int i = 0; i < patients.size(); i++){
        if (patients[i].ID == ID){
            cout << "Patient ID: " << patients[i].ID << endl;
            cout << "Name: " << patients[i].firstName << " " << patients[i].lastName << endl;
            cout << "Age: " << patients[i].age << endl;
            cout << "Blood group: " << patients[i].blood << endl;
            cout << "Gender: " << patients[i].gender << endl;
            cout << "Medical Records:\n";
            for (int j = 0; j < patients[i].medicalRecords.size(); j++){
                cout << "Diagnosis: " << patients[i].medicalRecords[j].diagnosis << endl;
                cout << "Treatment: " << patients[i].medicalRecords[j].treatment << endl;
                cout << "------------------------" << endl;
            }
            return;
        }
    }
    cout << "Patient not found!\n";
}

int main(){
    Hospital hospital;
    int choice;
    while (true){
        clearScreen();
        cout << "Hospital Management System" << endl;
        cout << "1. Add Patient" << endl;
        cout << "2. Display Patients" << endl;
        cout << "3. Schedule Appointment" << endl;
        cout << "4. Display Appointments" << endl;
        cout << "5. Add Medical Record" << endl;
        cout << "6. Display Medical Record" << endl;
        cout << "7. Generate Report" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        // cout << "\033[2J\033[1;1H"; // clear screen
        clearScreen();
        switch (choice){
        case 1:
            hospital.addPatient();
            break;

        case 2:
            hospital.displayPatients();
            break;

        case 3:
            hospital.scheduleAppointment();
            break;

        case 4:
            hospital.displayAppointments();
            break;

        case 5:
            hospital.addMedicalRecord();
            break;

        case 6:
            hospital.displayMedicalRecord();
            break;

        case 7:
            hospital.generateReport();
            break;

        case 8:
            exit(0);

        default:
            cout << "Invalid choice, please try again" << endl;
        }
        getchar();
    }
    return 0;
}