public class TestVillageois{
    public void main(){
        Villageois V1 = new Villageois("1");
        Villageois V2 = new Villageois("2");
        Villageois V3 = new Villageois("3");
        Villageois V4 = new Villageois("4");
        System.out.println(V1.toString());
        System.out.println(V2.toString());
        System.out.println(V3.toString());
        System.out.println(V4.toString());
        System.out.println(V1.poidsSouleve()
                            + V2.poidsSouleve()
                            + V3.poidsSouleve()
                            + V4.poidsSouleve() 
                            >= 100);
    }
}