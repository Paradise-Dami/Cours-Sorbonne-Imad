public class TrianglePascal{
	public int[][] tabPascal;
	public TrianglePascal(int n){
		tabPascal = new int[n][];
		for (int i = 0; i < n; i++){
			tabPascal[i] = new int[i];
		}
	}
	public void remplirTriangle(){
		System.out.println("A = " + tabPascal.length);
		for (int i = 0; i < tabPascal.length; i++){
			tabPascal[i][0] = 1;
			for (int j = 1; j < tabPascal[i].length; j++){
				if (i==j){
					tabPascal[i][j] = 1;
				} else {
					tabPascal[i][j] = tabPascal[i-1][j-1] + tabPascal[i-1][j];
				}
			}
		}
	}
	public String toString(){
		String res = "";
		for (int[] i: tabPascal){
			for (int j = 0; j < i.length; j++){
				res += "|" + i[j] +"|";
			}
			res+="\n";
		}
		return res;
	}
}
