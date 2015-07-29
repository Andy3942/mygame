
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
	client:start()
end

local __G__TRACKBACK__ = function(msg)
    local msg = debug.traceback(msg)
    print(msg)
    return msg
end

local status, msg = xpcall(main, __G__TRACKBACK__)