#include<iostream>
#include <thread>

using namespace std;

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
void pause(int seconds) {
    this_thread::sleep_for(chrono::seconds(seconds));
}
void pauseMili(int milliseconds) {
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

void clearScreen(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
int main(){
    const char* colors[] = {
    "color 1F", "color 2F", "color 3F", "color 4F", "color 5F", "color 6F", "color 7F",
    "color 8F", "color 9F", "color AF", "color BF", "color CF", "color DF", "color EF", "color FF",
    "color FF", "color EF", "color DF", "color CF", "color BF", "color AF", "color 9F", "color 8F",
    "color 7F", "color 6F", "color 5F", "color 4F", "color 3F", "color 2F", "color 1F", "color 0F", 
    "color 0B"
    };
    for(auto color:colors){
        clearScreen();
        system(color);
        cout << "\t\tBANGLADESH ARMY UNIVERSITY OF SCIENCE AND TECHNOLOGY\n";
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout << "Department : Computer Science and Technology\n";
        cout << "NAHID HASAN ARIF & AL MUSTAVIS AHMED RIFAT\n";
        cout << "Project name: HOSPITAL MANAGEMENT SYSTEM\n";
        cout << "Using Language: C++(OOP)\n";
        cout << "Project made by application: VISUAL STUDIO CODE & MYSY2(MINGW64) COMPILER\n";
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        pauseMili(100);
    }
}