package Java.IO.OtherIOTest;

import java.io.CharArrayReader;
import java.io.CharArrayWriter;
import java.io.FileReader;

public class CharArrayRWTest {
    public static void main(String[] args) {
        FileReader fis = null;
        CharArrayWriter caw = null;
        CharArrayReader car = null;
        try {
            fis = new FileReader("E:\\CodeAll\\Java\\OtherIOTest\\test.txt");
            caw = new CharArrayWriter();
            int b;
            while ((b = fis.read()) != -1) {
                caw.write(b);
            }
            char[] c = caw.toCharArray();
            car = new CharArrayReader(c);
            int i;
            while ((i = car.read()) != -1) {
                System.out.print((char) i);
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                if (fis != null) {
                    // 关闭文件输入流
                    fis.close();
                }
                if (caw != null) {
                    // 关闭字节数组输出流
                    caw.close();
                }
                if (car != null) {
                    // 关闭文件输出流
                    car.close();
                }
            } catch (Exception e) {
                e.printStackTrace();
            }

        }
    }
}
