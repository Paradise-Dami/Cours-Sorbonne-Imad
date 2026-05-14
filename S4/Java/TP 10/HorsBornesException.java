public class HorsBornesException extends Exception {
    public HorsBornesException(String errorMessage){
        super("Nombre Invalide" + errorMessage);
    }
}
