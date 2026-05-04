import java.util.ArrayList;

public class poissonManager {
    private Terrain terrain;
    private ArrayList<Ressource> bancsPoissons = new ArrayList<>();
    private int killLoop = 0;

    public poissonManager(Terrain terrain) {
        this.terrain = terrain;
    }

    public void creerBanc(int taille, int ligne, int colonne) {
        Ressource banc = new Ressource("Poisson", taille);
        terrain.setCase(ligne, colonne, banc);
        bancsPoissons.add(banc);
    }

    public void moveBancAlea(int numBanc){
        Ressource banc = bancsPoissons.get(numBanc);
        int oldX = banc.getLigne();
        int oldY = banc.getColonne();
        int newX = oldX + (int)(Math.random() * 3) - 1;
        int newY = oldY + (int)(Math.random() * 3) - 1;
        if (terrain.sontValides(newX,newY) && terrain.caseEstVide(newX, newY)){
            terrain.viderCase(oldX, oldY);
            terrain.setCase(newX, newY, banc);
            banc.setPosition(newX, newY);
        }
    }

    public void loseMembers(int deaths, int numBanc){
        Ressource banc = bancsPoissons.get(numBanc);
        if ((banc.getQuantite() - deaths) <= 0){
            int ligne = banc.getLigne();
            int col = banc.getColonne();
            banc.setQuantite(0);
            banc.resetPosition();
            terrain.viderCase(ligne, col);
            bancsPoissons.remove(banc);
        } else {
            banc.setQuantite(banc.getQuantite() - deaths);
        }
    }

    public void addMembers(int born, int numBanc){
        Ressource banc = bancsPoissons.get(numBanc);
        banc.setQuantite(banc.getQuantite() + born);
    }

    public void moveVersNourriture(int numBanc, nourritureManager nm) {
        ArrayList<Ressource> nourritures = nm.getNourriture();

        if (nourritures.isEmpty()) {
            moveBancAlea(numBanc);
        } else {
            Ressource banc = bancsPoissons.get(numBanc);

            Ressource cible = null;
            double minDist = Double.MAX_VALUE;
            for (Ressource n : nourritures) {
                double dist = Math.sqrt(Math.pow(n.getLigne() - banc.getLigne(), 2)
                                    + Math.pow(n.getColonne() - banc.getColonne(), 2));
                if (dist < minDist) {
                    minDist = dist;
                    cible = n;
                }
            }

            int oldX = banc.getLigne();
            int oldY = banc.getColonne();
            int dx = (int)Math.signum(cible.getLigne() - oldX);
            int dy = (int)Math.signum(cible.getColonne() - oldY);
            int newX = oldX + dx;
            int newY = oldY + dy;

            if (terrain.sontValides(newX, newY) &&
                terrain.caseEstVide(newX, newY)) {
                terrain.viderCase(oldX, oldY);
                terrain.setCase(newX, newY, banc);
                banc.setPosition(newX, newY);
            } else if (dx != 0 && terrain.sontValides(oldX + dx, oldY) &&
                terrain.caseEstVide(oldX + dx, oldY) ) {
                terrain.viderCase(oldX, oldY);
                terrain.setCase(oldX + dx, oldY, banc);
                banc.setPosition(oldX + dx, oldY);
            } else if (dy != 0 && terrain.sontValides(oldX, oldY + dy) &&
                terrain.caseEstVide(oldX, oldY + dy)) {
                terrain.viderCase(oldX, oldY);
                terrain.setCase(oldX, oldY + dy, banc);
                banc.setPosition(oldX, oldY + dy);
            }
        }

        if (killLoop == 1) {
            if (numBanc < bancsPoissons.size()) {
                loseMembers(1, numBanc);
            }
            killLoop = 0;
        } else {
            killLoop = 1;
        }
    }

    public ArrayList<Ressource> getBancs() {
        return bancsPoissons;
    }
}