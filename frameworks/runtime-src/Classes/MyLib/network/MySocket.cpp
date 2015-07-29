//
//  MySocket.cpp
//  mygame
//
//  Created by bzx on 7/29/15.
//
//

#include <sys/socket.h>
#include <sys/fcntl.h>

#include "MySocket.h"

NS_MY_BEGIN

Socket* Socket::create(SocketType socket_type)
{
    auto ret = new(std::nothrow) Socket();
    if(ret->initWithTCP())
    {
        return ret;
    }
    return nullptr;
}

bool Socket::initWithTCP()
{
    _socket = socket(AF_INET, SOCK_STREAM, 0);
    if(_socket != SOCKET_INVALID)
    {
        setBlock(true);
        return true;
    }else
    {
        return false;
    }
}

bool Socket::connect(const char* ip, unsigned short port)
{
    
}

void Socket::setBlock(bool is_block)
{
    int flags = fcntl(_socket, F_GETFL, 0);
    if(is_block)
    {
        flags &= (~(O_NONBLOCK));
    }else
    {
        flags |= O_NONBLOCK;
    }
    fcntl(_socket, F_SETFL, flags);
    
}

int Socket::getError()
{
#ifdef OS_WIN32
    return WSAGetLastError();
#else
    return errno;
#endif
}

const char* Socket::socketStrerror(int err)
{
    if (err <= 0)
    {
        return IOStrerror(err);
    }
    switch (err) {
        case EADDRINUSE: return "address already in use";
        case EISCONN: return "already connected";
        case EACCES: return "permission denied";
        case ECONNREFUSED: return "connection refused";
        case ECONNABORTED: return "closed";
        case ECONNRESET: return "closed";
        case ETIMEDOUT: return "timeout";
        default: return strerror(err);
    }
}

const char* Socket::IOStrerror(int err)
{
     switch (err) {
        case IOType::DONE: return NULL;
        case IOType::CLOSED: return "closed";
        case IOType::TIMEOUT: return "timeout";
        default: return "unknown error"; 
    }
}

NS_MY_END