public class TestCoureur {
    public void main(){
        Coureur c1 = new Coureur();
        Coureur c2 = new Coureur(3);
        Coureur c3 = new Coureur(0, 0, false);
        Coureur c4 = new Coureur(300, 3.55, true);
	System.out.println(c1.getNumDossard());
	System.out.println(c2.getTempsAu100());
	System.out.println(c3.getPossedeTemoin());
	System.out.println(c4.toString());
	System.out.println(c4.getPossedeTemoin());
	c4.passeTemoin(c2);
	c2.courir();

	//question 6
	c1.courir();
	c2.courir();
	c3.courir();
	c4.courir();
	System.out.println(String.format("%.2f", c1.getTempsAu100() +
	c2.getTempsAu100() +
	c3.getTempsAu100() +
	c4.getTempsAu100()) +
	"est le temps pris pour les 4 coureurs sur 400m");
    }
}
