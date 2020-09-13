package practice.patterns;

import org.junit.jupiter.api.*;

public class SingletonThreadTest {

    private static SingletonThread singleton = null;

    @BeforeEach
    public void setUp() {
        singleton = null;
    }

    @Test
    public void testUnique() throws InterruptedException {
        Thread threadOne = new Thread(new SingletonThreadRunnable()),
               threadTwo = new Thread(new SingletonThreadRunnable());

        threadOne.start();
        threadTwo.start();
        threadOne.join();
        threadTwo.join();
    }

    private static class SingletonThreadRunnable implements Runnable {

        @Override
        public void run() {

            // Get a reference to the singleton.
            SingletonThread singletonThread = SingletonThread.getInstance();

            // Protect singleton member variable from multithreaded access.
            synchronized (SingletonThreadTest.class) {

                // if singleton is null
                if (singleton == null) {

                    // set it to the singleton
                    singleton = singletonThread;
                }
            }

            // local reference must be equal to the one and only instance of Singleton.
            // otherwise, we have two Singleton instances.
            Assertions.assertEquals(true, singleton == singletonThread);
        }
    }
}
