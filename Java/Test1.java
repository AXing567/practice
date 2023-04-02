package Java;

import java.io.*;

public class Test1 {
    public static void main(String[] args) throws IOException {
        Runtime rt = Runtime.getRuntime();
        rt.exec("notepad");
    }
}





// class AddThread implements Runnable {
//     public static int sum;
//     private int num , starter;
//     public AddThread(int starter) {
//         this.starter = starter;
//     }
    
//     public void run() {
//         for(int i = 1; i <= 10 ; i++)
//         {
//             num += starter++;
//         }
//         AddThread.sum += num;
//     }

// }

// public class Test1 {
//     public static void main(String[] args) {
//         int x = 10;
//         Thread[] a = new Thread[x];
//         for(int i = 0 ; i < x ; i++)
//         {
//            a[i] = new Thread(new AddThread(i * 10 + 1));
//            a[i].start();
//         }
//         for (int i = 0 ; i < x ; i++)
//         {
//             try{
//                 a[i].join();
//             }catch(Exception e){
//                 e.printStackTrace();
//             }
//         }
//         System.out.println(AddThread.sum);
//     }
// }


// class Teacher implements Runnable {
// private int x;

// public Teacher(int x) {
// this.x = x;
// }

// public void run() {
// while (true) {

// try {
// Thread.sleep(1);
// } catch (Exception e) {
// e.printStackTrace();
// }
// if (x > 0) {
// System.out.println("试卷" + x-- + "已发放（" + Thread.currentThread().getName() +
// ")");
// } else {
// break;
// }

// }

// }

// private synchronized void putPaper() {
// try {
// Thread.sleep(1);
// } catch (Exception e) {
// e.printStackTrace();
// }
// System.out.println("试卷" + x-- + "已发放（" + Thread.currentThread().getName() +
// ")");
// }
// }

// public class Test1 {
// public static void main(String[] args) {
// Teacher t = new Teacher(80);
// new Thread(t, "小明").start();
// new Thread(t, "小李").start();
// new Thread(t, "小刚").start();
// new Thread(t, "小志").start();

// }
// }

// class ThreadA implements Runnable {
// public void run() {
// int i = 50;
// while (i != 0) {
// System.out.println("new" + i--);
// }
// }
// }
// public class Test1{
// public static void main(String[] args) {
// Thread printNew = new Thread(new ThreadA());
// printNew.start();
// int i = 100;
// while(i != 0) {
// System.out.println("main" + i--);
// }
// }
// }

// class ThreadA extends Thread{
// public void run(){
// System.out.println(Thread.currentThread().getName());
// }
// }

// class ThreadB extends Thread{
// public void run(){
// System.out.println(Thread.currentThread().getName());
// }
// }

// public class Test1{
// public static void main(String[] args) {
// ThreadA a = new ThreadA();
// a.setName("线程1正在执行");
// ThreadA b = new ThreadA();
// b.setName("线程2正在执行");
// a.start();
// b.start();
// }
// }