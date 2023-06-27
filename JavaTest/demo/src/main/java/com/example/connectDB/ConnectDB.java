package com.example.connectDB;

import java.sql.*;

public class ConnectDB {
    private Connection conn ;
    private Statement stmt;
    private ResultSet rs ;
    private  String url="jdbc:mysql://localhost:3306/school";

    public void setRs(ResultSet rs) {
        this.rs = rs;
    }

    public Connection getConn() {
        return conn;
    }

    public Statement getStmt() {
        return stmt;
    }

    public ResultSet getRs() {
        return rs;
    }

    public String getUrl() {
        return url;
    }

    public void openCon() throws SQLException, ClassNotFoundException {
        Class.forName("com.mysql.jdbc.Driver");
        conn = DriverManager.getConnection(url,"root","123");
        stmt = conn.createStatement();

    }
    public void closeCon() throws SQLException {
        rs.close();
        stmt.close();
        conn.close();
    }
}
