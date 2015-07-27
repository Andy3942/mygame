local class_name = "ClassUtil"
local M = class(class_name)
rawset(_G, class_name, M)
package.seeall(M)
setfenv(1, M)

function openAutoload( ... )
	print("openAutoload======")
	local mt = getmetatable(_G)
	if mt == nil then
		mt = {}
		setmetatable(_G, mt)
	end
	local class_path = require("my/classload/ClassPath")
	mt.__index = function ( t, k )
		print("kkkk===", k)
		local class_name = k
		local class_path = class_path[class_name]
		if nil == class_path then
			return nil
		end
		print("class_name==", class_name, class_path, "hehe")
		local class = require(class_path)
		rawset(_G, class_name, class)
		return class
	end
end