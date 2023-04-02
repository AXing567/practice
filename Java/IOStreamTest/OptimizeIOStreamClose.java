package Java.IOStreamTest;

import java.io.FileInputStream;
import java.io.FileOutputStream;

public class OptimizeIOStreamClose {
    public static void main(String[] args) {
        FileInputStream in = null;
        FileOutputStream out = null;
        try {
            // 建立与test.txt的联系
            in = new FileInputStream("E:/CodeAll/Java/IOStreamTest/test.txt");
            out = new FileOutputStream("E:/CodeAll/Java/IOStreamTest/test.txt", false);
            String str = "itcast";
            // 将字符串转换为字节数组并根据test文件指定编码格式以解决乱码问题
            byte[] b = str.getBytes("Utf-8");//getBytes(Charset charset) 使用给定的charset将该String编码为字节序列，将结果存储到新的字节数组中。 
            // 将字节数组中的所有字节写入到文件中
            for (int i = 0; i < b.length; i++) {
                out.write(b[i]);
            }

            int c = 0;
            // 循环读取test.txt文件中的内容（一次八位）并转换成十进制整形输出
            while (true) {
                c = in.read();
                // 如果读取到了文件末尾，就退出。即read()方法返回-1
                if (c == -1) {
                    break;
                }
                System.out.println(c);
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            // 使用更稳妥的方式来执行close()方法
            try {
                // 在 finally块中需要对 in 和 out 对象进行非空判断，因为它们可能在 try 块中没有成功初始化，或者在初始化后在使用过程中出现了异常。
                if (in != null) {
                    in.close();
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
            try {
                if (out != null) {
                    out.close();
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
