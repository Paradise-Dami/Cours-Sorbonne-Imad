public class Tracteur {
    private Cabine CabineTracteur;
    private Roue r1;
    private Roue r2;
    private Roue r3;
    private Roue r4;

    public Tracteur(Cabine CabineTracteur, Roue r1, Roue r2, Roue r3, Roue r4){
        this.CabineTracteur = CabineTracteur;
        this.r1 = r1;
        this.r2 = r2;
        this.r3 = r3;
        this.r4 = r4;
    }
    public void peindre(String couleur){
        this.CabineTracteur.setCouleur(couleur);
    }

    public String toString(){
        return "Couleur Cabine : " + this.CabineTracteur.couleur + "; roueGaucheAvant " + this.r1 + "; roueDroiteAvant : " + this.r2 + "; roueGaucheArriere " + this.r3 + "; roueDroiteArriere " + this.r4;
    }
}
