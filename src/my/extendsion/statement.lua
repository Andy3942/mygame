-- switch
local Switch = class("Switch")

function Switch:ctor(value) 
	self._case_data = {}
	self._value = value
	self._default_func = nil
end

function Switch:case( condition, func)
	local case_data = {}
	case_data.condition = condition
	case_data.func = func
	self._case_data[condition] = case_data
end

function Switch:default(func)
	self._default_func = func
end
function Switch:close( ... )
	local func = self._case_data[self._value] or self._default_func
	if func ~= nil then
		func()
	end
end

function switch( value )
	return Switch.new(value)
end