package Java;

import java.time.*;
import java.util.Scanner;

public class BookkeepingBook {
    private static double he = 698, she = 648, play = 528.4;

    public static void main(String[] args) {

        while (true) {
            System.out.println("-----------欢迎使用星星&红红の专属记账本！-----------");
            System.out.println("本月余额（星）：" + get_he());
            System.out.println(
                    "平均每天可花费（含今天）：" + String.format("%.2f", (get_he() / getDaysLeftInMonth())).toString() + '\n');

            System.out.println("本月余额（红）：" + get_she());
            System.out.println(
                    "平均每天可花费（含今天）：" + String.format("%.2f", (get_she() / getDaysLeftInMonth())).toString() + '\n');

            System.out.println("本月余额（娱乐）：" + get_play());
            System.out.println(
                    "平均每天可花费（含今天）：" + String.format("%.2f", (get_play() / getDaysLeftInMonth())).toString() + '\n');

            int x;
            System.out.println("\n\n\n请输入数字以选择功能：");
            System.out.println("1.修改（星）当前余额");
            System.out.println("2.修改（红）当前余额");
            System.out.println("3.修改（娱乐）当前余额");
            Scanner s = new Scanner(System.in);
            double y;
            x = s.nextInt();
            switch (x) {
                case 1:
                    System.out.println("请输入要新增多少钱（用负号表示减少）：");
                    y = s.nextDouble();
                    set_he(y);
                    break;
                case 2:
                    System.out.println("请输入要新增多少钱（用负号表示减少）：");
                    y = s.nextDouble();
                    set_she(y);
                    break;
                case 3:
                    System.out.println("请输入要新增多少钱（用负号表示减少）：");
                    y = s.nextDouble();
                    set_play(y);
                    break;
                default:
                    System.out.println("您输入的信息有误，请重试。");
            }

        }

    }

    public static int getDaysLeftInMonth() {
        LocalDate today = LocalDate.now();
        int monthLength = today.lengthOfMonth();// 本月天数
        int daysLeft = monthLength - today.getDayOfMonth() + 1; // 本月剩余天数（含今天）
        return daysLeft;
    }

    public static void set_he(double x) {
        he += x;
        System.out.println("当前余额（星）：" + he);
    }

    public static void set_she(double x) {
        she += x;
        System.out.println("当前余额（红）：" + she);
    }

    public static void set_play(double x) {
        play += x;
        System.out.println("当前余额（娱乐）：" + play);
    }

    public static double get_he() {
        return he;
    }

    public static double get_she() {
        return she;
    }

    public static double get_play() {
        return play;
    }

}
