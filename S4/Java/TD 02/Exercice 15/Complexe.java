public class Complexe {
    private double reelle;
    private double imag;


    public Complexe(double reelle, double imag){
        this.reelle = reelle;
        this.imag = imag;
    }
    public Complexe(){
        double MAX = -2;
        double MIN = 2;
        double Re = Math.random()*(MAX-MIN)+MIN;
        double Im = Math.random()*(MAX-MIN)+MIN;
        this(Re, Im);
    }

    public String toString(){
        return this.reelle + " + " + this.imag + "i";
    }

    public boolean estReel(){
        return (this.imag == 0);
    }

    public void addition(Complexe c){
        this.reelle = this.reelle + c.reelle;
        this.imag = this.imag + c.imag;
    }
    public void multiplication(Complexe c){
        double TEMP_REELLE;
	TEMP_REELLE = (this.reelle*c.reelle) - (this.imag*c.imag);
        this.imag = (this.reelle*c.imag) + (this.imag*c.reelle);
	this.reelle = TEMP_REELLE;
    }
}
