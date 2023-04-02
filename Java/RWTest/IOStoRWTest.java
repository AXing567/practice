package Java.RWTest;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.io.BufferedWriter;

public class IOStoRWTest {
    public static void main(String[] args) {
        FileInputStream fis = null;
        FileOutputStream fos = null;
        BufferedReader br = null;
        BufferedWriter bw = null;
        InputStreamReader isr = null;
        OutputStreamWriter osw = null;
        try {
            fis = new FileInputStream("E:/CodeAll/Java/IOStreamTest/test.txt");
            fos = new FileOutputStream("E:/CodeAll/Java/IOStreamTest/test2.txt");
            isr = new InputStreamReader(fis);
            osw = new OutputStreamWriter(fos);
            br = new BufferedReader(isr);
            bw = new BufferedWriter(osw);
            String str;
            while((str = br.readLine()) != null) {
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
                System.out.println("写入成功！");
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

    }
}
