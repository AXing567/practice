package com.example.demo;

import com.example.connectDB.OperateDB;
import com.google.gson.Gson;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;


@WebServlet("/LoginServlet")  //这是就是路由的配置
public class LoginServlet extends HttpServlet {
    @Override
    protected void service(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        Map<String, String> map = new HashMap<>();
        OperateDB operateDB = new OperateDB();
        request.setCharacterEncoding("utf-8");
        response.setContentType("text/html;charset=utf-8");
        String uname;
        String upwd;

        uname = "1";
        upwd = "123";
//        upwd = request.getParameter("upwd");
//        uname = request.getParameter("uname");
        map.put("checkCode", operateDB.check(uname, upwd).checkCode ? "1" : "0");
        map.put("checkMsg", operateDB.check(uname, upwd).msg);
        map.put("admin", "admin");
        map.put("user", "user");

//        将map转换为json并输出到前端
        Gson gson = new Gson();
        String userMap = gson.toJson(map);
        response.getWriter().write(userMap);

    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doPost(req, resp);
    }
}
