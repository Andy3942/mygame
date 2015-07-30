//
//  MySocket.h
//  mygame
//
//  Created by bzx on 7/30/15.
//
//

#ifndef __mygame__MySocket__
#define __mygame__MySocket__

#include <iostream>

#ifdef OS_WIN32

#include <winsock.h>

#else

#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>

#endif


#include "MyMacros.h"

NS_MY_BEGIN

#define SOCKET_INVALID -1 

enum SocketType{
    TCP,
};

struct Protocol
{
    int family = AF_INET;
    int type = SOCK_STREAM;
    int flag = 0;
};

typedef int t_socket;


class Socket
{
public:
    static Socket* create(SocketType socket_type = TCP);
    bool init(SocketType socket_type);
    bool connet(const char* host, unsigned short port);
    bool send(const char* buff);
    std::string receive(unsigned int size = 8888);
    int close();
    int getError();
    const char* getStrError(int err);
private:
    Protocol _protocol;
    t_socket _socket;
};

NS_MY_END

#endif /* defined(__mygame__MySocket__) */
