package com.example.servlet;

import com.example.LoginService.Login;
import com.example.OperateDB.OperateDB;
import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

@WebServlet("/LoginServlet")  //路由的配置
public class LoginServlet extends HttpServlet {
    //    日志记录器
    final Logger logger = LoggerFactory.getLogger(LoginServlet.class);

    @Override
    protected void service(HttpServletRequest request, HttpServletResponse response) throws IOException {

//        设置编码格式
        request.setCharacterEncoding("utf-8");
        response.setContentType("text/html;charset=utf-8");

        logger.info("LoginServlet已启动");
//        链接数据库
        OperateDB.connect();

//        获取前端传来的数据
        StringBuilder requestBody = new StringBuilder();
        BufferedReader reader = request.getReader();
        String line;
        while ((line = reader.readLine()) != null) {
            requestBody.append(line);
        }
        reader.close();

//        创建用于返回map的对象、用于处理json相关的对象
        Map<String, Object> map = new HashMap<>();
        Gson gson = new Gson();

//        首先  判断是否有输入用户名和密码
        if (requestBody.toString().equals("")) {
            map.put("checkCode", Login.Result(false, "没有输入用户名和密码", 0, "000000000000000000000000000000000000"));
            response.getWriter().write(gson.toJson(map));
            logger.info("没有输入用户名和密码");
        } else {
//            然后  判断是否存在此用户
            /*map = gson.fromJson(requestBody.toString(), new TypeToken<Map<String, Object>>(){}.getType());
            使用了TypeToken技术，它创建了一个匿名内部类，继承了TypeToken类，并实现了getType()方法，
            用于获取泛型类型的具体类型信息。这样做可以确保在类型转换时，Gson库可以正确地解析JSON字符串，
            并将其转换为正确的泛型类型。这种方式可以避免类型擦除的问题。*/
            map = gson.fromJson(requestBody.toString(), new TypeToken<Map<String, Object>>() {
            }.getType());
            String userName = map.get("userName").toString();
            String password = map.get("password").toString();
            String token = map.get("token").toString();

            if (OperateDB.selectToken(token, userName)) {
                map.put("checkCode", Login.login(userName, password));
                logger.info("token验证成功");
            }
//            最后  根据数据库，检测是否登录成功，并返回结果至客户端
            map.put("checkCode", Login.login(userName, password));
            /*将map转换为json并输出到前端*/
            response.getWriter().write(gson.toJson(map));
            logger.info("信息已返回至客户端（含成功及失败）");
        }
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        doPost(req, resp);
    }

    @Override
    public void destroy() {
        /*关闭数据库连接*/
//        OperateDB.closeDB();
        super.destroy();
        logger.info("LoginServlet已销毁");
    }

}
