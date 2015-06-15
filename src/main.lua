
cc.FileUtils:getInstance():setPopupNotify(false)
cc.FileUtils:getInstance():addSearchPath("src/")
cc.FileUtils:getInstance():addSearchPath("res/")

require "config"
require "cocos.init"

local function main()
	require("my/classload/ClassUtil")
	ClassUtil.openAutoload()
	Network.send()
	Network.send()
	-- require "my.network.Network"
	-- Network.send()
 --    require("app.MyApp"):create():run()
end

local status, msg = xpcall(main, __G__TRACKBACK__)
if not status then
    print(msg)
end
