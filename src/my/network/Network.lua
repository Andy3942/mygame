-- Author: 	bzx
-- Date: 	2015-06-12
-- Purpose: 网络层

local M = {}
package.seeall(M)
setfenv(1, M)

local host = "www.baidu.com"
local port = 80
-- local server = socket.bind(host, port)
-- local client = server:accept()

function send(  )

	local tcp = socket.tcp()
	local n, e = tcp:connect(host, port)
	print(n, e)
	tcp:send("GET / HTTP/1.0\r\n\r\n")
	while true  do
		local response, receive_status=tcp:receive()
		print("receive return:",response or "nil" ,receive_status or "nil")
		if receive_status ~= "closed" then
			if response then
				print("receive:"..response)
			end
		else
			break
		end
	end
	  -- client:send("STEP\n")
	  -- local hehe = client:receive()
	  -- print(hehe)
	  -- print("========")
	  -- local breakpoint = client:receive()
	  -- print(breakpoint)

		-- local http = require("socket.http")
		-- local response = http.request("http://www.baidu.com/")
		-- print(response)

end



return M