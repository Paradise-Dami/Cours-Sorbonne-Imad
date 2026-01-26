public class AdresseWeb{
    public String protocole;
    public String domaine;
    public String chemin;
    
    public AdresseWeb(String p, String d, String c){
        protocole = p;
        domaine = d;
        chemin = c;
    }
    public AdresseWeb(String d, String c){
        protocole = "http";
        domaine = d;
        chemin = c;
    }
    public AdresseWeb(String d){
        this(d,"");
    }
    public String toString(){
        return protocole + "://" + domaine + chemin;
    }
}