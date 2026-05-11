import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class ExceptionManager {

    public static class EntreeErreur {
        public final int etape;
        public final SimulationException.Code code;
        public final String message;
        public final boolean fatale;

        public EntreeErreur(int etape, SimulationException.Code code, String message, boolean fatale) {
            this.etape   = etape;
            this.code    = code;
            this.message = message;
            this.fatale  = fatale;
        }

        public String toString() {
            return String.format("[Etape %d | %s | %s] %s",
                etape, fatale ? "FATAL" : "WARN", code, message);
        }
    }

    // ---------- état interne ----------

    private final List<EntreeErreur> historique = new ArrayList<>();
    private int etapeCourante = 0;

    // ---------- API publique ----------

    /** Permet à la simulation de signaler le numéro d'étape courant. */
    public void setEtape(int etape) {
        this.etapeCourante = etape;
    }

    /**
     * Traite une SimulationException.
     * Certains codes sont considérés fatals (l'appelant doit arrêter la simulation),
     * d'autres sont simplement loggués comme avertissements.
     *
     * @param e l'exception à traiter
     * @return true si l'erreur est fatale, false si elle est récupérable
     */
    public boolean gerer(SimulationException e) {
        boolean fatale = estFatale(e.getCode());
        EntreeErreur entree = new EntreeErreur(etapeCourante, e.getCode(), e.getMessage(), fatale);
        historique.add(entree);

        if (fatale) {
            System.err.println("[ERREUR FATALE] " + entree);
        } else {
            System.out.println("[AVERTISSEMENT] " + entree);
        }
        return fatale;
    }

    /**
     * Traite une exception inattendue (non-SimulationException).
     * Toujours considérée comme fatale.
     *
     * @param e l'exception inattendue
     * @return true (toujours fatal)
     */
    public boolean gererInattendue(Exception e) {
        SimulationException wrapped = new SimulationException(
            SimulationException.Code.SCENARIO_INCONNU,
            "Exception inattendue : " + e.getMessage(),
            e
        );
        return gerer(wrapped);
    }

    /**
     * Retourne l'historique complet des erreurs (non modifiable).
     */
    public List<EntreeErreur> getHistorique() {
        return Collections.unmodifiableList(historique);
    }

    /** Retourne le nombre total d'erreurs enregistrées. */
    public int getNbErreurs() {
        return historique.size();
    }

    /** Retourne le nombre d'erreurs fatales enregistrées. */
    public int getNbErreursFatales() {
        int count = 0;
        for (EntreeErreur e : historique) {
            if (e.fatale) count++;
        }
        return count;
    }

    /** Affiche un résumé de toutes les erreurs survenues. */
    public void afficherResume() {
        System.out.println("\n=== Résumé des erreurs ===");
        if (historique.isEmpty()) {
            System.out.println("  Aucune erreur enregistrée.");
            return;
        }
        for (EntreeErreur e : historique) {
            System.out.println("  " + e);
        }
        System.out.println("  Total : " + getNbErreurs() + " erreur(s) dont "
                           + getNbErreursFatales() + " fatale(s).");
    }

    // ---------- logique interne ----------

    /**
     * Détermine si un code d'erreur est fatal.
     * Les erreurs de position/index sont fatales ; les erreurs de quantité ou de copie
     * sont récupérables (on ignore l'opération et on continue).
     */
    private boolean estFatale(SimulationException.Code code) {
        switch (code) {
            case POSITION_INVALIDE:
            case CASE_OCCUPEE:
            case SCENARIO_INCONNU:
                return true;
            case BANC_INEXISTANT:
            case NOURRITURE_INEXISTANTE:
            case QUANTITE_NEGATIVE:
            case COPIE_NULL:
            default:
                return false;
        }
    }
}
