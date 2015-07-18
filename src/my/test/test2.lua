require "socket"

function haha( ... )
	for i = 1, 10 do
		_G["hei"] = _G["hei"] or 0
		_G["hei"] = _G["hei"] + 1
		print("h3h3===", _G["hei"])
		socket.sleep(3)
	end
end
haha()