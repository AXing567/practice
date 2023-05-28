package Java.IO.OtherIOTest;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.SequenceInputStream;
import java.util.Enumeration;
import java.util.Vector;

public class SequenceInputStreamTest2 {
    public static void main(String[] args) {
        Vector vector = new Vector();
        FileInputStream fis1 = null;
        FileInputStream fis2 = null;
        SequenceInputStream sis = null;
        FileOutputStream fos = null;
        try {
            fis1 = new FileInputStream("E:\\CodeAll\\Java\\OtherIOTest\\test.txt");
            fis2 = new FileInputStream("E:\\CodeAll\\Java\\OtherIOTest\\test2.txt");
            vector.addElement(fis1);
            vector.addElement(fis2);
            Enumeration e = vector.elements();//获取Vector对象中的元素
            sis = new SequenceInputStream(e);
            fos = new FileOutputStream("E:\\CodeAll\\Java\\OtherIOTest\\test3.txt");
            int len;
            byte[] buf = new byte[1024];
            while ((len = sis.read(buf)) != -1) {
                fos.write(buf, 0, len);// 写入数组的0到0+len-1
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
