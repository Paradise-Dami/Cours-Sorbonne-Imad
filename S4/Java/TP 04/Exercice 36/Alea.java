public class Alea{
	private static final int MIN_LETTRE = 97;
	private static final int MAX_LETTRE = 122;

	private Alea(){};

	public static char lettre(){
		return (char)(Math.random()*(MAX_LETTRE-MIN_LETTRE+1) + MIN_LETTRE);
	}
	public static String chaine(){
		String out ="";
		for (int i = 0; i < 10; i++){
			out = out + lettre();
		}
		return out;
	}
	public static void main(){
		System.out.println(chaine());
	}
}
