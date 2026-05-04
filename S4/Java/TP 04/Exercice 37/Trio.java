public class Trio{
	private int numero;
	private static int compteur = 0;
	private Personne[] tabPersonne;
	public Trio(){
		tabPersonne = new Personne[3];
		for (int i = 0; i < tabPersonne.length; i++){
			tabPersonne[i] = new Personne();
		}
		compteur++;
		numero = compteur;
	}
	public String toString(){
		String out = "Trio " + numero + " :";
		for (int i = 0; i<tabPersonne.length; i++){
			out = out + " " + tabPersonne[i].toString();
		}
	}
}
