package Java.RWTest;

import java.io.FileWriter;
import java.nio.charset.Charset;


public class FileWriterTest {
    public static void main(String[] args) {
        FileWriter writer = null;
        try{
            String file = "E:/CodeAll/Java/IOStreamTest/test.txt";
            //重点在于这里的编码格式，如果不指定编码格式，那么默认的是GBK编码格式
            writer = new FileWriter(file, Charset.forName("UTF-8"));
            writer.write("你好 世界！！");
        }catch(Exception e) {
            e.printStackTrace();
        } finally {
            try {
                if(writer != null) {
                    writer.close();
                }
            }catch(Exception e) {
                e.printStackTrace();
            }
        }
    }
}
