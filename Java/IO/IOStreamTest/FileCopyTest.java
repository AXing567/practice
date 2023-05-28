package Java.IO.IOStreamTest;

import java.io.FileInputStream;
import java.io.FileOutputStream;

public class FileCopyTest {
    public static void main(String[] args) {
        FileInputStream in = null;
        FileOutputStream out = null;
        try {
            in = new FileInputStream("F:/CloudMusic/Quinn葵因 - 非白.mp3");
            out = new FileOutputStream("E:/CodeAll/Java/IOStreamTest/非白.mp3");
            int len ;
            long beginTime = System.currentTimeMillis();
            while((len = in.read()) != -1){
                out.write(len);
            }
            long endTime = System.currentTimeMillis();
            System.out.println("复制文件所花费的时间为：" + (endTime - beginTime) + "ms");
        } catch (Exception e){
            e.printStackTrace();
        } finally{
            try{
                if(in != null){
                    in.close();
                }
            } catch (Exception e){
                e.printStackTrace();
            }
            try{
                if(out != null){
                    out.close();
                }
            } catch (Exception e){
                e.printStackTrace();
            }
        }
    }
}
