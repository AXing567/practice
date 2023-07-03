package com.example.LoginService;

import com.example.OperateDB.OperateDB;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.util.UUID;

public class TokenUtil {
    static Logger logger = LoggerFactory.getLogger(TokenUtil.class);
    /**
     * @param user:
     * @return String
     * @author Axing
     * @description 根据用户输入的用户名，生成并返回一个对应的token（令牌）并存入数据库
     * @date 2023/6/28 16:26
     */
    public static String generateToken(String user) {
        //生成唯一不重复的字符串
        String token = UUID.randomUUID().toString();
        //将token存入数据库
        if (OperateDB.update(token, user)) {
            logger.info("token存入数据库成功");
        } else {
            logger.error("token存入数据库失败");
        }
        return token;
    }
}