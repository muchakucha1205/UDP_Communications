#ifndef _SIMPLE_UDP_HPP_
#define _SIMPLE_UDP_HPP_
#include <stdio.h>
#include <iostream>
#include <string>
#include <WinSock2.h> //windows
#include <Windows.h>

#define BUFFER_MAX 400

class simple_udp{
    int sock;
    struct sockaddr_in addr;

public:
    simple_udp(std::string address, int port){
        WSAData wsaData;
        WSAStartup(MAKEWORD(2, 0), &wsaData);
        sock = socket(AF_INET, SOCK_DGRAM, 0);
        addr.sin_port = htons(port);
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = inet_addr(address.c_str());
    }

    void udp_send(std::string word){
        std::cout << word << std::endl;
        sendto(sock, word.c_str(), word.length(), 0, (struct sockaddr *)&addr, sizeof(addr));
    }

    // void udp_send(float array){
    //     sendto(sock, word.c_str(), word.length(), 0, (struct sockaddr *)&addr, sizeof(addr));
    // }

    void udp_bind(){
        bind(sock, (const struct sockaddr *)&addr, sizeof(addr));
    }

    std::string udp_recv(){
        char buf[BUFFER_MAX];
        memset(buf, 0, sizeof(buf));
        recv(sock, buf, sizeof(buf), 0);
        return std::string(buf);
    }

    void udp_recv(char *buf, int size){
        memset(buf, 0, size);
        recv(sock, buf, size, 0);
    }

    ~simple_udp(){
        closesocket(sock);
        WSACleanup();
    }
    
};

#endif