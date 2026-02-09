public class Segment {
    private static int x, y;
    public Segment(int extX, int extY) {
        x = extX;
        y = extY;
    }
    public int longueur() {
        if (x <= y) {
            return y-x;
        }
        else {
            return x-y;
        }
    }
    public String toString(){
        return "Segment [<" + x + ">, <" + y + ">]";      
    }
}
