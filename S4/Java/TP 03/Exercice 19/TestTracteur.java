public class TestTracteur{
	public void main(){
	//q2
	Roue r1 = new Roue(120);
	Roue r2 = new Roue(120);
	Roue r3 = new Roue();
	Roue r4 = new Roue();
	System.out.println(r1.toString());
	
	//q3
	Cabine c1 = new Cabine(3, "bleue");
	Tracteur t1 = new Tracteur(c1, r1, r2, r3, r4);
	System.out.println(t1.toString());
	Tracteur t2 = t1;
	t2.peindre("rouge");
	System.out.println(t1.toString());
	}
}
