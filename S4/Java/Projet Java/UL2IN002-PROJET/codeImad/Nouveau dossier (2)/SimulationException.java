/**
 * Exception personnalisée pour la simulation marine.
 * Hérite de Exception (exception vérifiée).
 */
public class SimulationException extends Exception {

    /**
     * Codes d'erreur sémantiques pour identifier la cause de l'exception.
     */
    public enum Code {
        POSITION_INVALIDE,      // coordonnées hors du terrain
        CASE_OCCUPEE,           // tentative d'écriture sur une case non vide
        BANC_INEXISTANT,        // indice de banc hors limites
        NOURRITURE_INEXISTANTE, // indice de nourriture hors limites
        QUANTITE_NEGATIVE,      // quantité invalide (≤ 0)
        COPIE_NULL,             // tentative de copie d'un objet null
        SCENARIO_INCONNU        // numéro de scénario non géré
    }

    private final Code code;

    /**
     * @param code    code d'erreur identifiant la cause
     * @param message description lisible de l'erreur
     */
    public SimulationException(Code code, String message) {
        super(message);
        this.code = code;
    }

    /**
     * @param code    code d'erreur identifiant la cause
     * @param message description lisible de l'erreur
     * @param cause   exception d'origine (chaînage)
     */
    public SimulationException(Code code, String message, Throwable cause) {
        super(message, cause);
        this.code = code;
    }

    /** Retourne le code d'erreur de cette exception. */
    public Code getCode() {
        return code;
    }

    @Override
    public String toString() {
        return "[SimulationException|" + code + "] " + getMessage();
    }
}
