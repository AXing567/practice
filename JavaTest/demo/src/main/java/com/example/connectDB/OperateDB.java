package com.example.connectDB;

public class OperateDB {
    public class CheckCodeMsg {
        public boolean checkCode;
        public String msg;
        public Boolean power;
    }

    public CheckCodeMsg check(String userName, String password) {
//        实例化链接数据库的对象，用其内部的方法进行数据库的操作
        ConnectDB conn = new ConnectDB();
//        实例化一个返回值对象
        CheckCodeMsg checkCodeMsg = new CheckCodeMsg();
        try {
            // 链接数据库
            conn.openCon();
            // 判断是否存在该用户
            conn.setRs(conn.getStmt().executeQuery("select '" + userName + "' from user"));
            if (conn.getRs() != null) {
                conn.setRs(conn.getStmt().executeQuery("SELECT * FROM USER WHERE `userName` = '" + userName + "' AND `password` = '" + password + "'"));
                if (conn.getRs() != null) {
                    checkCodeMsg.checkCode = true;
                    checkCodeMsg.msg = "登录成功";
                } else {
                    checkCodeMsg.checkCode = false;
                    checkCodeMsg.msg = "用户名或密码错误";
                }
            } else {
                checkCodeMsg.checkCode = false;
                checkCodeMsg.msg = "用户名或密码错误";
            }
            // 关闭数据库
            conn.closeCon();
            return checkCodeMsg;

        } catch (Exception e) {
            e.printStackTrace();
        }
        return checkCodeMsg;
    }



}
