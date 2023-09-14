#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main(){
    int test, radiusTop, radiusBottom, heightGlass, heightJuice;
    cin>>test;
    for(int i=1; i<=test; i++){
        cin >>radiusTop>>radiusBottom>>heightGlass>>heightJuice;
        double juiceRadius = radiusBottom + (radiusTop-radiusBottom)*heightJuice/heightGlass;
        double volume = (acos(0.0)*heightJuice/3)*(pow(radiusTop,2)+pow(juiceRadius,2)+radiusTop*juiceRadius);
        cout<<"Case "<<i<<": "<<fixed<<setprecision(7)<<volume<<endl;
    }
    return 0;
}