#ifndef __ECHOSERVER_HPP
#define __ECHOSERVER_HPP

#include<iostream>
#include<cstdlib>
#include<string>
#include <cstdint>
#include<strings.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include"logger.h"

const static int default_fd = -1;
const static int default_port = -1;

enum
{
    SUCCESS = 0,
    SOCKET_ERR,
    USAGE_ERR,
    BIND_ERR,
};

class UdpServer{
public:
    UdpServer(const std::string &ip, uint16_t port = default_port)
    :_sockfd(default_fd),
     _ip(ip),
     _port(port)
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

        //2.完善信息
        struct sockaddr_in local;
        bzero(&local, sizeof(local));
        local.sin_family = AF_INET;
        local.sin_addr.s_addr = inet_addr(_ip.c_str());
        local.sin_port = htons(_port);//h->n

        //3.bind socket 信息
        int n = bind(_sockfd, (struct sockaddr *)&local, sizeof(local));
        if(n < 0)
        {
            LOG_FATAL("bind suruct error");
            exit(BIND_ERR);
        }
        LOG_DEBUG("bind socket success, ip:" << _ip << ",port:" << _port);
    }
    void Loop(){}


private:
    int _sockfd;
    std::string _ip;
    uint16_t _port;

};

#endif