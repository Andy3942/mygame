-- Author: 	bzx
-- Date: 	2015-07-27
-- Purpose: 客户端

local class_name = "Client"
local M = class(class_name)
rawset(_G, class_name, M)

function M:ctor( host, port )
	self._host = host
	self._port = port
	self._net_status = NetStatus.CLOSED
	self._client = nil
end

function M:create( host, port )
	local ret = Client.new(host, port)
	return ret
end

function M:start( ... )
	print("开始启动客户端：", self._host, self._port)
	local shared_data = my.DataManager:getInstance():getSharedData()
	while true do
		local send_datas = shared_data:at("send_datas")
		if send_datas == nil then
			print("send_data 没有数据")
		else
			local data = send_datas:at(0)
			print(data:at("text"))
		end
		socket.sleep(3)
	end
end

function M:send(data)
	print("发送数据")
	if self._net_status == NetStatus.CLOSED then
		print("尚未建立连接，开始连接")
		connect()
		print("连接成功")
	end
	self._client:send(data)
	
		
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

function M:connect( ... )
	self._client = socket.tcp()
	local tag, err = _client:connect(self._host, self._port)
	print(string.format("connect: %s %d", self._host, self._port), tag, err)
	if 1 == tag then
		self._net_status = NetStatus.CONNECTED
	else

	end
end

function M:setNetStatus( net_status )
	self._net_status = net_status
	local s = switch(self._net_status)
	s.case(NetStatus.CLOSED, function ( ... )
		broadcast("closed")
	end)
	s.case(NetStatus.CONNECTED)
	s.close()
end

function M:broadcast( event )
	-- local listeners = _listeners[event]
	-- if nil == listeners then
	-- 	return
	-- end
	-- for i = 1, #listeners do
	-- 	local listener = listeners[i]
	-- 	listener(event)
	-- end
end

return M