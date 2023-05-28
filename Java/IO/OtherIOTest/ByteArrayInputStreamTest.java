package Java.IO.OtherIOTest;

import java.io.ByteArrayInputStream;

public class ByteArrayInputStreamTest {
    public static void main(String[] args) {
        byte[] b = { 1, 2, 3, 4, -1 };
        ByteArrayInputStream bais = new ByteArrayInputStream(b);
        int data;
        while ((data = bais.read()) != -1) {
            System.out.println(data);
        }
    }
}
