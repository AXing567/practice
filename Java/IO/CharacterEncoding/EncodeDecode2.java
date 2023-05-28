package Java.IO.CharacterEncoding;

import java.io.UnsupportedEncodingException;
import java.nio.charset.StandardCharsets;

public class EncodeDecode2 {
    public static void main(String[] args) throws UnsupportedEncodingException {
        String str = "文件编码解码练习";
        byte[] b1 = str.getBytes(StandardCharsets.UTF_8);
        String result1 = new String(b1, "ISO8859-1");
        System.out.println(result1);
        byte[] b2 = result1.getBytes("ISO8859-1");
        String result2 = new String(b2, StandardCharsets.UTF_8);
        System.out.println(result2);
    }
}
