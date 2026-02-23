public class TestProjet{
	public void main(){
		System.out.println("nbPersonnes=" + Personne.getNbPersonnes());
		Personne p1 = new Personne();
		Personne p2 = new Personne();
		System.out.println(p1.toString() + " " + p2.toString());
		System.out.println("nbPersonnes=" + Personne.getNbPersonnes());
	}
}
