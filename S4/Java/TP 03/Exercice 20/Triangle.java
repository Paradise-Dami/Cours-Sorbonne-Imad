public class Triangle{
	private Point p1, p2, p3;

	public Triangle(Point p1, Point p2, Point p3){
	this.p1 = p1;
	this.p2 = p2;
	this.p3 = p3;
	}

	public Triangle(){
	this(new Point(),new Point(),new Point()); //jsp si c'est ce qui est demandé
	}

	public double getPerimetre(){
	return p1.distance(p2) + p2.distance(p3) + p3.distance(p1);
	}

	public Triangle copy(){
		Point a = p1.copy();
		Point b = p2.copy();
		Point c = p3.copy();
		return new Triangle(a,b,c);
	}

	public String toString(){
	return "{" + p1 + ";" + p2 + ";" + p3 + "}";
	}
}
