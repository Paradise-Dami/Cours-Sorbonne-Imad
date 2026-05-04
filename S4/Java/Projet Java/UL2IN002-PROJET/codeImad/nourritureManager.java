import java.util.ArrayList;

public class nourritureManager {
    private Terrain terrain;
    private ArrayList<Ressource> pointsNourriture = new ArrayList<>();

    public nourritureManager(Terrain terrain) {
        this.terrain = terrain;
    }

    public void creerNourriture(int quantite, int ligne, int colonne) {
        Ressource nourriture = new Ressource("Nourriture", quantite);
        terrain.setCase(ligne, colonne, nourriture);
        pointsNourriture.add(nourriture);
    }

    public ArrayList<Ressource> getNourriture() {
        return pointsNourriture;
    }

    public void consommer(int numNourriture, int quantiteConsommee) {
        Ressource nourriture = pointsNourriture.get(numNourriture);
        int reste = nourriture.getQuantite() - quantiteConsommee;
        if (reste <= 0) {
            int ligne = nourriture.getLigne();
            int col = nourriture.getColonne();
            if (terrain.sontValides(ligne, col)) {
                terrain.viderCase(ligne, col);
            }
            nourriture.setQuantite(0);
            nourriture.resetPosition();
            pointsNourriture.remove(nourriture);
        } else {
            nourriture.setQuantite(reste);
        }
    }
}