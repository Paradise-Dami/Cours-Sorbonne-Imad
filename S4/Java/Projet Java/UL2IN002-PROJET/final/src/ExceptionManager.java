public class ExceptionManager {
    public void gerer(SimulationException e) {
        System.out.println("Erreur : " + e.getMessage());
    }

    public void gererInattendue(Exception e) {
        System.out.println("Erreur inattendue : " + e.getMessage());
    }
}
