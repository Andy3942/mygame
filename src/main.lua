
cc.FileUtils:getInstance():setPopupNotify(false)
cc.FileUtils:getInstance():addSearchPath("src/")
cc.FileUtils:getInstance():addSearchPath("res/")

require "config"
require "cocos.init"

local function main()
	require("my/classload/ClassUtil")
	ClassUtil.openAutoload()
	--Network.send()
	local scene = display.newScene("MainScene")
	display.runScene(scene)

	local layer = display.newLayer()
	scene:addChild(layer)

	--local layout = ccs.GUIReader:getInstance():widgetFromJsonFile("UITest/UITest.json")
	local layout = ccs.GUIReader:getInstance():widgetFromBinaryFile("csb/TestScene.csb")
    print(layout)
    layer:addChild(layout)

 --    require("app.MyApp"):create():run()
end

local status, msg = xpcall(main, __G__TRACKBACK__)
if not status then
    print(msg)
end
