package Java.IO.OtherIOTest;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;

public class DataIOStreamTest {
    public static void main(String[] args) {
        FileInputStream fis = null;
        FileOutputStream fos = null;
        BufferedInputStream bis = null;
        BufferedOutputStream bos = null;
        DataInputStream dis = null;
        DataOutputStream dos = null;
        try {
            fis = new FileInputStream("OtherIOTest/test.txt");
            fos = new FileOutputStream("OtherIOTest/test.txt");
            bis = new BufferedInputStream(fis);
            bos = new BufferedOutputStream(fos);
            dis = new DataInputStream(bis);
            dos = new DataOutputStream(bos);
            dos.writeInt(10);
            dos.writeUTF("张三");
            dos.writeBoolean(true);
            dos.writeDouble(10.5);
            dos.writeChar('a');
            dos.writeFloat(10.5f);
            dos.writeLong(1000000000000000000L);
            dos.writeShort(10);
            dos.writeByte(10);
            // 刷新或关闭流方可写入数据
            dos.flush();
            System.out.println("写入成功！");
            System.out.println("读取数据：");
            System.out.println(dis.readInt());
            System.out.println(dis.readUTF());
            System.out.println(dis.readBoolean());
            System.out.println(dis.readDouble());
            System.out.println(dis.readChar());
            System.out.println(dis.readFloat());
            System.out.println(dis.readLong());
            System.out.println(dis.readShort());
            System.out.println(dis.readByte());
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                if (dis != null) {
                    dis.close();
                }
                if (dos != null) {
                    dos.close();
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
