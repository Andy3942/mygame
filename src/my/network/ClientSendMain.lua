-- Author: 	bzx
-- Date: 	2015-07-31
-- Purpose: 客户端发送

-- cc.FileUtils:getInstance():setPopupNotify(false)
-- cc.FileUtils:getInstance():addSearchPath("src/")

-- require "config"
-- require "cocos.init"

require "cocos.cocos2d.functions"
require "my/init"

local function main()
	require("src/my/classload/ClassUtil")
	ClassUtil.openAutoload()
	local client = Client:create(CLIENT_HOST, CLIENT_PORT)
	client:startSend()
end

local status, msg = xpcall(main, __G__TRACKBACK__)