package com.example.connectDB;

import java.sql.*;

public class OperateDB {
    private static Connection conn;
    private static PreparedStatement pstmt;
    private static ResultSet rs;

    /**
     * @param : 空
     * @return void
     * @author Axing
     * @description 链接数据库
     * @date 2023/6/28 16:30
     */
    public void connect(){
        try {
            Class.forName("com.mysql.jdbc.Driver");
            String url="jdbc:mysql://localhost:3306/school";
            conn = DriverManager.getConnection(url,"root","123");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static ResultSet selectToken(String token){
        try {
            pstmt = conn.prepareStatement("select * from user where token = ?");
            pstmt.setString(1,token);
            return pstmt.executeQuery();
        } catch (Exception e) {
            e.printStackTrace();
            System.out.println("查找token异常（当有此报错的时候，selectToken()的返回值为空）");
        }
        return null;
    }

    /**
     * @param userName: 用户名
     * @param password: 密码
     * @return ResultSet
     * @author Axing
     * @description 查询用户名和密码后返回一个对象如登录信息，权限等。参考com.example.LoginService.LoginResult类
     * @date  2023/6/28 16:30
     */
    public ResultSet selectUser(String userName, String password){
        try {
            pstmt = conn.prepareStatement("SELECT * FROM user WHERE userName = ? AND password = ?");
            pstmt.setString(1, userName);
            pstmt.setString(2, password);
            return pstmt.executeQuery();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return rs;
    }

//    public String

    /**
     * @param :
     * @return void
     * @author Axing
     * @description 关闭数据库
     * @date  2023/6/28  16:36
     */
    public void closeDB(){
        try {
            if(rs!=null) rs.close();
            if(pstmt!=null) pstmt.close();
            if(conn!=null) conn.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}
