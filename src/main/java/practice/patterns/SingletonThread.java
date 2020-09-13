package practice.patterns;

final public class SingletonThread {

    private static boolean firstThread = true;
    private static int counter = 1;
    private static SingletonThread instance = null;

    // Don't allow any instantiations.
    private SingletonThread() {

    }

    public static SingletonThread getInstance() {
        if (instance == null) {

            // synchronized makes the getInstance() method thread safe.
            // rather than making the whole method synchronized, only synchronize the critical code.
            synchronized (SingletonThread.class) {

                // simulateRandomActivity();
                instance = new SingletonThread();

                System.out.println(String.format("%d Instance Created.", counter));
                counter++;
            }
        }

        return instance;
    }

    private static void simulateRandomActivity() {
        try {
            if(firstThread) {
                firstThread = false;
                Thread.currentThread().sleep(50);
            }
        } catch (InterruptedException e) {
            System.out.println();
        }
    }

}
