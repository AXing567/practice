package Java.IO.OtherIOTest;


public class StandardIOStreamTest {
    public static void main(String[] args)  {
        try{
            StringBuffer sb = new StringBuffer();
            int c;
            while ((c = System.in.read()) != '\n' && c != '\r') {
                sb.append((char)c);
            }
            System.out.println(sb);
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
}
