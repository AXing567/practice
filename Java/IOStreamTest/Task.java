package Java.IOStreamTest;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

public class Task {
	
	public static void task() throws Exception{
		/********* Begin *********/
		File file = new File("D://hello.txt");
        FileOutputStream out = new FileOutputStream(file);
        FileInputStream in = new FileInputStream(file);

        
        String str = "Hello Java Hello InputStream";
        byte[] b = str.getBytes("UTF-8");
        for (int i = 0 ; i < b.length ; i++){
            out.write(b[i]);
        }


        byte[] c = new byte[1024];
        in.read(c);
        str = new String(c,"UTF-8");
        System.out.print(str);
		in.close();
        out.close();;
        
		
		/********* End *********/
	}
	
    public static void main(String[] args) throws Exception {
        task();
    }
}
