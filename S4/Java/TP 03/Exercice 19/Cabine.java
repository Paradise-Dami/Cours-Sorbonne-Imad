public class Cabine {
    private int volume;
    private String couleur;
    
    public Cabine(int volume, String couleur){
        this.volume = volume;
        this.couleur = couleur;
    }

    public void setCouleur(String couleur){
        this.couleur = couleur;
    }

    public String toString(){
        return "Volume, Couleur : " + this.volume + "," + this.couleur;
    }
}
