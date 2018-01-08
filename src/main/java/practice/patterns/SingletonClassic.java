package practice.patterns;

final public class SingletonClassic {

    private static int counter = 1;
    private static SingletonClassic instance = null;

    // Don't allow any instantiations.
    private SingletonClassic() {

    }

    // Get the SingletonClassic object. Always one singleton instance.
    // The singleton instance is not created until the getInstance() method is called for the first time.
    public static SingletonClassic getInstance() {
        if (instance == null) {
            instance = new SingletonClassic();

            System.out.println(String.format("%d Instance Created.", counter));
            counter++;
        }
        return instance;
    }
}
