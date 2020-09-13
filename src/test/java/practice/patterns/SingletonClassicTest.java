package practice.patterns;

public class SingletonClassicTest {

    public static void main(String... args) {

        SingletonClassic singleton1 = SingletonClassic.getInstance();
        SingletonClassic singleton2 = SingletonClassic.getInstance();
        SingletonClassic singleton3 = SingletonClassic.getInstance();
        SingletonClassic singleton4 = SingletonClassic.getInstance();

        // Single instance, hence should be true.
        System.out.println(singleton1 == singleton2);
        System.out.println(singleton3 == singleton4);
    }
}
