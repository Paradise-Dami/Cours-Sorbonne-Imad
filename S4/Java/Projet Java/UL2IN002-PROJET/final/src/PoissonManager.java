import java.util.ArrayList;

public class PoissonManager {
    private Terrain terrain;
    private ArrayList<BancPoissons> bancsPoissons = new ArrayList<>();
    private int killLoop = 0;
    private ExceptionManager em = new ExceptionManager();

    public PoissonManager(Terrain terrain) {
        this.terrain = terrain;
    }

    public void creerBanc(int taille, int ligne, int colonne) {
        try {
            if (!terrain.sontValides(ligne, colonne))
                throw new SimulationException("Position invalide (" + ligne + "," + colonne + ") pour le banc.");
            if (taille <= 0)
                throw new SimulationException("Taille de banc invalide : " + taille);
            BancPoissons banc = new BancPoissons(taille);
            terrain.setCase(ligne, colonne, banc);
            bancsPoissons.add(banc);
        } catch (SimulationException e) {
            em.gerer(e);
        }
    }

    public void moveBancAlea(int numBanc) {
        try {
            if (numBanc < 0 || numBanc >= bancsPoissons.size())
                throw new SimulationException("Indice de banc invalide : " + numBanc);
            Ressource banc = bancsPoissons.get(numBanc);
            int oldX = banc.getLigne();
            int oldY = banc.getColonne();
            int newX = oldX + (int)(Math.random() * 3) - 1;
            int newY = oldY + (int)(Math.random() * 3) - 1;
            if (terrain.sontValides(newX, newY) && terrain.caseEstVide(newX, newY)) {
                terrain.viderCase(oldX, oldY);
                terrain.setCase(newX, newY, banc);
                banc.setPosition(newX, newY);
            }
        } catch (SimulationException e) {
            em.gerer(e);
        }
    }

    public void loseMembers(int deaths, int numBanc) {
        try {
            if (numBanc < 0 || numBanc >= bancsPoissons.size())
                throw new SimulationException("Indice de banc invalide : " + numBanc);
            if (deaths <= 0)
                throw new SimulationException("Nombre de morts invalide : " + deaths);
            Ressource banc = bancsPoissons.get(numBanc);
            if ((banc.getQuantite() - deaths) <= 0) {
                int ligne = banc.getLigne();
                int col = banc.getColonne();
                banc.setQuantite(0);
                banc.resetPosition();
                if (terrain.sontValides(ligne, col)) {
                    terrain.viderCase(ligne, col);
                }
                bancsPoissons.remove(banc);
            } else {
                banc.setQuantite(banc.getQuantite() - deaths);
            }
        } catch (SimulationException e) {
            em.gerer(e);
        }
    }

    public void addMembers(int born, int numBanc) {
        try {
            if (numBanc < 0 || numBanc >= bancsPoissons.size())
                throw new SimulationException("Indice de banc invalide : " + numBanc);
            if (born <= 0)
                throw new SimulationException("Nombre de naissances invalide : " + born);
            Ressource banc = bancsPoissons.get(numBanc);
            banc.setQuantite(banc.getQuantite() + born);
        } catch (SimulationException e) {
            em.gerer(e);
        }
    }

    public void moveVersNourriture(int numBanc, NourritureManager nm) {
        try {
            if (numBanc < 0 || numBanc >= bancsPoissons.size())
                throw new SimulationException("Indice de banc invalide : " + numBanc);

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
                int bestX = -1, bestY = -1;
                double bestDist = Double.MAX_VALUE;

                for (int dl = -1; dl <= 1; dl++) {
                    for (int dc = -1; dc <= 1; dc++) {
                        if (dl != 0 || dc != 0) {
                            int nl = oldX + dl;
                            int nc = oldY + dc;
                            if (terrain.sontValides(nl, nc)) {
                                Ressource contenu = terrain.getCase(nl, nc);
                                if (contenu == null || contenu.type.equals("Nourriture")) {
                                    double d = Math.sqrt(Math.pow(cible.getLigne() - nl, 2) + Math.pow(cible.getColonne() - nc, 2));
                                    if (d < bestDist) {
                                        bestDist = d;
                                        bestX = nl;
                                        bestY = nc;
                                    }
                                }
                            }
                        }
                    }
                }

                if (bestX != -1) {
                    terrain.viderCase(oldX, oldY);
                    terrain.setCase(bestX, bestY, banc);
                    banc.setPosition(bestX, bestY);
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
        } catch (SimulationException e) {
            em.gerer(e);
        }
    }

    public ArrayList<BancPoissons> getBancs() {
        return bancsPoissons;
    }
}
