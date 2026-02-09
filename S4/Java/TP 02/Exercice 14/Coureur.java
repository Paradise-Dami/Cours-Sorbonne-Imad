public class Coureur {
    private int numDossard;
    private double tempsAu100;
    private boolean possedeTemoin;
    private int MAX = 16;
    private int MIN = 12;

    public Coureur(int numDossard, double tempsAu100, boolean possedeTemoin){
        this.numDossard = numDossard;
        this.tempsAu100 = tempsAu100;
        this.possedeTemoin = possedeTemoin;
    }
    public Coureur(int numDossard){
        this.numDossard = numDossard;
        this.tempsAu100 = Math.random()*(MAX-MIN)+MIN;
        this.possedeTemoin = false;
    }
    public Coureur(){
        int MAX_NUM_DOSSARD = 1000;
        int MIN_NUM_DOSSARD = 10;
        int numD = (int)Math.random()*(MAX_NUM_DOSSARD-MIN_NUM_DOSSARD+1)+MIN_NUM_DOSSARD; 
        this(numD);
    }
    public int getNumDossard(){
        return this.numDossard;
    }
    public double getTempsAu100(){
        return this.tempsAu100;
    }
    public boolean getPossedeTemoin(){
        return this.possedeTemoin;
    }
    public void setPossedeTemoin(boolean possedeTemoin){
        this.possedeTemoin = possedeTemoin;
    }
    public String toString(){
        String ouiNon = "non";
        if (this.possedeTemoin){
            ouiNon = "oui";
        }
        return "Coureur " +
        this.numDossard +
        " tempsAu100 : " +
        String.format("%.2f", this.tempsAu100) +
        "s au 100m possedeTemoin : " +
        ouiNon;
    }
    public void passeTemoin(Coureur c){
        if (!this.getPossedeTemoin()){
            System.out.println("Erreur, le passeur n'a pas le Témoin");
            return;
        }
        c.setPossedeTemoin(true);
        this.setPossedeTemoin(false);
        System.out.println("moi, coureur " +
        this.numDossard +
        ", je passe le témoin au coureur " +
        c.getNumDossard());
        return;
    }
    public void courir(){
        System.out.println("je suis le coureur " +
        this.numDossard +
        " et je cours");
    }
}