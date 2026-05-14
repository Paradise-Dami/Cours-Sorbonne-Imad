import java.util.Random;

public class ScenarioGenerator {
    private Terrain terrain;
    private PoissonManager pm;
    private NourritureManager nm;
    private RequinManager rm;
    private Random rand = new Random();

    public ScenarioGenerator(Terrain terrain, PoissonManager pm, NourritureManager nm, RequinManager rm) {
        this.terrain = terrain;
        this.pm = pm;
        this.nm = nm;
        this.rm = rm;
    }

    // Retourne true si la case est libre
    private boolean caseLibre(int ligne, int col) {
        return terrain.sontValides(ligne, col) && terrain.caseEstVide(ligne, col);
    }

    // Trouve une case libre aléatoire
    private int[] casealeatoire() {
        int ligne, col;
        do {
            ligne = 1 + rand.nextInt(terrain.nbLignes);
            col = 1 + rand.nextInt(terrain.nbColonnes);
        } while (!caseLibre(ligne, col));
        return new int[]{ligne, col};
    }

    public void generer(int nbBancs, int tailleBanc, int nbNourritures, int nbRequins, int nbPiliers) {
        // Placer les piliers
        for (int i = 0; i < nbPiliers; i++) {
            int[] pos = casealeatoire();
            Pilier p = new Pilier();
            terrain.setCase(pos[0], pos[1], p);
        }

        // Placer les nourritures
        for (int i = 0; i < nbNourritures; i++) {
            int[] pos = casealeatoire();
            nm.creerNourriture(1 + rand.nextInt(5), pos[0], pos[1]);
        }

        // Placer les requins
        for (int i = 0; i < nbRequins; i++) {
            int[] pos = casealeatoire();
            rm.creerRequin(pos[0], pos[1]);
        }

        // Placer les bancs
        for (int i = 0; i < nbBancs; i++) {
            int[] pos = casealeatoire();
            pm.creerBanc(tailleBanc, pos[0], pos[1]);
        }

        System.out.println("Scénario généré : " + nbBancs + " bancs, " + nbNourritures + " nourritures, " + nbRequins + " requins, " + nbPiliers + " piliers");
    }
}