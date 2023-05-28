package Java.IO.RWTest;

import java.io.FileReader;

public class FileReaderTest {
    public static void main(String[] args) {
        FileReader reader = null;
        try {
            reader = new FileReader("E:/CodeAll/Java/IOStreamTest/test.txt");
            int read;
            while((read = reader.read()) != -1) {
                System.out.print((char)read);
            }
        }catch(Exception e) {
            e.printStackTrace();
        }finally {
            try {
                if(reader != null) {
                    reader.close();
                }
            }catch(Exception e) {
                e.printStackTrace();
            }
        }
    }
}
