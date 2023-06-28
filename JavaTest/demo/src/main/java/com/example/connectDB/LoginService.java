package com.example.connectDB;

import java.sql.*;

public class LoginService {
//    根据用户名和密码查询用户信息
    public LoginResult login(String userName, String password) {
        LoginResult result = new LoginResult();

        // 连接数据库
        Connection conn = null;
        try {
            Class.forName("com.mysql.jdbc.Driver");
            conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/school", "root", "123");
        } catch (SQLException | ClassNotFoundException e) {
            result.setSuccess(false);
            result.setMessage("数据库连接失败");
            result.setPermission(0);
            return result;
        }

        // 查询用户信息
        PreparedStatement ps = null;
        ResultSet rs = null;
        try {
            ps = conn.prepareStatement("SELECT * FROM user WHERE userName = ? AND password = ?");
            ps.setString(1, userName);
            ps.setString(2, password);
            rs = ps.executeQuery();
            if (rs.next()) {
                result.setSuccess(true);
                result.setMessage("登录成功");
                result.setPermission(rs.getInt("permission"));
            } else {
                result.setSuccess(false);
                result.setMessage("用户名或密码错误");
                result.setPermission(0);
            }
        } catch (SQLException e) {
            result.setSuccess(false);
            result.setMessage("数据库查询失败");
            result.setPermission(0);
        } finally {
            // 关闭数据库连接
            try {
                if (rs != null) rs.close();
                if (ps != null) ps.close();
                if (conn != null) conn.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
        return result;
    }
//    用户名或密码为空时返回的结果
    public LoginResult LoginResultFalse() {
        LoginResult result = new LoginResult();
        result.setSuccess(false);
        result.setMessage("用户名及密码不能为空");
        result.setPermission(0);
        return result;
    }
}

class LoginResult {
    private boolean success; // 是否成功
    private String message; // 登录信息
    private int permission; // 用户权限
    public String toString() {
        return "LoginResult [success=" + success + ", message=" + message + ", permission=" + permission + "]";
    }

    public boolean isSuccess() {
        return success;
    }

    public void setSuccess(boolean success) {
        this.success = success;
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }

    public int getPermission() {
        return permission;
    }

    public void setPermission(int permission) {
        this.permission = permission;
    }
}
