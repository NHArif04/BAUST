#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

// Function to clear the screen based on the operating system
void clearScreen(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

struct User{
    string username;
    string password;
};

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
    unsigned long long ID;
    string firstName;
    string lastName;
    string age;
    string blood;
    string gender;
    vector<MedicalRecord> medicalRecords;
};

class Hospital{
private:
    int count, MAX_PATIENTS = 1000;
    vector<Patient> patients;
    vector<Appointment> appointments;
    vector<User> users;

public:
    Hospital() { count = 0; }
    void loadUserFromFile();
    void registerUser();
    bool loginUser();
    void loadPatientDataFromFile();
    void loadAppointmentDataFromFile();
    void savePatientDataToFile();
    void saveAppointmentDataToFile();
    void addPatient();
    void scheduleAppointment();
    void displayAppointments();
    void displayPatients();
    void generateReport();
    void addMedicalRecord();
    void displayMedicalRecord();
};

void Hospital::loadUserFromFile(){
    ifstream inFile("auth.txt");
    if (inFile.is_open()){
        users.clear();
        User user;
        while (inFile >> user.username >> user.password){
            users.push_back(user);
        }
        inFile.close();
        cout << "User data loaded from auth.txt" << endl;
    }else{
        cout << "Error opening auth.txt for reading." << endl;
    }
}

void Hospital::registerUser(){
    clearScreen();
    User newUser;
    cout << "Registration Page" << endl;
    cout << "Enter a username: ";
    cin >> newUser.username;
    cout << "Enter a password: ";
    cin >> newUser.password;

    for (const User &user : users){
        if (user.username == newUser.username){
            cout << "Username already exists. Registration failed." << endl;
            getchar();
            return;
        }
    }

    users.push_back(newUser);

    ofstream outFile("auth.txt", ios::app);
    if (outFile.is_open()){
        outFile << newUser.username << " " << newUser.password << endl;
        outFile.close();
        cout << "Registration successful! You can now log in." << endl;
    }else{
        cout << "Error opening auth.txt for writing." << endl;
    }
    cin.ignore();
    clearScreen();
}

bool Hospital::loginUser(){
    string username, password;
    cout << "Login Page" << endl;
    cout << "Enter your username: ";
    cin >> username;

    for (const User &user : users){
        if (user.username == username){
            cout << "Enter your password: ";
            cin >> password;

            if (user.password == password){
                cout << "Login successful!" << endl;
                return true;
            }else{
                cout << "Incorrect password. Login failed." << endl;
                return false;
            }
        }
    }

    cout << "User not found. Login failed." << endl;
    return false;
}

void Hospital::loadPatientDataFromFile(){
    ifstream inFile("patients.txt");
    inFile >> count;
    if (inFile.is_open()){
        patients.clear();
        Patient patient;
        while (inFile >> patient.ID){
            inFile.ignore();
            getline(inFile, patient.firstName);
            getline(inFile, patient.lastName);
            inFile >> patient.age;
            inFile.ignore();
            getline(inFile, patient.blood);
            inFile >> patient.gender;
            inFile.ignore();
            patients.push_back(patient);
        }
        inFile.close();
        cout << "Patient data loaded from patients.txt" << endl;
    }else{
        cout << "Error opening patients.txt for reading." << endl;
    }
}

void Hospital::loadAppointmentDataFromFile(){
    ifstream inFile("appointments.txt");
    if (inFile.is_open()){
        appointments.clear();
        Appointment appointment;
        while (getline(inFile, appointment.doctorName)){
            getline(inFile, appointment.patientName);
            getline(inFile, appointment.date);
            getline(inFile, appointment.time);
            appointments.push_back(appointment);
        }
        inFile.close();
        cout << "Appointment data loaded from appointments.txt" << endl;
    }else{
        cout << "Error opening appointments.txt for reading." << endl;
    }
}

void Hospital::savePatientDataToFile(){
    ofstream outFile("patients.txt");
    if (outFile.is_open()){
        outFile << count << endl;
        for (const Patient &patient : patients){
            outFile << patient.ID << endl;
            outFile << patient.firstName << endl;
            outFile << patient.lastName << endl;
            outFile << patient.age << endl;
            outFile << patient.blood << endl;
            outFile << patient.gender << endl;
            outFile << patient.medicalRecords.size() << endl;
            for (const MedicalRecord &record : patient.medicalRecords){
                outFile << record.diagnosis << endl;
                outFile << record.treatment << endl;
            }
        }
        outFile.close();
        cout << "Patient data saved to patients.txt" << endl;
    }else{
        cout << "Error opening patients.txt for writing." << endl;
    }
}

