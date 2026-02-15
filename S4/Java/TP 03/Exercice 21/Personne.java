public class Personne {
    private char nom;
    private Personne conjoint = null;

    public Personne(char nom){
        this.nom = nom;
    }
    public Personne(){
        char lettreNom = (char)((Math.random()*(90-65 + 1)) + 65);
        this(lettreNom);
    }
    public String toString(){
        String status;
        if (this.conjoint != null){
            status = ", marié(e)";
        } else {
            status = ", célibataire";
        }
        return "Pers" + this.nom + status;
    }
    public void epouser(Personne p){
        if ((this.conjoint != null) | (p.conjoint != null) | (p.nom == this.nom)){
            System.out.println("Le mariage de " + this.toString() +
            " avec " + p.toString() +
            " est impossible");
            return;
        }
        System.out.println(this + ", se marie avec " + p);
        this.conjoint = p;
        p.conjoint = this;
        return;
    }
    public void divorcer(){
        if (this.conjoint == null){
            System.out.println("Divorce impossible, aucun conjoint");
            return;
        }
        System.out.println(this + " divorce " + this.conjoint);
        this.conjoint.conjoint = null;
        this.conjoint = null;
        return;
    }
}