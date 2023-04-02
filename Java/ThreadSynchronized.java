package Java;

class Storage {
    private int[] cells = new int[10];
    private int inPos, outPos;
    private int count;

    public synchronized void put(int num) {
        try {
            while (count == cells.length) {
                this.wait();// 当计数为数组长度的时候，让此线程放弃同步锁，进入等待
            }
            cells[inPos] = num;
            System.out.println("在cells[" + inPos + "]中加入了----" + cells[inPos]);
            inPos++;
            if (inPos == cells.length) {
                inPos = 0;
            }
            count++;
            this.notify();
        } catch (Exception e) {// wait()会有抛出IllegalMonitorStateException异常的可能，当使用的线程不是同步锁对象的时候
            e.printStackTrace();
        }
    }

    public synchronized void get() {
        try {
            while (count == 0) {
                this.wait();// 当计数为0的时候，对应对象进入等待
            }
            System.out.println("从cells[" + outPos + "]中取出了----" + cells[outPos]);
            cells[outPos] = 0;
            outPos++;
            if (outPos == cells.length) {
                outPos = 0;
            }
            count--;
            this.notify();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

class Input implements Runnable {
    private Storage st;
    private int num;

    public Input(Storage st) {
        this.st = st;
    }

    public void run() {
        while (true) {
            st.put(num++);
        }
    }
}

class Output implements Runnable {
    private Storage st;
    Output(Storage st){
        this.st = st;
    }
    public void run(){
        while (true) {
            st.get();
        }
    }
}

public class ThreadSynchronized {
    public static void main(String[] args) {
        Storage st = new Storage();
        Input input = new Input(st);
        Output output = new Output(st);
        new Thread(input).start();
        new Thread(output).start();
    }

}
