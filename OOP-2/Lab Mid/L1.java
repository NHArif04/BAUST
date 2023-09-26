abstract class Grandparent{
    abstract void  display();
    void show(){
        System.out.println("Body thakte pare");
    }
}

class Parent extends Grandparent{
    Parent(){
        System.out.println(". Parent class's constructor");
    }


    void display(){
        System.out.println("Display Parent class");
    }
}


class Child extends Parent{
    Child(){
        System.out.println(". Child class's constructor");
    }

    // void display(){
    //     System.out.println("Display Child class");
    // }

//     void display(String name){
//         System.out.println("Display Child class overload");
//     }
}


class L1 {
    public static void main(String[] args) {
        Child obj = new Child();
        
        obj.display();










        /* for(int i=0; i<3; i++){
            switch(i){
                case 1: 
                    System.out.println("one");
                break;

                case 2:
                    System.out.println("two");
                break;

                default:
                    System.out.println("zero");
                break;
            }
        }

        int i=0;
        while(true){
            i++;
            if(i%2==0){ 
                continue;
            }
            if(i==11) break;
            
            System.out.println(i);
        }
 */
        /* 
         * Arithmetic Operators: binary(+, -, *, /, %), unary(++, --)=> a+b
        *   Relational Operators: binary(==, !=, >, <, >=, <=)
        *   Bitwise Operators: &, |, ^, ~, <<, >>, >>>
        *   Logical Operators: &&, ||, !
        *   Assignment Operators: =, +=, -= , *=, /=, %=, &=, |=, ^=, >>=, <<=
        *   Unary Operators: + (unary plus), - (unary minus), ++ (increment), -- (decrement), ! (logical complement)
        *   Ternary Operator: (boolean expression) ? expression1 : expression2
         */

        /* int a=5, b=6;
        if(!(a>5 && b>5)){  // !false=> true
            System.out.println("both are greater than 5");
        }else if(a>5 || b>5){  //true
            System.out.println("one of them are greater than 5");
        }
        int c = a&b; //101 & 110  => 100
        /* c=c<<(2);     // c-> 100<<(2)   => 10000 -> 
        System.out.println(c); */
        /* c=c>>(2);
        System.out.println(c); */

        /* int arr[][]=new int[3][];

        int array[]={1,2,3,4,5,6};

        for(int j=0; j<arr.length; j++){
            arr[j]=new int[j+1];
            for(int i)
        } */
    }

}
