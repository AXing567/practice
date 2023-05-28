package Java.IO.IOStreamTest;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;

public class FileCopy_BufferedTest {
    public static void main(String[] args) {
        BufferedInputStream in = null;
        BufferedOutputStream out = null;
        try {
            // BufferedInputStream(InputStream in) 
            // 创建一个 BufferedInputStream并保存其参数，输入流 in ，供以后使用。
            
            // BufferedInputStream(InputStream in, int size) 
            // 创建 BufferedInputStream具有指定缓冲区大小，并保存其参数，输入流 in ，供以后使用。 
            in = new BufferedInputStream(new FileInputStream("F:/CloudMusic/Quinn葵因 - 非白.mp3"));
            out = new BufferedOutputStream(new FileOutputStream("E:/CodeAll/Java/IOStreamTest/非白.mp3"));
            int len;
            long beginTime = System.currentTimeMillis();
            while ((len = in.read()) != -1) {
                out.write(len);
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
