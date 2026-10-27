--package.path = "../myLuaTest/myLuaCode/?.lua;"..package.path
print(string.format("path=%s", package.path))
print(string.format("cpath=%s", package.cpath))
require("LuaPanda").start("127.0.0.1", 8818)

print("hello world")
