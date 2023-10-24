#include <fstream>
#include <conio.h>
#include <string.h>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

struct User{
    string username;
    string password;
};

class book
{
    char book_number[30];
    char book_name[50];
    char author_name[20];
    int num_copies;
    vector<User>users;

public:
    void registerUser(){
        system("cls");
        User newUser;
        cout << "Registration Page" << endl;
        cout << "Enter a username: ";
        cin >> newUser.username;
        cout << "Enter a password: ";
        cin >> newUser.password;
        
        for (const User &user : users){
            if (user.username == newUser.username){
                cout << "Duplicate user.\n Any key to return" << endl;
                getchar();
                return;
            }
        }
        users.push_back(newUser);

        ofstream outFile("auth.txt", ios::app);
        if (outFile.is_open()){
            outFile << newUser.username << " " << newUser.password << endl;
            outFile.close();
            cout << "Registration successful!" << endl;
        }else{
            cout << "File load error" << endl;
        }
        cin.ignore();
        system("cls");
    }
    
    int loginUser(){
        system("cls");
        string username, password;
        cout << "Login Page" << endl;
        cout << "Enter your username: ";
        cin >> username;

        for (const User &user : users){
            if (user.username == username){
                cout << "Enter your password: ";
                cin >> password;
                return (user.password == password)?1:0;
            }
        }
        cout << "User not found. Login failed." << endl;
        getchar();
        return false;
    }

