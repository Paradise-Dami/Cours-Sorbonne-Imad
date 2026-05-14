import java.util.InputMismatchException;
import java.util.Scanner;

public class TestSleep{
    public static void main(String args[]){
        int x = 0;
        Scanner scanner = new Scanner(System.in);
        System.out.print( "Entrer un entier : " );
        try {
            x = scanner.nextInt();
        } catch (InputMismatchException e) {
            System.out.print("Le nombre est mal formé");
            return;
        }
        System.out.println("Attente de " + x + " secondes");
        try {
        Thread.sleep(1000*x);
        } catch (InterruptedException e) {
            return;
        }
        System.out.println("Fin de l'attente");
    }
}