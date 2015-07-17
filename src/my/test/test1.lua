require "socket"
local function hehe( ... )
	for i = 1, 10 do
		_G["hei"] = _G["hei"] or 0
		_G["hei"] = _G["hei"] + 1
		print("haha===", _G["hei"])
		socket.sleep(1)
	end
end
hehe()