#include<iostream>
#include <cmath>
#include<iomanip>
using namespace std;

double areaTriangle(double a, double b, double c, double s);
double calculateArea(double R1, double R2, double R3);
double calcAngle(double a, double b, double c);
double calcAngle(double a, double b, double c);
double arcAreaCircle(double R, double theta);

int main(){
    int test;
    cin>>test;
    double result, radius1, radius2, radius3;
    for(int i=1; i<=test; i++){
        cin>>radius1>>radius2>>radius3;
        result = calculateArea(radius1,radius2,radius3);
        cout<<"Case "<<i<<": "<<fixed<<setprecision(10)<<result<<endl;
    }
    return 0;
}

double areaTriangle(double a, double b, double c, double s){
    return sqrt(s*(s-a)*(s-b)*(s-c));
}


double calcAngle(double a, double b, double c){
    return acos((a*a+b*b-c*c)/(2*a*b));
}

double arcAreaCircle(double R, double theta){
    return (theta*R*R/2);
}

double calculateArea(double R1, double R2, double R3) {
    double a =R1+R2;
    double b =R3+R2;
    double c =R1+R3;
    double angleA = calcAngle(b,c,a);
    double angleB = calcAngle(c,a,b);
    double angleC = calcAngle(a,b,c);
    double triangle = areaTriangle(a,b,c,(a+b+c)/2);
    double circleA = arcAreaCircle(R3, angleA);
    double circleB = arcAreaCircle(R2, angleC);
    double circleC = arcAreaCircle(R1, angleB);
    double circle = circleA+circleB+circleC;
    return (triangle-circle);
}
