local M = {}
rawset(_G, "ClassUtil", M)
package.seeall(M)
setfenv(1, M)

function openAutoload( ... )
	local mt = getmetatable(_G)
	mt = mt or {}
	local class_path = require("my/classload/ClassPath")
	mt.__index = function ( t, k )
		local class_name = k
		local class_path = class_path[class_name]
		if nil == class_path then
			return nil
		end
		print(class_name, class_path, "hehe")
		local class = require(class_path)
		rawset(_G, class_name, class)
		return class
	end
end