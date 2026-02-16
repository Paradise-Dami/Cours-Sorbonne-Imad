public class TestVectN {
    public void main(){
        VectN v1 = new VectN();
        VectN v2 = new VectN(7,19);
        VectN v3 = new VectN(1,2,3);
	VectN vect = new VectN(4,5,6);
	int[] t = vect.getTabCorr();
	System.out.println("vect="+vect);
	t[0]=100; // modif d'une valeur de t
	System.out.println("vect="+vect);
    }    
}
