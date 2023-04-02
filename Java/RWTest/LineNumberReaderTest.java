package Java.RWTest;

import java.io.FileReader;
import java.io.LineNumberReader;
import java.io.FileWriter;

public class LineNumberReaderTest {
    public static void main(String[] args) {
        FileReader reader = null;
        FileWriter writer = null;
        LineNumberReader lnr = null;
        try {
            reader = new FileReader("E:/CodeAll/Java/IOStreamTest/test.txt");
            writer = new FileWriter("E:/CodeAll/Java/IOStreamTest/test2.txt");
            lnr = new LineNumberReader(reader);// 包装成LineNumberReader对象
            // 因为LineNumberReader类读取到换行符、回车符、或者换行回车符时，会自动增加行号，所以在此我们设置初始行号为0
            lnr.setLineNumber(0);// 设置初始行号为0
            String str;
            while ((str = lnr.readLine()) != null) {
                writer.write(lnr.getLineNumber() + ":" + str);
                writer.write("\r\n");
            }
            writer.flush();
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                if (lnr != null) {
                    lnr.close();
                }
                if (writer != null) {
                    writer.close();
                }
                System.out.println("写入成功！");
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
