-- Author: 	bzx
-- Date: 	2015-07-31
-- Purpose: 客户端接收

require "cocos.cocos2d.functions"
require "my/init"

local function main()
	require("src/my/classload/ClassUtil")
	ClassUtil.openAutoload()
	local client = Client:create(CLIENT_HOST, CLIENT_PORT)
	client:startReceive()
end

local __G__TRACKBACK__ = function(msg)
    local msg = debug.traceback(msg)
    print(msg)
    return msg
end

local status, msg = xpcall(main, __G__TRACKBACK__)