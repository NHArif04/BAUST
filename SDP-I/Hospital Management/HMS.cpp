#include <iostream>
#include <vector>       // to use built-in stl->vector
#include <fstream>      // to work with files
#include <string>       // to use built in string method
#include <cstdlib>      // to use function like clear screen
#include <thread>       // to add waiting time

using namespace std;

// Function to clear the screen based on the operating system
void clearScreen(){                 //return_type function_name (parameter){ body }
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Function to sleep few seconds
void pause(int seconds) {
    this_thread::sleep_for(chrono::seconds(seconds));           //namespace, scope resolution->::
}

void pauseMili(int milliseconds) {
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

void redirect(int seconds){
    for(int i=seconds; i>=0; i--){
        clearScreen();
        cout<<"Please wait "<<i<<" more seconds to redirect to the page.";
        pause(1);
    }
}

struct User{                        //user define data type ->   User user;  int a;     => user.username = "Rifat"
    string username;
    string password;
};

struct Appointment{                  //user define data type ->   Appointment appoint;  int a;
    string doctorName;
    string patientName;
    string date;
    string time;
};

struct MedicalRecord{                               //MedicalRecord record;  record.diagnosis="value";
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
    vector<MedicalRecord> medicalRecords;                   //medicalRecords.pushback(record)
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
    void addPatient();
    void savePatientDataToFile();
    void displayPatients();
    void loadPatientDataFromFile();
    void scheduleAppointment();
    void saveAppointmentDataToFile();
    void displayAppointments();
    void loadAppointmentDataFromFile();
    void addMedicalRecord();
    void displayMedicalRecord();
    void saveMedicalRecordToFile();
    void loadMedicalRecordFromFile();
    void modifyPatientInformation();
    void generateReport();
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
            cout << "Username already exists. Registration failed.\nPress any key to return." << endl;
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
    redirect(2);
    cin.ignore();
    clearScreen();
}

bool Hospital::loginUser(){
    clearScreen();
    string username, password;
    cout << "Login Page" << endl;
    cout << "Enter your username: ";
    cin >> username;

    for (const User &user : users){
        if (user.username == username){
            cout << "Enter your password: ";
            cin >> password;

            if (user.password == password){
                cout << "Login successful!\n" << endl;
                pause(1);
                redirect(2);
                return true;
            }else{
                cout << "Incorrect password. Login failed.\n" << endl;
                redirect(2);
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
            getline(inFile, patient.age);
            getline(inFile, patient.blood);
            getline(inFile, patient.gender);
            patients.push_back(patient);
        }
        inFile.close();
        loadMedicalRecordFromFile();
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

void Hospital::loadMedicalRecordFromFile() {
    ifstream inFile("medical_records.txt");
    if (inFile.is_open()) {
        for (int i = 0; i < patients.size(); i++) {
            unsigned long long ID;
            int numRecords;
            inFile >> ID >> numRecords;
            for (int j = 0; j < numRecords; j++) {
                MedicalRecord record;
                inFile.ignore();
                getline(inFile, record.diagnosis);
                getline(inFile, record.treatment);
                patients[i].medicalRecords.push_back(record);
            }
        }
        inFile.close();
        cout << "Medical records data loaded from medical_records.txt" << endl;
    }
    else {
        cout << "Error opening medical_records.txt for reading." << endl;
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
            // outFile << patient.medicalRecords.size() << endl;
            // for (const MedicalRecord &record : patient.medicalRecords){
            //     outFile << record.diagnosis << endl;
            //     outFile << record.treatment << endl;
            // }
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

void Hospital::saveMedicalRecordToFile() {
    ofstream outFile("medical_records.txt");
    if (outFile.is_open()) {
        for (const Patient& patient : patients) {
            outFile << patient.ID << " " << patient.medicalRecords.size() << endl;
            for (const MedicalRecord& record : patient.medicalRecords) {
                outFile << record.diagnosis << endl;
                outFile << record.treatment << endl;
            }
        }
        outFile.close();
        cout << "Medical records data saved to medical_records.txt" << endl;
    }
    else {
        cout << "Error opening medical_records.txt for writing." << endl;
    }
}


void Hospital::addPatient(){
    clearScreen();

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
    getchar();
}


void Hospital::modifyPatientInformation() {
    long long ID;
    cout << "Enter patient ID to modify information: ";
    cin >> ID;

    for (int i = 0; i < patients.size(); i++) {
        if (patients[i].ID == ID) {
            modify:
            cout << "Modify Patient Information for ID: " << patients[i].ID << endl;
            cout << "1. Update Information" << endl;
            cout << "2. Delete Patient" << endl;
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            cin.ignore();
            
            if (choice == 1) {
                cout << "Enter First Name: ";
                cin >> patients[i].firstName;
                cout << "Enter Last Name: ";
                cin >> patients[i].lastName;
                cout << "Enter Age: ";
                cin >> patients[i].age;
                cout << "Enter Blood Group: ";
                cin >> patients[i].blood;
                cout << "Enter Gender (m/f): ";
                cin >> patients[i].gender;

                savePatientDataToFile();
                cout << "Patient information updated successfully!\n";
                pause(1);
            } else if (choice == 2) {
                patients.erase(patients.begin() + i);
                count--;
                savePatientDataToFile();
                cout << "Patient deleted successfully!\n";
                pause(1);
            } else {
                cout << "Invalid choice!\n";
                pause(1);
                clearScreen();
                goto modify;
            }
            return;
        }
    }
    cout << "Patient not found!\n";
}



void Hospital::displayPatients(){
    clearScreen();
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
    if(0 == count){
        cout<<"No patient to display\n\n";
    }
    cout << "Press 'Enter' to return to the Main Menu" << endl;
    cin.ignore();
}

void Hospital::addMedicalRecord(){
    clearScreen();
    long long ID;
    cout << "Enter patient ID: ";
    cin >> ID;

    for (int i = 0; i < patients.size(); i++){
        if (patients[i].ID == ID){
            MedicalRecord record;
            cout << "Enter diagnosis: ";
            cin >> record.diagnosis;
            cin.ignore();
            cout << "Enter treatment: ";
            cin >> record.treatment;
            cin.ignore();
            patients[i].medicalRecords.push_back(record);
            saveMedicalRecordToFile();
            cout << "Medical record added successfully!\n";
            pause(1);
            return;
        }
    }
    cout << "Patient not found!\n";
}

void Hospital::displayAppointments(){
    clearScreen();
    cout << "List of appointments:\n";
    for (int i = 0; i < appointments.size(); i++){
        cout << "Doctor name : " << appointments[i].doctorName << endl;
        cout << "Patient name: " << appointments[i].patientName << endl;
        cout << "Date        : " << appointments[i].date << endl;
        cout << "Time        : " << appointments[i].time << endl;
        cout << "========================================" << endl;
    }
    cout<<"Press 'Enter' to return.\n";
    getchar();
}

void Hospital::displayMedicalRecord(){
    clearScreen();
    long long ID;
    if(0 == count){
        cout<<"No patient has found!\n";
        return;
    }
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
            cout<<"Enter 'Enter' key to return\n";
            getchar();
            redirect(1);
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
    redirect(2);
}

void Hospital::generateReport(){
    clearScreen();
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
            cout<<"Press 'Enter' to return\n";
            getchar();
            return;
        }
    }
    cout << "Patient not found!\n";
}


/** 
16 color values (0 to F) map to the actual colors:

0: Black                    1: Blue 
2: Green                    3: Aqua
4: Red                      5: Purple
6: Yellow                   7: White
8: Gray                     9: Light Blue
A: Light Green              B: Light Aqua
C: Light Red                D: Light Purple
E: Light Yellow             F: Bright White

system("color XY");  //? X=>background, Y=>text color
**/

void intro(){
        const char* colors[] = {"color 7F", "color 37", "color 12", "color 01", "color 03", "color 0B"};
        for(auto color:colors){
        clearScreen();
        system(color);
        cout << "\t\tBANGLADESH ARMY UNIVERSITY OF SCIENCE AND TECHNOLOGY\n";
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "Department : Computer Science and Technology\n";
        cout << "NAHID HASAN ARIF & AL MUSAVVIR AHAMED RIFAT\n";
        cout << "Project name: HOSPITAL MANAGEMENT SYSTEM\n";
        cout << "Using Language: C++(OOP)\n";
        cout << "Project made by application: VISUAL STUDIO CODE & MYSY2(MINGW64) COMPILER\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        pauseMili(150);
    }
}


int main(){
    intro();
    pause(2);
    clearScreen();
    system("color 0B");
    Hospital hospital;
    hospital.loadUserFromFile();
    hospital.loadPatientDataFromFile();
    hospital.loadAppointmentDataFromFile();
    while (true){
        auth:
        clearScreen();
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
                    cout << "7. Modify Patient Information" << endl;
                    cout << "8. Generate Report" << endl;
                    cout << "9. Logout" << endl;
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
                        hospital.modifyPatientInformation();
                        break;

                    case 8:
                        hospital.generateReport();
                        break;

                    case 9:
                        clearScreen();
                        hospital.savePatientDataToFile();
                        hospital.saveAppointmentDataToFile();
                        cout << "Logged out successfully!\nEnter any key to return." << endl;
                        getchar();
                        redirect(2);
                        clearScreen();
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
            cout << "Program Terminated!" << endl;
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
    return 0;
}
