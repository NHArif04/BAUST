package same;

import different.Different;

public class Same extends Different{
    private void sShow1(){
        System.out.println("Private Same1");
    }

    protected void sShow2(){
        System.out.println("Protected Same1");
    }

    public void sShow3(){
        System.out.println("Public Same1");
    }
}
