package Java.IO.OtherIOTest;

import java.io.PrintStream;

public class PrintStreamTest {
    public static void main(String[] args) {
        PrintStream ps = null;
        try {
            // 创建一个文件字节输出流对象与test建立链接，第二个参数为true表示追加内容，false表示覆盖内容
            ps = new PrintStream("OtherIOTest/test.txt");

            ps.print(666);
            ps.println("星的Java文件字节输出流练习");
            ps.println("星的Java文件字节输出流练习");
            ps.println(new Student());
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                if (ps != null) {
                    ps.close();
                }
                System.out.println("如果没有报错，那么写入成功！");
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}

class Student{
    public String toString() {
        return "学生对象";
    }
}
