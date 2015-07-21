require "socket"
local function hehe( ... )
	for i = 1, 10000 do
		-- _G["hei"] = _G["hei"] or ""
		-- _G["hei"] = _G["hei"] .. "+1"
		-- _G["hei"] = _G["hei"] .. "+2"
		-- _G["hei"] = _G["hei"] .. "+3"
		-- _G["hei"] = _G["hei"] .. "+4"
		-- _G["hei"] = _G["hei"] .. "+5\n"
		-- print("1====\n", _G["hei"])
		--socket.sleep(3)
		print("1=", i)
	end
end
hehe()