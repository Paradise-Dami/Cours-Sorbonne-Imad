public class simulationManager {
    private static simulationManager instance = null;

    private Terrain terrain;
    private poissonManager pm;
    private nourritureManager nm;
    private int etape;

    private simulationManager() {
        terrain = new Terrain(10, 10);
        pm = new poissonManager(terrain);
        nm = new nourritureManager(terrain);
        etape = 0;
    }

    public static simulationManager getInstance() {
        if (instance == null) {
            instance = new simulationManager();
        }
        return instance;
    }

    public void initialiser(int scenario) {
    switch (scenario) {
        case 1:
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
            System.out.println("Scénario inconnu, utilisation du scénario 1");
            initialiser(1);
            break;
    }
}

    public void etape() {
        etape++;
        System.out.println("\n=== Etape " + etape + " ===");
        terrain.afficher(10);
        
        for (int i = 0; i < pm.getBancs().size(); i++) {
            pm.moveVersNourriture(i, nm);
        }
    
        for (int i = 0; i < pm.getBancs().size(); i++) {
            Ressource banc = pm.getBancs().get(i);
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