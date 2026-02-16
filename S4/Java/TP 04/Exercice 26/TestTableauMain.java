public class TestTableauMain{
	public void main(String[] args){
		int indice = 0;
		System.out.format("Il y a %d arguments\n", args.length);
		for (String s:args){
		System.out.format("args[%d]=%s\n",indice,s);
		indice++;
		}
	}
}
