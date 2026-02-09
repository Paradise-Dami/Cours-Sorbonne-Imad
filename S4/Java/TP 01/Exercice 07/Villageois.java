public class Villageois {
    private String nom;
    private double poids;
    private boolean malade;
    private final int PoidsMax = 150;
    private final int PoidsMin = 50;

    public Villageois(String nomVillageois){
        nom = nomVillageois;
        if (Math.random() < 0.2){
            malade = true;
        }
        poids = Math.random()*(PoidsMax-PoidsMin)+PoidsMin;

    } 

    public double poidsSouleve(){
        if (malade){
            return poids/3;
        } else {
            return poids/4;
        }
    }

    public String toString(){
        String EstMalade = "non";
        if (malade){
            EstMalade = "oui";
        }
        return "villageois : " + nom 
        + ", poids : " + String.format("%.2f",poids) 
        + ", malade : " + EstMalade
        + ", peut soulever " + poidsSouleve();
    }
    public String getNom(){
        return nom;
    }
    public double getPoids(){
        return poids;
    }
    public boolean getMalade(){
        return malade;
    }
}
