-- Author: 	bzx
-- Date: 	2015-06-12
-- Purpose: 网络层

local class_name = "Network"
local M = class(class_name)
rawset(_G, class_name, M)

local _listeners 			= {}
local _net_status 			= NetStatus.CLOSED
local _push_handlers 		= {}
local _received_handlers 	= {}

function M:init( ... )
	self._shared_data = my.DataManager:getInstance():getSharedData()
	self._wait_send_datas = my.Vector:create()
	self._shared_data:insert(WAIT_SEND_DATAS, self._wait_send_datas)
	self._received_datas = my.Vector:create()
	self._shared_data:insert(RECEIVED_DATAS, self._received_datas)
	-- self._wait_receive_datas = my.Vector:create()
	-- shared_data:insert(WAIT_RECEIVE_DATAS, self._wait_receive_datas)
	local client = my.Socket:create()
	self._shared_data:insert(CLIENT, client)
end

function M:send(package, handler)
	local data = my.Map:create()
	data:insert("package", package)
	self._wait_send_datas:pushBack(data)
	table.insert(_received_handlers, handler)
end

function M:startReceive( ... )
	local receiveFunc = function ( ... )
		self:receive()
	end
	local scheduler = cc.Director:getInstance():getScheduler()
	scheduler:scheduleScriptFunc(receiveFunc, RECEIVE_INTERVAL, false)
end

function M:receive( ... )
	local received_count = self._received_datas:size()
	if received_count == 0 then
		return
	end
	local received_data = self._received_datas:at(0)
	local package = received_data:at("package")
	package = self:parse(package)
	local push_handler = _push_handlers[package.tag]
	if push_handler ~= nil then 
		push_handler()
	else
		local handler = _received_handlers[1]
		handler(package)
		self._received_datas:erase(0)
		table.remove(_received_handlers, 1)
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