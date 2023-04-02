package Java.IOStreamTest;

// 所有的输出流类都是从OutputStream类派生出来的，OutputStream类是一个抽象类，它定义了所有输出流都具备的共同特征。
import java.io.FileOutputStream;

public class FileOutputSteamTest {
    // 用throws抛出异常容易执行不到close()方法，所以用try...catch...finally...语句块更适合
    public static void main(String[] args) throws Exception {
        // 创建一个文件字节输出流对象与test建立链接，第二个参数为true表示追加内容，false表示覆盖内容
        FileOutputStream out = new FileOutputStream("E:/CodeAll/Java/IOStreamTest/test.txt", true);
        String str = "星的Java文件字节输出流练习";
        // 将字符串转换为字节数组并根据test文件指定编码格式以解决乱码问题
        byte[] b = str.getBytes("Utf-8");
        // 将字节数组中的所有字节写入到文件中
        for (int i = 0 ; i < b.length ; i++) {
            out.write(b[i]);
        }
        out.close();
    }
    
}
