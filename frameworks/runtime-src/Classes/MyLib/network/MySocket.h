//
//  MySocket.h
//  mygame
//
//  Created by bzx on 7/29/15.
//
//

#ifndef __mygame__MySocket__
#define __mygame__MySocket__

#include <iostream>
#include "MyMacros.h"

#define SOCKET_INVALID  -1

NS_MY_BEGIN

typedef enum{
    TCP = 1,
}SocketType;

typedef enum {
    DONE = 0,        /* operation completed successfully */
    TIMEOUT = -1,    /* operation timed out */
    CLOSED = -2,     /* the connection has been closed */
	UNKNOWN = -3     
}IOType;

typedef int t_socket;


class Socket
{
public:
    static Socket* create(SocketType socket_type);
    bool initWithTCP();
    
    bool connect(const char* ip, unsigned short port);
    
    void setBlock(bool is_block);
    int getError();
    static const char* socketStrerror(int err);
    static const char* IOStrerror(int err);
private:
    t_socket _socket;
};

NS_MY_END

#endif /* defined(__mygame__MySocket__) */
