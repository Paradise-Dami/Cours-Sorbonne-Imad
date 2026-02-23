public class Personne{
	private final String nom;
	private static int nbPersonnes = 0;
	private static char lettre = 'A';

	public Personne(){
		this.nom = "Individu" + lettre;
		nbPersonnes++;
		lettre++;
	}
	public static int getNbPersonnes(){
		return nbPersonnes;
	}
	public String toString(){
		return this.nom;
	}
}
