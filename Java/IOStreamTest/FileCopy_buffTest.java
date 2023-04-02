package Java.IOStreamTest;

import java.io.FileInputStream;
import java.io.FileOutputStream;

public class FileCopy_buffTest {
    public static void main(String[] args) {
        FileInputStream in = null;
        FileOutputStream out = null;
        try {
            in = new FileInputStream("F:/CloudMusic/Quinn葵因 - 非白.mp3");
            out = new FileOutputStream("E:/CodeAll/Java/IOStreamTest/非白.mp3");
            byte[] buff = new byte[8192];
            int len;
            long beginTime = System.currentTimeMillis();
            while ((len = in.read(buff)) != -1) {
                out.write(buff, 0, len);
            }
            long endTime = System.currentTimeMillis();
            System.out.println("复制文件所花费的时间为：" + (endTime - beginTime) + "ms");
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                if (in != null) {
                    in.close(); // 关闭输入流
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
            try {
                if (out != null) {
                    out.close(); // 关闭输出流
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
