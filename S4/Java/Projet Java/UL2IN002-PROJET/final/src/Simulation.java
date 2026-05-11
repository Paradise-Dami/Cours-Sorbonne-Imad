import java.util.Random;

public class Simulation {
    private static Simulation instance = null;

    private Terrain terrain;
    private PoissonManager pm;
    private NourritureManager nm;
    private int etape;
    private RequinManager rm;
    private ScenarioGenerator sg;
    private Random rand = new Random();
    private ExceptionManager em = new ExceptionManager();

    private Simulation() {
        terrain = new Terrain(10, 10);
        pm = new PoissonManager(terrain);
        nm = new NourritureManager(terrain);
        rm = new RequinManager(terrain);
        sg = new ScenarioGenerator(terrain, pm, nm, rm);
        etape = 0;
    }

    public static Simulation getInstance() {
        if (instance == null) {
            instance = new Simulation();
        }
        return instance;
    }

    public void initialiser(int scenario) {
        try {
            switch (scenario) {
                case 0:
                    int nbBancs = 2 + rand.nextInt(3);
                    int tailleBanc = 5 + rand.nextInt(10);
                    int nbNourritures = 2 + rand.nextInt(4);
                    int nbRequins = 1 + rand.nextInt(3);
                    int nbPiliers = 2 + rand.nextInt(5);
                    sg.generer(nbBancs, tailleBanc, nbNourritures, nbRequins, nbPiliers);
                    break;
                case 1:
                    Pilier p1 = new Pilier();
                    p1.setPosition(5, 5);
                    terrain.setCase(5, 5, p1);
                    rm.creerRequin(3, 3);
                    rm.creerRequin(7, 7);
                    nm.creerNourriture(3, 1, 1);
                    nm.creerNourriture(3, 1, 10);
                    nm.creerNourriture(3, 10, 5);
                    pm.creerBanc(10, 5, 1);
                    pm.creerBanc(8,  5, 10);
                    pm.creerBanc(6,  10, 1);
                    break;
                case 2:
                    nm.creerNourriture(5, 5, 5);
                    nm.creerNourriture(2, 1, 5);
                    nm.creerNourriture(2, 10, 5);
                    nm.creerNourriture(2, 5, 1);
                    pm.creerBanc(12, 1, 1);
                    pm.creerBanc(12, 1, 10);
                    pm.creerBanc(12, 10, 10);
                    break;
                case 3:
                    nm.creerNourriture(1, 5, 5);
                    pm.creerBanc(5, 1, 1);
                    pm.creerBanc(5, 1, 10);
                    pm.creerBanc(5, 10, 1);
                    pm.creerBanc(5, 10, 10);
                    break;
                case 4:
                    nm.creerNourriture(10, 2, 2);
                    nm.creerNourriture(10, 2, 8);
                    nm.creerNourriture(10, 8, 2);
                    nm.creerNourriture(10, 8, 8);
                    nm.creerNourriture(10, 5, 5);
                    pm.creerBanc(3, 1, 5);
                    pm.creerBanc(3, 10, 5);
                    break;
                case 5:
                    nm.creerNourriture(2, 5, 10);
                    pm.creerBanc(8, 5, 1);
                    pm.creerBanc(8, 5, 2);
                    pm.creerBanc(8, 5, 3);
                    break;
                default:
                    throw new SimulationException("Scénario inconnu : " + scenario);
            }
        } catch (SimulationException e) {
            em.gerer(e);
            initialiser(1);
        }
    }

    public void etape() {
        etape++;
        System.out.println("\n=== Etape " + etape + " ===");
        terrain.afficher(10);

        for (int i = 0; i < pm.getBancs().size(); i++) {
            pm.moveVersNourriture(i, nm);
            rm.agir(pm);
        }

        for (int i = 0; i < pm.getBancs().size(); i++) {
            BancPoissons banc = pm.getBancs().get(i);
            if (!terrain.sontValides(banc.getLigne(), banc.getColonne())) continue;
            for (int j = 0; j < nm.getNourriture().size(); j++) {
                Ressource nourriture = nm.getNourriture().get(j);
                int dLigne = Math.abs(banc.getLigne() - nourriture.getLigne());
                int dCol = Math.abs(banc.getColonne() - nourriture.getColonne());
                if (dLigne <= 1 && dCol <= 1) {
                    System.out.println("  " + banc.type + " mange près de (" + nourriture.getLigne() + "," + nourriture.getColonne() + ")");
                    nm.consommer(j, 1);
                    break;
                }
            }
        }
        System.out.println("Bancs : " + pm.getBancs().size() + " | Nourritures : " + nm.getNourriture().size());
    }

    public boolean estTerminee() {
        return pm.getBancs().isEmpty();
    }
}
