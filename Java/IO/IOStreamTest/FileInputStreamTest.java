package Java.IO.IOStreamTest;

// 所有的输入流类都是从InputStream类派生出来的，InputStream类是一个抽象类，它定义了所有输入流都具备的共同特征。
import java.io.FileInputStream;

public class FileInputStreamTest {
    // 用throws抛出异常容易执行不到close()方法，所以用try...catch...finally...语句块更适合
    public static void main(String[] args) throws Exception {
        // 建立与test.txt的联系
        FileInputStream in = new FileInputStream("E:/CodeAll/Java/IOStreamTest/test.txt");

        int b = 0;
        // 循环读取test.txt文件中的内容（一次八位）并转换成十进制整形输出
        while (true) {
            b = in.read();
            // 如果读取到了文件末尾，就退出。即read()方法返回-1
            if (b == -1) {
                break;
            }
            System.out.println(b);
        }
        // 关闭输入流以节省内存资源
        in.close();
    }

}
