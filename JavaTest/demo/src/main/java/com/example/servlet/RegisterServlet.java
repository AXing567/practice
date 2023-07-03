package com.example.servlet;

import com.example.LoginService.TokenUtil;
import com.example.OperateDB.OperateDB;
import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

/**
 * @projectName: demo
 * @package: com.example.servlet
 * @className: RegisterServlet
 * @author: Axing
 * @description: 注册功能
 * @date: 2023/6/30 14:18
 * @version: 1.0
 */
@WebServlet("/RegisterServlet")
public class RegisterServlet extends HttpServlet {
    final Logger logger = LoggerFactory.getLogger(LoginServlet.class);

    @Override
    protected void service(HttpServletRequest request, HttpServletResponse response) throws IOException {
        request.setCharacterEncoding("utf-8");
        response.setContentType("text/html;charset=utf-8");
        logger.info("RegisterServlet已启动");
        OperateDB.connect();

//        获取前端传来的数据
        StringBuilder requestBody = new StringBuilder();
        BufferedReader reader = request.getReader();
        String line;
        while ((line = reader.readLine()) != null) {
            requestBody.append(line);
        }
        reader.close();
        logger.info("接收前端数据成功");
        logger.info(requestBody.toString());


        Map<String, Object> map = new HashMap<>();
        Gson gson = new Gson();

//        判断是否有数据传入服务器
        if (requestBody.toString().equals("")) {
            response.getWriter().write("这是注册页面，请发送点数据过来，不能发送空数据");
            logger.info("页面未发送数据至注册接口");
        } else {
//            将前端传来的数据转换为变量
            map = gson.fromJson(requestBody.toString(), new TypeToken<Map<String, Object>>() {
            }.getType());
            String name = map.get("name").toString();
            String mobilePhone = map.get("mobilePhone").toString();
            String password = map.get("password").toString();
            String userName = map.get("userName").toString();
            String token = TokenUtil.generateToken(userName);

//              新建/存储用户信息
            OperateDB.insertUser(name, mobilePhone, userName, password, token);

//              将此用户的token返回给前端
            map.put("token", token);
            response.getWriter().write(gson.toJson(map));
            logger.info("返回token成功");

        }
    }
}
