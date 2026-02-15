
public class TestPersonne {
    public void main(){
        Personne p1 = new Personne('A');
        Personne p2 = new Personne('B');
        Personne p3 = new Personne('C');
        p1.epouser(p2);
        System.out.println(p1 + ", " + p2 + ", " + p3);
        p1.epouser(p3);
        System.out.println(p1 + ", " + p2 + ", " + p3);
        p3.epouser(p1);
        System.out.println(p1 + ", " + p2 + ", " + p3);
        p3.epouser(p3);
        System.out.println(p1 + ", " + p2 + ", " + p3);
        p1.divorcer();
        System.out.println(p1 + ", " + p2 + ", " + p3);
        p3.divorcer();
        System.out.println(p1 + ", " + p2 + ", " + p3);
    }    
}
