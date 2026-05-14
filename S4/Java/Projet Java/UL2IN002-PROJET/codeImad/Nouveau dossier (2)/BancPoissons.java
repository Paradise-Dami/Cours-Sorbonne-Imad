public class BancPoissons extends EntiteMarine {

    /**
     * Constructeur principal.
     * @param taille nombre de poissons dans le banc
     */
    public BancPoissons(int taille) {
        super("Poisson", taille);
    }

    /**
     * Constructeur de copie.
     * Crée un nouveau BancPoissons indépendant à partir d'un existant.
     * La position n'est PAS copiée : le clone doit être replacé manuellement sur le terrain.
     *
     * @param autre le BancPoissons à copier
     * @throws SimulationException si l'objet source est null
     */
    public BancPoissons(BancPoissons autre) throws SimulationException {
        super("Poisson", 0);
        if (autre == null) {
            throw new SimulationException(
                SimulationException.Code.COPIE_NULL,
                "Impossible de copier un BancPoissons null."
            );
        }
        this.setQuantite(autre.getQuantite());
        // La position n'est pas copiée volontairement :
        // deux entités ne peuvent pas occuper la même case.
    }
}
