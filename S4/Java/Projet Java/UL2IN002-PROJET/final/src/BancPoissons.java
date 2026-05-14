public class BancPoissons extends EntiteMarine {
    public BancPoissons(int taille) {
        super("Poisson", taille);
    }

    public BancPoissons(BancPoissons autre) {
        super("Poisson", autre.getQuantite());
    }
}
