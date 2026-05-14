public class TestSimulation {
    public static void main(String[] args) {
        ExceptionManager em = new ExceptionManager();
        int scenario = 1;

        try {
            if (args.length > 0) {
                scenario = Integer.parseInt(args[0]);
            }
        } catch (NumberFormatException e) {
            em.gererInattendue(e);
        }

        Simulation sim = Simulation.getInstance();
        sim.initialiser(scenario);

        int nbEtapesMax = 30;
        int etape = 0;

        while (etape < nbEtapesMax && !sim.estTerminee()) {
            sim.etape();
            etape++;
        }

        if (sim.estTerminee()) {
            System.out.println("\n=== Simulation terminée ===");
        } else {
            System.out.println("\n=== Nombre max d'étapes atteint ===");
        }
    }
}
