package Java.IO.OtherIOTest;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;

public class StandardIOStreamTest2 {
    public static void main(String[] args) {
        try {
            // 重定向标准输入输出流
            System.setIn(new FileInputStream("E:\\CodeAll\\Java\\OtherIOTest\\test.txt"));
            System.setOut(new PrintStream("E:\\CodeAll\\Java\\OtherIOTest\\test2.txt"));
            // 字节流转换为字符流 —— 缓冲字符流包装字符流
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            String str;
            while ((str = br.readLine()) != null) {
                System.out.println(str);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
