-- Author: 	bzx
-- Date: 	2015-06-12
-- Purpose: 网络层

local M = {}
package.seeall(M)
setfenv(1, M)
NetStatus = {
	CONNECTED = 1,
	CLOSED    = 2,
	SE
}

local _host 		= "127.0.0.1"--"www.baidu.com"
local _port 		= 8383--80
local _client
local _listeners 	= {}
local _net_status 	= NetStatus.CLOSED


function send(  )

	if _net_status == NetStatus.CLOSED then
		connect()
	end
	_client:send("GET / HTTP/1.0\r\n\r\n")
	
		
	-- while true  do
	-- 	local response, receive_status = _client:receive()
	-- 	print("receive return:",response or "nil" ,receive_status or "nil")
	-- 	if receive_status ~= "closed" then
	-- 		if response then
	-- 			print("receive:"..response)
	-- 		end
	-- 	else
	-- 		break
	-- 	end
	-- end
end

function connect( ... )
	_client = socket.tcp()
	local tag, err = _client:connect(_host, _port)
	print(string.format("connect: %s %d", _host, _port), tag, err)
	if 1 == tag then
		_net_status = NetStatus.CONNECTED
	else

	end
end

function setNetStatus( net_status )
	_net_status = net_status
	local s = switch(_net_status)
	s.case(NetStatus.CLOSED, function ( ... )
		broadcast("closed")
	end)
	s.case(NetStatus.CONNECTED)
	s.close()
end

function broadcast( event )
	local listeners = _listeners[event]
	if nil == listeners then
		return
	end
	for i = 1, #listeners do
		local listener = listeners[i]
		listener(event)
	end
end

function addListener( event, callback )
	_listeners[tag] = _listeners[tag] or {}
	table.insert(_listeners[tag], callback)
end

return M