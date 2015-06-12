-- Author: 	bzx
-- Date: 	2015-06-12
-- Purpose: 网络层

local moduleName = ...
local M = {}
rawset(_G, moduleName, M)
package.seeall(M)
setfenv(1, M)

function send(  )
	print(socket._VERSION)
end

return