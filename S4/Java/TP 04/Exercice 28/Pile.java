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
	if (this.estVide()){
	   return false;
	}
        return nbA==tabAssiette.length;
    }
    public void empiler(Assiette a){
        if (this.estPleine()){
	   return;
	}
	tabAssiette[nbA] = a;
        nbA+=1;
    }
    public Assiette depiler(){
	if (nbA==0){
	   return null;
	}
        Assiette temp = new Assiette(tabAssiette[nbA-1].getDiametre());
        tabAssiette[nbA-1] = null;
        nbA = nbA - 1;
        return temp;
    }

    public String toString(){
        String res = "";
	if (nbA==0){
	    return "";
	}
        for (int i = 0; i < nbA; i++){
            res += this.tabAssiette[i].toString() + " ";
        }
        return res;
    }
}
