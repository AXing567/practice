package com.example.operateDB;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.sql.*;

public class OperateDB {
    private static Connection conn;
    private static PreparedStatement pstmt;
    private static ResultSet rs;
    /*日志记录器*/
    static Logger logger = LoggerFactory.getLogger(OperateDB.class);


    /**
     * @author Axing
     * @description 链接数据库
     * @date 2023/6/28 16:30
     */
    public static void connect() {
        try {
            Class.forName("com.mysql.jdbc.Driver");
            String url = "jdbc:mysql://localhost:3306/school";
            conn = DriverManager.getConnection(url, "root", "123");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * @param token:
     * @param userName:
     * @return Boolean 更新成功返回true，否则返回false
     * @author Axing
     * @description 根据用户名更新token
     * @date 2023/6/29 10:22
     */
    public static Boolean update(String token, String userName) {
        try {
            pstmt = conn.prepareStatement("update user set token = ? where userName = ?");
            pstmt.setString(1, token);
            pstmt.setString(2, userName);
            return pstmt.executeUpdate() == 1;
        } catch (Exception e) {
            e.printStackTrace();
            logger.error("更新token异常");
        }
        return false;
    }

    /**
     * @param token:
     * @param userName:
     * @return ResultSet
     * @author Axing
     * @description 根据token判断是否存在此token，存在则返回一个ResultSet对象，否则返回null。验证token时可以通过此方法判断token是否存在
     * @date 2023/6/29 10:24
     */

    public static ResultSet selectToken(String token, String userName) {
        try {
            pstmt = conn.prepareStatement("select * from usr where token = ? and userName = ?");
            pstmt.setString(1, token);
            pstmt.setString(2, userName);
            return pstmt.executeQuery();
        } catch (Exception e) {
            e.printStackTrace();
            logger.info("查找token异常（当有此报错的时候，selectToken()的返回值为空）");
        }
        return null;
    }

    /**
     * @param userName: 用户名
     * @param password: 密码
     * @return ResultSet
     * @author Axing
     * @description 查询用户名和密码后返回一个对象如登录信息，权限等。参考com.example.loginService.LoginResult类
     * @date 2023/6/28 16:30
     */
    public static ResultSet selectUser(String userName, String password) {
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

    /**
     * @author Axing
     * @description 关闭数据库
     * @date 2023/6/28  16:36
     */
    public static void closeDB() {
        try {
            if (rs != null) rs.close();
            if (pstmt != null) pstmt.close();
            if (conn != null) conn.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}
