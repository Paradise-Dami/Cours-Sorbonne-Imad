public class TestLettre {
    private int skew = 97;
    public void main() {
        for (char lettre = 'a'; (int)lettre <= (int)'z'; lettre = (char)((int)lettre + 1)){
            Lettre l = new Lettre(lettre);
            if ((((int)lettre) - skew )%5 == 0){
                System.out.println();
            }
            System.out.print(l.getCarac() + " ");
        }
    }    
}
