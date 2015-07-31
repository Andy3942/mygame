-- Author: 	bzx
-- Date: 	2015-07-27
-- Purpose: 客户端

local class_name = "Client"
local M = class(class_name)
rawset(_G, class_name, M)

function M:ctor( host, port )
	self._host = host
	self._port = port
	self._client = nil
	self._wait_send_datas = nil
	self._received_datas = nil
end

function M:create( host, port )
	local ret = Client.new(host, port)
	ret:init()
	return ret
end

function M:init( ... )
	self._shared_data = my.DataManager:getInstance():getSharedData()
	self._wait_send_datas = self._shared_data:at(WAIT_SEND_DATAS)
	self._received_datas = self._shared_data:at(RECEIVED_DATAS)	
	-- self._wait_receive_datas = shared_data:at(WAIT_RECEIVE_DATAS)
	self._client = self._shared_data:at(CLIENT)
end

function M:startSend( ... )
	print("启动发送线程：", self._host, self._port)
	while true do
		while self:getNetStatus() ~= NetStatus.CONNECTED do
			print("尚未建立连接，开始连接")
			self:connect()
		end
		local data_count = self._wait_send_datas:size()
		if data_count == 0 then
			print("没有要发送的数据")
		else
			if self:getNetStatus() == NetStatus.CONNECTED then
				self:send()
			end
		end
		socket.sleep(0.1)
	end
end

function M:startReceive( ... )
	print("启动接收线程：", self._host, self._port)
	while true do
		self:receive()
	end
end

function M:send()
	local data = self._wait_send_datas:at(0)
	local package = data:at("package")
	local ret = self._client:send(package .. "\n")
	print("发送：", package, ret)
	if ret then
		self._wait_send_datas:erase(0)
	end
end

function M:receive( ... )
	print("等待接收")
	if self:getNetStatus() ~= NetStatus.CONNECTED then
		return
	end
	local package = self._client:receive()
	print("received:", package)
	if package ~= nil then
		local receive_data = my.Map:create()
		receive_data:insert("package", package)
		self._received_datas:pushBack(receive_data)
	end
end

function M:connect( ... )
	local ret = self._client:connect(self._host, self._port)
	print(string.format("connect: %s %d", self._host, self._port), tag, err)
	if ret then
		self:setNetStatus(NetStatus.CONNECTED)
	else
	end
end

function M:setNetStatus( net_status )
	self._shared_data:insert(NET_STATUS, net_status)
end

function M:getNetStatus( ... )
	return self._shared_data:at(NET_STATUS)
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