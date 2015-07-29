NetStatus = {
	CONNECTED = 1,
	CLOSED    = 2,
}

CLIENT_HOST 		= "127.0.0.1"--"www.baidu.com"
CLIENT_PORT 		= 8383--80

TIMEOUT 			= 40      -- 接收数据超时限制
RECEIVE_INTERVAL 	= 0.03    -- 定时接收后端数据的时间间隔（单位：秒）