    void loadUserFromFile(){
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

    void get_book_details()
    {
        cout << "\nENTER DETAILS ABOUT BOOK U WANT TO PURCHASE\n";
        cout << "\nEnter The Book Number: ";
        cin >> book_number;
        cout << "\nEnter The Name of The Book: ";
        cin.ignore();
        cin.getline(book_name, 50);
        cout << "\nEnter The Author's Name: ";
        cin.ignore();
        cin.getline(author_name, 50);
        fflush(stdin);
        cout << "\nEnter No. Of Copies : ";
        cin >> num_copies;
    }

    void show_book()
    {
        cout << "\nBook Number: " << book_number;
        cout << "\nBook Name: " << book_name;
        cout << "\nAuthor's Name: " << author_name;
        cout << "\nCOPIES : " << num_copies;
    }
    void modify_book()
    {
        cout << "\nBook number : " << book_number;
        cout << "\nModify Book Name : ";
        cin.ignore();
        cin.getline(book_name, 50);
        cout << "\nModify Author's Name: ";
        cin.ignore();
        cin.getline(author_name, 50);
        fflush(stdin);
        cout << "\nEnter No. Of Copies : ";
        cin >> num_copies;
    }
    char *getbooknumber()
    {
        return book_number;
    }
    void report()
    {
        cout << book_number << setw(30) << book_name << setw(30) << author_name << setw(25) << num_copies << endl;
    }
};

fstream fp;
book bk;
void write_book()
{
    system("cls");
    int more_or_main;
    fp.open("book.dat", ios::out | ios::app);
    do
    {
        bk.get_book_details();
        fp.write((char *)&bk, sizeof(book));
        cout << "\nPress 1 to add more books.";
        cout << "\nPress 2 to return to main menu.\n";
        cout << "Enter: ";
        cin >> more_or_main;
    } while (more_or_main == 1);
    fp.close();
}

void display_a_book(char n[])
{
    system("cls");
    cout << "\nBOOK DETAILS\n";
    int check = 0;
    fp.open("book.dat", ios::in);
    while (fp.read((char *)&bk, sizeof(book)))
    {
        if (strcmpi(bk.getbooknumber(), n) == 0)
        {
            bk.show_book();
            check = 1;
        }
    }
    fp.close();
    if (check == 0)
        cout << "\n\nBook does not exist";
    getch();
}

void modify_book()
{
    system("cls");
    char n[20];
    int found = 0;
    cout << "\n\n\tMODIFY BOOK";
    cout << "\n\n\tEnter The book number: ";
    cin >> n;
    fp.open("book.dat", ios::in | ios::out);
    while (fp.read((char *)&bk, sizeof(book)) && found == 0)
    {
        if (strcmpi(bk.getbooknumber(), n) == 0)
        {
            bk.show_book();
            cout << "\nEnter The New Details of book" << endl;
            bk.modify_book();
            int pos = -1 * sizeof(bk);
            fp.seekp(pos, ios::cur);
            fp.write((char *)&bk, sizeof(book));
            cout << "\n\n\t Record Updated Successfully...";
            found = 1;
        }
    }
    fp.close();
    if (found == 0)
        cout << "\n\n Record Not Found ";
    getch();
}

void delete_book()
{
    system("cls");
    char n[20];
    int flag = 0;
    cout << "\n\n\n\tDELETE BOOK";
    cout << "\n\nEnter The Book's number You Want To Delete: ";
    cin >> n;
    fp.open("book.dat", ios::in | ios::out);
    fstream fp2;
    fp2.open("Temp.dat", ios::out);
    fp.seekg(0, ios::beg);
    while (fp.read((char *)&bk, sizeof(book)))
    {
        if (strcmpi(bk.getbooknumber(), n) != 0)
        {
            fp2.write((char *)&bk, sizeof(book));
        }
        else
            flag = 1;
    }
    fp2.close();
    fp.close();
    remove("book.dat");
    rename("Temp.dat", "book.dat");
    if (flag == 1)
        cout << "\n\n\tRecord Deleted ..";
    else
        cout << "\n\nRecord not found";
    getch(); // to wait for user input
}

void display_allb()
{
    system("cls");
    fp.open("book.dat", ios::in);
    if (!fp)
    {
        cout << "ERROR!!! FILE COULD NOT BE OPEN ";
        getch();
        return;
    }
    cout << "\n\n\t\t\t\t\tBook LIST\n\n";
    cout << "============================================================================================\n";
    cout << "Book Number" << setw(20) << "Book Name" << setw(25) << "Author" << setw(32) << "Copies" << endl;
    cout << "============================================================================================\n";
    while (fp.read((char *)&bk, sizeof(book)))
    {
        bk.report();
    }
    fp.close();
    getch();
}

void intro()
{

    system("color E"); // to get outputs in color
    system("cls");
    cout << "\t\t\t\tBANGLADESH ARMY UNIVERSITY OF SCIENCE AND TECHNOLOGY\t";
    cout << "\n\t\t\t\t\t\tproject number: 01";

    cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

    cout << "\nDepartment of Computer Science and Technology";
    cout << "\nGroup member's are---";
    cout << "\nMD EMAM MASUM & MD TANVIR HASAN PRIOM";
    cout << "\nProject name: BOOK SHOP MANAGEMENT SYSTEM";
    cout << "\nUsing Language: C++";
    cout << "\nProject made by application: Code::Blocks 20.03";
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
}

int main()
{
    bk.loadUserFromFile();
    while (true){
        interface:
        system("cls");
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
            bk.registerUser();
            break;

        case 2:
            if (bk.loginUser()){
                int option = 0;
                while(true)
                {
                    intro();

                    cout << "\n\t\tPress: 1 to TO ADD BOOKS";
                    cout << "\n\t\tPress: 2 to SHOW ALL BOOKS";
                    cout << "\n\t\tPress: 3 to CHECK AVAILABILITY";
                    cout << "\n\t\tPress: 4 to MODIFY BOOKS";
                    cout << "\n\t\tPress: 5 to DELETE BOOKS";
                    cout << "\n\t\tPress: 6 to Exit";
                    cout << "\n\t...............................................\n";
                    cout << "\n\t\tEnter your option: ";
                    cin >> option;
                    switch (option)
                    {
                    case 1:
                        system("cls");
                        write_book();
                        break;
                    case 2:
                        display_allb();
                        break;
                    case 3:
                        char num[30];
                        system("cls");
                        cout << "\n\n\tPlease Enter The book No. ";
                        cin >> num;
                        display_a_book(num);
                        break;
                    case 4:
                        modify_book();
                        break;
                    case 5:
                        delete_book();
                        break;
                    case 6:
                        goto interface;
                        break;
                    default:
                        cout << "\a";
                    }
                }
            }
            break;
        default:
            cout<<"End!\n";
            return 0;
        }
    }
}