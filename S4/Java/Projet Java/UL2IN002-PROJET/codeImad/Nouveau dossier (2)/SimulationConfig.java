/**
 * Classe de configuration globale de la simulation.
 * Contient uniquement des attributs statiques (constantes).
 * Ne peut pas être instanciée.
 */
public final class SimulationConfig {

    // Dimensions du terrain
    public static final int TERRAIN_LIGNES    = 10;
    public static final int TERRAIN_COLONNES  = 10;

    // Limites de la simulation
    public static final int NB_ETAPES_MAX     = 30;

    // Paramètres des bancs de poissons
    public static final int TAILLE_BANC_MIN   = 1;
    public static final int TAILLE_BANC_MAX   = 20;
    public static final int SEUIL_BANC_VIDE   = 0;

    // Paramètres de la nourriture
    public static final int NOURRITURE_MIN    = 1;
    public static final int NOURRITURE_MAX    = 10;

    // Paramètres des requins
    public static final int PORTEE_REQUIN     = 1;   // distance de chasse (cases adjacentes)
    public static final int DEGATS_REQUIN     = 1;   // poissons mangés par attaque

    // Messages système
    public static final String MSG_FIN_BANCS  = "Tous les bancs de poissons ont disparu.";
    public static final String MSG_ETAPES_MAX = "Nombre maximum d'étapes atteint.";

    // Constructeur privé : cette classe ne doit pas être instanciée
    private SimulationConfig() {
        throw new UnsupportedOperationException("SimulationConfig est une classe utilitaire statique.");
    }
}
