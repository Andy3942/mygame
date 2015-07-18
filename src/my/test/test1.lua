require "socket"
local function hehe( ... )
	for i = 1, 10 do
		_G["hei2"] = _G["hei2"] or 0
		_G["hei2"] = _G["hei2"] + 1
		print("haha===", _G["hei2"])
		socket.sleep(3)
	end
end
hehe()