package Java.OtherTest;

class Lock1 implements Runnable {
    static Object kinfe = new Object();
    static Object chopsticks = new Object();
    private boolean flag;

    public Lock1(boolean flag) {
        this.flag = flag;
    }

    public void run() {
        if (flag) {
            while (true) {
                synchronized (chopsticks) {
                    System.out.println(Thread.currentThread().getName() + "拿到了筷子" + flag);
                    synchronized (kinfe) {
                        System.out.println(Thread.currentThread().getName() + "拿到了刀" + flag);
                    }
                }
            }

        } else {
            while (true) {
                synchronized (kinfe) {
                    System.out.println(Thread.currentThread().getName() + "拿到了刀" + flag);
                    synchronized (chopsticks) {
                        System.out.println(Thread.currentThread().getName() + "拿到了筷子" + flag);
                    }
                }
            }

        }

    }
}

public class Lock {
    public static void main(String[] args) {
        Lock1 ld1 = new Lock1(false);
        Lock1 ld2 = new Lock1(true);

        new Thread(ld1, "Ch").start();
        new Thread(ld2, "Am").start();

    }
}
