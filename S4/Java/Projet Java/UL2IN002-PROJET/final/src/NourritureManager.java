import java.util.ArrayList;

public class NourritureManager {
    private Terrain terrain;
    private ArrayList<Ressource> pointsNourriture = new ArrayList<>();
    private ExceptionManager em = new ExceptionManager();

    public NourritureManager(Terrain terrain) {
        this.terrain = terrain;
    }

    public void creerNourriture(int quantite, int ligne, int colonne) {
        try {
            if (!terrain.sontValides(ligne, colonne))
                throw new SimulationException("Position invalide (" + ligne + "," + colonne + ") pour la nourriture.");
            if (quantite <= 0)
                throw new SimulationException("Quantite de nourriture invalide : " + quantite);
            Ressource nourriture = new Ressource("Nourriture", quantite);
            terrain.setCase(ligne, colonne, nourriture);
            pointsNourriture.add(nourriture);
        } catch (SimulationException e) {
            em.gerer(e);
        }
    }

    public ArrayList<Ressource> getNourriture() {
        return pointsNourriture;
    }

    public void consommer(int numNourriture, int quantiteConsommee) {
        try {
            if (numNourriture < 0 || numNourriture >= pointsNourriture.size())
                throw new SimulationException("Indice de nourriture invalide : " + numNourriture);
            if (quantiteConsommee <= 0)
                throw new SimulationException("Quantite consommee invalide : " + quantiteConsommee);
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
        } catch (SimulationException e) {
            em.gerer(e);
        }
    }
}
