public class TestPile{
	public void main(){
	Pile p = new Pile(3);
	p.empiler(new Assiette());
	p.empiler(new Assiette(1));
	p.empiler(new Assiette(12));
	System.out.println(p.toString());
	p.depiler();
	p.depiler();
	System.out.println(p.toString());
	p.empiler(new Assiette(3));
	System.out.println(p.toString());
	p.empiler(new Assiette(15));
	System.out.println(p.toString());
	p.depiler();
	p.depiler();
	System.out.println(p.depiler());
	p.depiler();
	System.out.println(p.toString());
	}
}
