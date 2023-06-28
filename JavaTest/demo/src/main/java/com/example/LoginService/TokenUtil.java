package com.example.LoginService;

import com.example.connectDB.OperateDB;

import java.util.UUID;

public class TokenUtil {

    /**
     * @param user:
     * @return String
     * @author Axing
     * @description 根据用户输入的用户名，生成并返回一个对应的token（令牌）
     * @date 2023/6/28 16:26
     */
    public static String generateToken(String user) {
        //生成唯一不重复的字符串
        String token = UUID.randomUUID().toString();
        return token;
    }


    public static boolean verify(String token ){
        return OperateDB.selectToken(token) == null ? false : true;
    }

//    public static User gentUser(String token){
//        return tokenMap.get(token);
//    }


}
