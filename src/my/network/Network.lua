-- Author: 	bzx
-- Date: 	2015-06-12
-- Purpose: 网络层

local class_name = "Network"
local M = class(class_name)
rawset(_G, class_name, M)

local _listeners 		= {}
local _net_status 		= NetStatus.CLOSED
local _push_handlers 	= {}

function M:init( ... )
	local shared_data = my.DataManager:getInstance():getSharedData()
	self._send_datas = my.Vector:create()
	shared_data:insert("send_datas", self._send_datas)
	self._receive_datas = my.Vector:create()
	shared_data:insert("receive_datas", self._receive_datas)
	local client = socket.tcp()
	shared_data:insert("client", client)
	print("Network:init==", client, tostring(client), type(client), tolua.type(client))
end

function M:send(package, handler)
	local data = my.Map:create()
	data:insert("package", package)
	data:insert("handler", handler)
	self._send_datas:pushBack(data)
end

function M:startReceive( ... )
	local receiveFunc = function ( ... )
		self:receive()
	end
	local scheduler = cc.Director:getInstance():getScheduler()
	scheduler:scheduleScriptFunc(receiveFunc, RECEIVE_INTERVAL, false)
end

function M:receive( ... )
	local receive_count = self._receive_datas:size()
	if receive_count == 0 then
		return
	end
	local receive_data = self._receive_datas:at(0)
	local package = receive_data:at("package")
	package = self:parse(package)
	local push_handler = _push_handlers[package.tag]
	if push_handler ~= nil then 
		push_handler()
	else
		local send_data = self._send_datas:at(0)
		local handler = send_data:at("handler")
		handler(package)
		self._send_datas:erase(0)
		self._receive_datas:erase(0)
	end
end

function M:re_push( push_tag, handler )
	_push_handlers[push_tag] = handler
end

function M:pack( package )
	-- TODO
end

function M:parse( package )
	local ret = {
		tag = "push",
		data = "haha",
	}
	return ret
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