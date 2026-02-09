public class TestTriangle{
	public void main(){
	Point p1 = new Point(3,5);
	Point p2 = new Point();
	Point p3 = new Point();
	System.out.println(p1.toString() + p2.toString() + p1.distance(p2));
	Triangle t1 = new Triangle(p1, p2, p3);
	System.out.println(t1.toString() + t1.getPerimetre());
	}

}
