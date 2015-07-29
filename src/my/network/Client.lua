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
	self._send_datas = nil
	self._receive_datas = nil
end

function M:create( host, port )
	local ret = Client.new(host, port)
	ret:init()
	return ret
end

function M:init( ... )
	local shared_data = my.DataManager:getInstance():getSharedData()
	self._send_datas = shared_data:at("send_datas")
	self._receive_datas = shared_data:at("receive_datas")
	self._client = socket.tcp()
end

function M:start( ... )
	print("开始启动客户端：", self._host, self._port)
	while true do
		local data_count = self._send_datas:size()
		if data_count == 0 then
			print("没有要发送的数据")
		else
			if self._net_status ~= NetStatus.CONNECTED then
				print("尚未建立连接，开始连接")
				self:connect()
			end
			if self._net_status == NetStatus.CONNECTED then
				local data = self._send_datas:at(0)
				local package = data:at("package")
				self:send(package)
			end
		end
		self:receive()
		socket.sleep(2)
	end
end

function M:send(package)
	self._client:send(package .. "\n")
	print("发送：", package)
end

function M:receive( ... )
	if self._net_status ~= NetStatus.CONNECTED then
		return
	end
	local package, status = self._client:receive()
	print("received:", package, status)
	if package ~= nil then
		local receive_data = my.Map:create()
		receive_data:insert("package", package)
		self._receive_datas:pushBack(receive_data)
	end
end

function M:connect( ... )
	local tag, err = self._client:connect(self._host, self._port, TIMEOUT)
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