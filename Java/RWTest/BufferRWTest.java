package Java.RWTest;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.BufferedReader;
import java.io.FileReader;

public class BufferRWTest {
    public static void main(String[] args) {
        FileReader reader = null;
        FileWriter writer = null;
        BufferedReader br = null;
        BufferedWriter bw = null;
        try {
            reader = new FileReader("E:/CodeAll/Java/IOStreamTest/test.txt");
            writer = new FileWriter("E:/CodeAll/Java/IOStreamTest/test2.txt");
            br = new BufferedReader(reader);
            bw = new BufferedWriter(writer);
            String str;
            // readLine()方法读取一行，不包含换行符
            // newLine()方法根据操作系统写入一个适应的换行符
            while ((str = br.readLine()) != null) {
                bw.write(str);
                bw.newLine();
            }

        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                if (br != null) {
                    br.close();
                }
                if (bw != null) {
                    bw.close();
                }
                
                // 由于使用了缓冲区，所以写入的内容首先被写入缓冲区
                // 只有缓冲区满或关闭流时才会写入文件
                System.out.println("写入成功！");
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
