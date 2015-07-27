-- Author: 	bzx
-- Date: 	2015-06-12
-- Purpose: 网络层

local class_name = "Network"
local M = class(class_name)
rawset(_G, class_name, M)

local _host 		= "127.0.0.1"--"www.baidu.com"
local _port 		= 8383--80
local _client
local _listeners 	= {}
local _net_status 	= NetStatus.CLOSED


function M:send(data)
	local shared_data = my.DataManager:getInstance():getSharedData()
	local send_datas = shared_data:at("send_datas")
	if send_datas == nil then
		send_datas = my.Vector:create()
		shared_data:insert("send_datas", send_datas)
	end
	local map_data = my.Map:create()
	map_data:insert("text", "12312111====")
	send_datas:pushBack(map_data)
end

function M:connect( ... )
	_client = socket.tcp()
	local tag, err = _client:connect(_host, _port)
	print(string.format("connect: %s %d", _host, _port), tag, err)
	if 1 == tag then
		_net_status = NetStatus.CONNECTED
	else

	end
end

function M:setNetStatus( net_status )
	_net_status = net_status
	local s = switch(_net_status)
	s.case(NetStatus.CLOSED, function ( ... )
		broadcast("closed")
	end)
	s.case(NetStatus.CONNECTED)
	s.close()
end

function M:broadcast( event )
	local listeners = _listeners[event]
	if nil == listeners then
		return
	end
	for i = 1, #listeners do
		local listener = listeners[i]
		listener(event)
	end
end

function M:addListener( event, callback )
	_listeners[tag] = _listeners[tag] or {}
	table.insert(_listeners[tag], callback)
end

return M