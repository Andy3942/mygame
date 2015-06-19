local socket = require("socket")

server = socket.bind("127.0.0.1", 8383)
control = server:accept();
while true do 
    command,status = control:receive();
	if status == "closed" then 
		break 
	end
	print(command);
	control:send("hehe");
end