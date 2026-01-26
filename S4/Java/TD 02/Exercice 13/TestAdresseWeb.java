public class TestAdresseWeb{
    public void main(){
        AdresseWeb w1 = new AdresseWeb("https","frite.fr","/test");
        AdresseWeb w2 = new AdresseWeb("stairs.website", "/hello");
        AdresseWeb w3 = new AdresseWeb("pouler.fr");
        System.out.println(w1.toString());
        System.out.println(w2.toString());
        System.out.println(w3.toString());
    }
}