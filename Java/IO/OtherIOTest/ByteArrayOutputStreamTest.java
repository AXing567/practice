package Java.IO.OtherIOTest;


import java.io.ByteArrayOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;

public class ByteArrayOutputStreamTest {
    public static void main(String[] args) {
        FileInputStream fis = null;
        ByteArrayOutputStream baos = null;
        FileOutputStream fos = null;
        try {
            // 创建一个文件输入流对象与test建立链接
            fis = new FileInputStream("E:\\CodeAll\\Java\\OtherIOTest\\test.txt");
            // 创建一个字节数组输出流对象
            baos = new ByteArrayOutputStream();
            // 创建一个文件输出流对象与test1建立链接
            fos = new FileOutputStream("E:\\CodeAll\\Java\\OtherIOTest\\test2.txt");

            int b;
            while ((b = fis.read()) != -1) {
                // 将读取到的数据写入字节数组缓冲区中
                baos.write(b);
            }
            // 将缓冲区的数据一次性写入test2.txt中
            fos.write(baos.toByteArray());
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                if (fis != null) {
                    // 关闭文件输入流
                    fis.close();
                }
                if (baos != null) {
                    // 关闭字节数组输出流
                    baos.close();
                }
                if (fos != null) {
                    // 关闭文件输出流
                    fos.close();
                }
                System.out.println("如果没有报错，那么写入成功！");
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

    }
}
