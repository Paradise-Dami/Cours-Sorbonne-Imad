public class Cone{
	private double r;
	private double h;
	private static final double PI = 3.14159;
	private static int nbCones = 0;
	private final int MAX = 10;
	private final int MIN = 0;

	public Cone(double r, double h){
		this.r = r;
		this.h = h;
		nbCones++;
	}

	public Cone(){
		this.r = Math.random()*(MAX-MIN) + MIN;
		this.h = Math.random()*(MAX-MIN) + MIN;
		nbCones++;
	}

	public double getVolume(){
		return (1/3)*PI*r*r*h;
	}
	public String toString(){
		return String.format("Cone r=%.1fcm h=%.1fcm de volume %.1fcm3", this.getVolume() , this.r, this.h);
	}
	public static int getNbCones(){
		return nbCones;
	}

}
