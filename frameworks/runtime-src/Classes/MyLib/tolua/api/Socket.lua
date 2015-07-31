
--------------------------------
-- @module Socket
-- @parent_module my

--------------------------------
-- 
-- @function [parent=#Socket] getError 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#Socket] receive 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- 
-- @function [parent=#Socket] getStrError 
-- @param self
-- @param #int err
-- @return char#char ret (return value: char)
        
--------------------------------
-- 
-- @function [parent=#Socket] send 
-- @param self
-- @param #char buff
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#Socket] init 
-- @param self
-- @param #int socket_type
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#Socket] connect 
-- @param self
-- @param #char host
-- @param #unsigned short port
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#Socket] close 
-- @param self
-- @return int#int ret (return value: int)
        
--------------------------------
-- 
-- @function [parent=#Socket] create 
-- @param self
-- @return Socket#Socket ret (return value: my.Socket)
        
return nil
