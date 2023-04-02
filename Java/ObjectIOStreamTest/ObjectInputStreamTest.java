package Java.ObjectIOStreamTest;

import java.io.FileInputStream;
import java.io.ObjectInputStream;

public class ObjectInputStreamTest {
    public static void main(String[] args) {
        FileInputStream fis = null;
        ObjectInputStream ois = null;
        try {
            //首先创建一个文件输入流，用于读取文件中的对象
            fis = new FileInputStream("Java/ObjectIOStreamTest/test.txt");
            //用ObjectInputStream包装文件输入流，使其具有读取对象的功能
            ois = new ObjectInputStream(fis);
            //读取对象
            Person p = (Person)ois.readObject();
            System.out.println("读取对象后：" + p.getName() + " " + p.getAge());
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                if (ois != null) {
                    ois.close(); 
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

    }
}
