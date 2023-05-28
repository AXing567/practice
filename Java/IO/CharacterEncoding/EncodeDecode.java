package Java.IO.CharacterEncoding;

import java.io.UnsupportedEncodingException;
import java.nio.charset.StandardCharsets;
import java.util.Arrays;

public class EncodeDecode {
    public static void main(String[] args) throws UnsupportedEncodingException {
        String str = "文件编码解码练习";
        byte[] b1 = str.getBytes();
        byte[] b2 = str.getBytes("GBK");
        System.out.println(Arrays.toString(b1));
        System.out.println(Arrays.toString(b2));
        byte[] b3 = str.getBytes(StandardCharsets.UTF_8);
        String result1 = new String(b1, "GBK");
        System.out.println(result1);
        String result2 = new String(b2, "GBK");
        System.out.println(result2);
        String result3 = new String(b3, StandardCharsets.UTF_8);
        System.out.println(result3);
        String result4 = new String(b2, "ISO8859-1");
        System.out.println(result4);
    }
}
