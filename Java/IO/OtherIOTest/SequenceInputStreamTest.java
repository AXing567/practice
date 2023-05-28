package Java.IO.OtherIOTest;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.SequenceInputStream;

public class SequenceInputStreamTest {
    public static void main(String[] args) {
        // 由于下载文件时是多线程同时下载的，所以下载的文件会被分成多个部分，这时候就需要将这些部分合并成一个文件
        // SequenceInputStream可以对多个输入流进行合并

        FileInputStream fis1 = null;
        FileInputStream fis2 = null;
        SequenceInputStream sis = null;
        FileOutputStream fos = null;
        try{
            fis1 = new FileInputStream("E:\\CodeAll\\Java\\OtherIOTest\\test.txt");
            fis2 = new FileInputStream("E:\\CodeAll\\Java\\OtherIOTest\\test2.txt");
            sis = new SequenceInputStream(fis1, fis2);
            fos = new FileOutputStream("E:\\CodeAll\\Java\\OtherIOTest\\test3.txt");
            int len;
            byte[] b = new byte[1024];
            while ((len = sis.read(b)) != -1) {
                fos.write(b, 0, len);
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                if (sis != null) {
                    sis.close();
                }
                if (fos != null) {
                    fos.close();
                }
                System.out.println("如果没有报错，那么写入成功！");
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
