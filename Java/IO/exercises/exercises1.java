package Java.IO.exercises;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class exercises1 {
    public static void main(String[] args) throws IOException {
        int a = 4;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str ;
        str = br.readLine();
        System.out.println(str);
    }
}
