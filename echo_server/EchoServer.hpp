#ifndef __ECHOSERVER_HPP
#define __ECHOSERVER_HPP

#include<iostream>
#include<cstdlib>
#include<sys/socket.h>
#include"logger.h"

const static int default_fd = -1;

enum
{
    SUCCESS = 0,
    SOCKET_ERR,
};

class UdpServer{
public:
    UdpServer():_sockfd(default_fd)
    {}
    ~UdpServer(){}
    void Init()
    {
        //1.创建socket,本质：打开网卡
        _sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        if(_sockfd < 0)
        {
            LOG_FATAL("creat socket error");
            exit(SOCKET_ERR);
        }
        LOG_INFO("create socket success, sockfd");
    }
    void Loop(){}


private:
    int _sockfd;
};

#endif