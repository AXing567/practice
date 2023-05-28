package Java.IO.FIleTest;

import java.io.RandomAccessFile;

public class RandomAccessFileTest {
    public static void main(String[] args) throws Exception {
        RandomAccessFile raf = new RandomAccessFile("E:\\CodeAll\\Java\\FIleTest\\test.txt", "rw");
        int times = 0;
        times = Integer.parseInt(raf.readLine());
        if (times > 0) {
            System.out.println("您已经使用过该软件" + (5 - times +1) + "次了，您还可以使用" + --times + "次");
            raf.seek(0);
            raf.writeBytes(String.valueOf(times));

        } else {
            System.out.println("您的使用次数已经用完，请注册后再使用！");
        }
        raf.close();
    }
}
