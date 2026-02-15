public class Pile {
    private int nbA = 0;
    private Assiette[] tabAssiette;

    public Pile(int tailleMax){
        tabAssiette = new Assiette[tailleMax];
    }
    public boolean estVide(){
        return (nbA==0);
    }
    public boolean estPleine(){
        return nbA==tabAssiette.length;
    }    
    public void empiler(Assiette a){
        tabAssiette[nbA] = a;
        nbA+=1;
    }
    public Assiette depiler(){
        Assiette temp = tabAssiette[nbA]; 
        tabAssiette[nbA] = null;
        nbA-=1;
        return temp;
    }

    public String toString(){
        String res = "";
        for (int i = 0; i < nbA; i++){
            res += this.tabAssiette[i].toString();
        }
        return res;
    }
}
