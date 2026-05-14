import java.util.ArrayList;

public class RequinManager {
    private Terrain terrain;
    private ArrayList<Requin> requins = new ArrayList<>();

    public RequinManager(Terrain terrain) {
        this.terrain = terrain;
    }

    public void creerRequin(int ligne, int colonne) {
        Requin requin = new Requin();
        terrain.setCase(ligne, colonne, requin);
        requins.add(requin);
    }

    public void agir(PoissonManager pm) {
        for (Requin requin : requins) {
            for (int i = 0; i < pm.getBancs().size(); i++) {
                BancPoissons banc = pm.getBancs().get(i);
                if (!terrain.sontValides(banc.getLigne(), banc.getColonne())) continue;
                int dLigne = Math.abs(banc.getLigne() - requin.getLigne());
                int dCol = Math.abs(banc.getColonne() - requin.getColonne());
                if (dLigne <= 1 && dCol <= 1) {
                    pm.loseMembers(1, i);
                    System.out.println("  [REQUIN] mange un poisson du banc en (" + banc.getLigne() + "," + banc.getColonne() + ")");
                }
            }
        }
    }

    public ArrayList<Requin> getRequins() { return requins; }
}