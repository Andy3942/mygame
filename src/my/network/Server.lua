local socket = require("socket")

server = socket.bind("127.0.0.1", 8383)
while true do
	print("等待客户端连接")
	control = server:accept();
	print("客户端连接成功")
	while true do 
		print("等待客户端发送数据")
	    local command,status = control:receive();
		print("接收到数据：", command, status);
		if status == "closed" then 
			break 
		end
		local tag, err = control:send("ok");
		print("send:", tag, err)
		-- socket.sleep(30)
		-- control:send("haha\n")
	end
end