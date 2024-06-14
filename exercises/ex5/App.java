public class App{
    public static void main(String[] arge){
        bar();
    }
    public static void bar(){
        System.out.println("=");
        bar();
    }
}