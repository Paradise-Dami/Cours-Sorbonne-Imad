public class EntierBorne {
    private int entier;
    private final int MIN = -100;
    private final int MAX = 100; 
    public EntierBorne(int n) throws HorsBornesException{
        if ((n < MIN) || (n > MAX)){
            throw new HorsBornesException("Nombre en dehors des bornes");
        } else {
            entier = n;
        }
    }
}
