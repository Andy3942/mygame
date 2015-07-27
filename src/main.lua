
--cc.FileUtils:getInstance():setPopupNotify(false)
cc.FileUtils:getInstance():addSearchPath("src/")
cc.FileUtils:getInstance():addSearchPath("res/")
cc.FileUtils:getInstance():addSearchPath("res/images")

require "config"
require "cocos.init"
require "my/init"

local function main()
	require("my/classload/ClassUtil")
	ClassUtil.openAutoload()
	
	-- local script_manager = my.ScriptManager:getInstance()
	-- script_manager:asyncExecuteScriptFile("my/network/ClientStart.lua", 3)

	local scene = cc.Scene:create()
	local diretor = cc.Director:getInstance()
	diretor:runWithScene(scene)

	local test_layer = cc.CSLoader:createNode("csb/TestLayer.csb")
	local send_message_btn = test_layer:getChildByName("sendMessageBtn")


	local function previousCallback(sender, eventType)
        if eventType == ccui.TouchEventType.ended then
            print("点击了。。。。。。")
        end
    end

    local left_button = root:getChildByName("left_Button")
    send_message_btn:addTouchEventListener(previousCallback)

	if test_layer == nil then
		print("没道理")
	end
	scene:addChild(test_layer)



	sendMessageBtn


	-- local time = os.clock()
	-- -- local hehe = my.Map:create()
	-- -- for i=1,10000 do
	-- -- 	hehe:insert("1234", 2342)
	-- -- 	hehe:at("1234")
	-- -- end
	-- 		require "src/my/test/skill.lua"
	-- for i = 1,100000 do

	-- 	local hehe = skill.getDataById(192073)
	-- 	--package.loaded["src/my/test/skill.lua"] = nil
	-- end
	-- print("fuck================", os.clock() - time)


	-- local time = os.clock()
	-- -- local hehe = my.Map:create()
	-- -- for i=1,10000 do
	-- -- 	hehe:insert("1234", 2342)
	-- -- 	hehe:at("1234")
	-- -- end
	-- 		skill2 = require "src/my/test/skill2.lua"
	-- for i = 1,100000 do

	-- 	local hehe = skill2.getDataById(192073)
	-- 	--package.loaded["src/my/test/skill2.lua"] = nil
	-- end
	-- print("fuck2================", os.clock() - time)




	--my.ScriptManager:getInstance():asyncExecuteScriptFile("src/my/test/test1.lua", 1)
	-- lock()
	-- for i=1, 1000 do
	-- 	print("====111111111111111111111111===")
	-- end
	-- unlock()

	-- -- require("my/classload/ClassUtil")
	-- -- ClassUtil.openAutoload()
	-- -- --Network.send()
	-- -- local scene = display.newScene("MainScene")
	-- -- display.runScene(scene)

	-- -- local layer = display.newLayer()
	-- -- scene:addChild(layer)

	-- -- --local layout = ccs.GUIReader:getInstance():widgetFromJsonFile("UITest/UITest.json")
	-- -- local layout = ccs.GUIReader:getInstance():widgetFromBinaryFile("csb/TestScene.csb")
 -- --    print(layout)
 -- --    layer:addChild(layout)

 -- -- --    require("app.MyApp"):create():run()
 -- print("fuck")
end

local __G__TRACKBACK__ = function(msg)
    local msg = debug.traceback(msg, 3)
    print(msg)
    return msg
end

local status, msg = xpcall(main, __G__TRACKBACK__)
