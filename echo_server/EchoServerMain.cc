#include"EchoServer.hpp"
#include<memory>

static void Usage(const std::string process)
{
    std::cerr << "Usage:\n\t";
    std::cerr << process << "local ip local port" << std::endl;
}

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        Usage(argv[0]);
        exit(USAGE_ERR);
    }

    std::string server_ip = argv[1];
    uint16_t server_port = std::stoi(argv[2]);
    std::unique_ptr<UdpServer> usvr = std::make_unique<UdpServer>(server_ip, server_port);
    usvr->Init();
    usvr->Loop(); 
    return 0;
}