# ***Readme file syntax:***
> **Bold** or __Bold__
> *Italic* or _Italic_
> **Bold -> _important_ <-Italic**


## ***C++ what need to learn*** 
<i>
* Preprocessor <br>
* Main() -> types <br>
* Namespaces -> use of it <br>
</i>
<br><br>

#### <b> Preprocessor </b> <br>
> #include preprocessor directives are 
<br></br>

#### <b> Main() </b> <br>
> Main() function is the entry point of a program. There can be several .cpp file but there is only one main function. Main() function can be define in two ways:

>***Normal function*** 
```C++
int main()
{
    .......
    .......
    return 0;
}
```
>***For command line application***  
```C++
int main(int argc, char *argv)
{
    .......
    .......
    return 0;
}
```
<br><br>

#### ***Variable***<br>
>A variable is an abstraction for memory location which allows programmers to use meaningful names instead of memory location.<br><br>
***Variable*** have 
<br>* Type -> (int, float, double, char, string, etc.),
<br>* Value -> (1, 2.45, 3.453235, 'a', "Nahid",..) which is change able.<br>
<br>Variable must be declared before they are being used.
<br>
```CPP
#include<iostream>
void main(){
    int a;
    a=10;
}
```

<br><br>
#### ***Namespaces***<br>
>Namespaces used to specify from where the function is being used to reduce the naming conflict. Below the #include directives are indicates from which namespace the function will be called. For example: 
```CPP
#include<iostream>
using std::cout;
int main(){
    cout << "Nahid" << endl;
    return 0;
}
```
>By this -> In **iostream** header file there is a namespace called std where the definition of cout is given we are using that *namespaces* cout() function.

<br><br>
## Input & Output Sample Code:
```C++
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    int a{};  //->initialize with zero a=0
    double d{1.5}; //->initialize with d=1.5
    cout<<a<<" "<<d<< endl;
    cin>>a>>d;  //->10.5 will be divide => a=10 b=0.5
    cout<<a<<" "<<d<< endl;
    return 0;
}
```
### Output:
```CMD
0 1.5
10.56
10 0.56
```