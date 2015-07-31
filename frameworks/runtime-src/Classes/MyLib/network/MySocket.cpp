//
//  MySocket.cpp
//  mygame
//
//  Created by bzx on 7/30/15.
//
//

#include "MySocket.h"


NS_MY_BEGIN

Socket* Socket::create(SocketType socket_type/*=TCP*/)
{
    auto ret = new(std::nothrow) Socket();
    ret->init(socket_type);
    return ret;
}

bool Socket::init(SocketType socket_type)
{
    switch (socket_type)
    {
        case SocketType::TCP:
            break;
        default:
            break;
    }
    _socket = socket(_protocol.family, _protocol.type, _protocol.flag);
    if(_socket == SOCKET_INVALID)
    {
        return false;
    }
    return true;
}

bool Socket::connect(const char* host, unsigned short port)
{
    struct addrinfo connecthints;
    memset(&connecthints, 0, sizeof(connecthints));
    connecthints.ai_socktype = _protocol.type;
    connecthints.ai_family = _protocol.family;
    struct addrinfo *resolved = NULL;
    
    char port_str[10];
    sprintf(port_str, "%u", port);
    getaddrinfo(host, port_str, &connecthints, &resolved);
    if(::connect(_socket, resolved->ai_addr, resolved->ai_addrlen) == 0)
    {
        return true;
    }
    return false;
}

bool Socket::send(const char* buff)
{
    unsigned int size =  strlen(buff);
    if (::send(_socket, buff, size, _protocol.flag) >= 0) 
    {
        return true;
    }
    return false;
}

std::string Socket::receive(unsigned int size)
{
    char* buff = (char*)malloc(size);
    int len = recv(_socket, buff, size, _protocol.flag);
    if(len > 0)
    {
        return buff;
    }
    return nullptr;
}

int Socket::close()
{
#ifdef OS_WIN32
    return closesocket(_socket);
#else
    return ::close(_socket);
#endif
}

int Socket::getError()
{
#ifdef OS_WIN32
    return WSAGetLastError();
#else
    return errno;
#endif
}

const char* Socket::getStrError(int err)
{
    return strerror(err);
}

NS_MY_END

