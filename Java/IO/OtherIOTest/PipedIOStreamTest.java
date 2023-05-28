package Java.IO.OtherIOTest;

import java.io.*;

public class PipedIOStreamTest {
    public static void main(String[] args) throws Exception {
        // 创建管道输入流与管道输出流
        final PipedInputStream pis = new PipedInputStream();
        final PipedOutputStream pos = new PipedOutputStream();
        // 将管道输入流与管道输出流进行连接
        pis.connect(pos);


        new Thread(new Runnable() {
            @Override
            public void run() {
                // 创建字符缓冲输入流包装来自系统输入后转换为的字符流
                BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                PrintStream ps = new PrintStream(pos);
                String line = null;
                while (true) {
                    try {
                        System.out.print(Thread.currentThread().getName() + "要求输入内容：");
                        ps.println(br.readLine());
                        Thread.sleep(1000);
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
            }
        }, "发送数据的线程").start();


        new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    BufferedReader br = new BufferedReader(new InputStreamReader(pis));
                    while (true) {
                        System.out.println(Thread.currentThread().getName() + "接收到的内容：" + br.readLine());
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }, "接收数据的线程").start();


    }
}
