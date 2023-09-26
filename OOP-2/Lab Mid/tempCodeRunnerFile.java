class Grandparent{
    int i=5;
    Grandparent(){
        System.out.println(i+". Grandparent class's constructor");
    }

    
    void display(){
        System.out.println("Display Grandparent class");
    }
}

class Parent extends Grandparent{
    Parent(){
        System.out.println(i+". Parent class's constructor");
    }


    void display(){
        System.out.println("Display Parent class");
    }
}