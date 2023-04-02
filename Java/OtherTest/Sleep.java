package Java.OtherTest;

class SleepThread implements Runnable {
    public void run() {
        for (int i = 1; i <= 10; i++) {
            if (i == 3) {
                try {
                    Thread.sleep(2000);// 两秒
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            System.out.println("线程1正在输出：" + i);
            try{
                Thread.sleep(500);
            }catch (InterruptedException e){
                e.printStackTrace();
            }

        }
    }
}

public class Sleep {
    public static void main(String[] args) {

    }
}
