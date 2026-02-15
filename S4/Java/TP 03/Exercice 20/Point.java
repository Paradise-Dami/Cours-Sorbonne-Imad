public class Point{
	private int posx,posy;

	public Point(int posx, int posy){
	this.posx = posx;
	this.posy = posy;
	}

	public Point(){
	int MAX = 9;
        int MIN = 0;
	this((int)(Math.random()*(MAX-MIN+1)+MIN),(int)(Math.random()*(MAX-MIN+1)+MIN));
	}

	public double distance(Point p){
	double deltaX2 = (this.posx-p.posx)*(this.posx-p.posx);
	double deltaY2 = (this.posy-p.posy)*(this.posy-p.posy);
	return Math.sqrt(deltaX2 + deltaY2);
	}

	public void deplaceToi(int newx, int newy){
	posx = newx;
	posy = newy;
	}

	public Point copy(){
		return new Point(posx,posy);
	}

	public String toString(){
	return "(" + posx + "," + posy + ")";

	}

}
