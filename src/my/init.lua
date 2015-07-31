require "socket"
require "my/extendsion/statement"
require "my/network/NetConfig"
require "SharedDataKey"

__G__TRACKBACK__ = function(msg)
   	local msg = debug.traceback(msg)
    print(msg)
    return msg
end