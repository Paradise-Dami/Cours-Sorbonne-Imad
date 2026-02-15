public class VectN {
    int[] vect;
    private VectN(int n){
        this.vect = new int[n];
    }
    public VectN(int n, int valMax){
        this.vect = new int[n];
        for (int i = 0; i < this.vect.length; i++){
            vect[i] = (int)(Math.random()*(valMax + 1));
        }
    }
    public VectN(){
        this(5,9);
    }
    public VectN(int a, int b, int c){
        this.vect = new int[]{a,b,c};
    }

    public int somme(){
        int resultat = 0;
        for (int x: this.vect){
            resultat = resultat + x;
        }
        return resultat;
    }

    public String toString() {
        if (this.vect.length==0) return "[]";
        String s = "[";
        for (int i = 0 ; i < (this.vect.length-1) ; i++) {
            s=s+this.vect[i]+",";
        }
        s=s+this.vect[this.vect.length-1] ;
        return s+"]";
    }

    public int[] getTab() {
        return this.vect;
    }
    public int[] getTabCorr(){
        VectN VectCopy = new VectN(this.vect.length);
        for (int i = 0 ; i < (VectCopy.vect.length) ; i++){
            VectCopy.vect[i] = this.vect[i]; 
        }
        return VectCopy.vect;
    }
}
