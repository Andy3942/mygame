
-- cc.FileUtils:getInstance():setPopupNotify(false)
-- cc.FileUtils:getInstance():addSearchPath("src/")
-- cc.FileUtils:getInstance():addSearchPath("res/")

-- require "config"
-- require "cocos.init"
require "socket"
local function main()
	for i = 1, 10000 do
		-- print("fuck=====\n")
		-- print(hei)
		print("main==", i)
		--socket.sleep(1)
	end
	-- require("my/classload/ClassUtil")
	-- ClassUtil.openAutoload()
	-- --Network.send()
	-- local scene = display.newScene("MainScene")
	-- display.runScene(scene)

	-- local layer = display.newLayer()
	-- scene:addChild(layer)

	-- --local layout = ccs.GUIReader:getInstance():widgetFromJsonFile("UITest/UITest.json")
	-- local layout = ccs.GUIReader:getInstance():widgetFromBinaryFile("csb/TestScene.csb")
 --    print(layout)
 --    layer:addChild(layout)

 -- --    require("app.MyApp"):create():run()
 print("fuck")
end

main()

-- local status, msg = xpcall(main, __G__TRACKBACK__)
-- if not status then
--     print(msg)
-- end