void Hospital::saveAppointmentDataToFile(){
    ofstream outFile("appointments.txt");
    if (outFile.is_open()){
        for (const Appointment &appointment : appointments){
            outFile << appointment.doctorName << endl;
            outFile << appointment.patientName << endl;
            outFile << appointment.date << endl;
            outFile << appointment.time << endl;
        }
        outFile.close();
        cout << "Appointment data saved to appointments.txt" << endl;
    }else{
        cout << "Error opening appointments.txt for writing." << endl;
    }
}

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

    patients.push_back(p);
    count++;
    savePatientDataToFile();
    cout << "Patient added successfully!\nPress 'Enter' to return to the Main Menu" << endl;
}

void Hospital::displayPatients(){
    cout << "List of patients:\n";
    cout << "========================================" << endl;
    for (int i = 0; i < count; i++){
        cout << "ID         : " << patients[i].ID << endl;
        cout << "Name       : " << patients[i].firstName << " " << patients[i].lastName << endl;
        cout << "Age        : " << patients[i].age << endl;
        cout << "Blood Group: " << patients[i].blood << endl;
        cout << "Gender     : " << patients[i].gender << endl;
        cout << "========================================" << endl;
    }
    cout << "Press 'Enter' to return to the Main Menu" << endl;
    cin.ignore();
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
            savePatientDataToFile();
            return;
        }
    }
    cout << "Patient not found!\n";
}

void Hospital::displayAppointments(){
    cout << "List of appointments:\n";
    for (int i = 0; i < appointments.size(); i++){
        cout << "Doctor name : " << appointments[i].doctorName << endl;
        cout << "Patient name: " << appointments[i].patientName << endl;
        cout << "Date        : " << appointments[i].date << endl;
        cout << "Time        : " << appointments[i].time << endl;
        cout << "========================================" << endl;
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
                cout << "Diagnosis : " << patients[i].medicalRecords[j].diagnosis << endl;
                cout << "Treatment : " << patients[i].medicalRecords[j].treatment << endl;
                cout << "========================================" << endl;
            }
            return;
        }
    }
    cout << "Patient not found!\n";
}

void Hospital::scheduleAppointment()
{
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
    saveAppointmentDataToFile();
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
                cout << "========================================" << endl;
            }
            return;
        }
    }
    cout << "Patient not found!\n";
}

int main(){
    Hospital hospital;
    hospital.loadUserFromFile();
    hospital.loadPatientDataFromFile();
    hospital.loadAppointmentDataFromFile();
    while (true){
        clearScreen();
        auth:
        cout << "Hospital Management System" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore();
        switch (choice){
        case 1:
            hospital.registerUser();
            break;

        case 2:
            if (hospital.loginUser()){
                while (true){
                    clearScreen();
                    cout << "Hospital Management System" << endl;
                    cout << "1. Add Patient" << endl;
                    cout << "2. Schedule Appointment" << endl;
                    cout << "3. Display Appointments" << endl;
                    cout << "4. Display Patients" << endl;
                    cout << "5. Add Medical Record" << endl;
                    cout << "6. Display Medical Record" << endl;
                    cout << "7. Generate Report" << endl;
                    cout << "8. Logout" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice;
                    cin.ignore();

                    switch (choice){
                    case 1:
                        hospital.addPatient();
                        break;

                    case 2:
                        hospital.scheduleAppointment();
                        break;

                    case 3:
                        hospital.displayAppointments();
                        break;

                    case 4:
                        hospital.displayPatients();
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
                        clearScreen();
                        cout << "Logged out successfully!" << endl;
                        hospital.savePatientDataToFile();
                        hospital.saveAppointmentDataToFile();
                        goto auth;
                        break;

                    default:
                        cout << "Invalid choice. Please try again." << endl;
                        break;
                    }
                }
            }
            break;

        case 3:
            cout << "Goodbye!" << endl;
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
    return 0;
}
