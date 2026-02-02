public class TestComplexe{
	public void main(){
	Complexe i = new Complexe(0,1);
	Complexe z1 = new Complexe(1,0);
	Complexe z2 = new Complexe(3,2);
	Complexe z3 = new Complexe(2,3);

	//(3+2i)(2+3i) = 6 + 9i + 4i  - 6 = 13 ?

	System.out.println("i reel : " + i.estReel());
        System.out.println("i*i : " + i.toString());
	i.multiplication(i);
        System.out.println("i*i : " + i.toString());
        
	System.out.println("z1 reel : " + z1.estReel());
	z2.multiplication(z3);
	z1.multiplication(z3);
	System.out.println("on fait z2*z3 : " + z2.toString());
	System.out.println("on fait z1*z3 : " + z1.toString());
	z3.addition(z3);
	System.out.println("on fait z1 + z3 : " + 
	z3.toString());
}
}
