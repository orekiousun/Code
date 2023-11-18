-----------------------------------------------------------------------
-- 点击运行按钮右侧的'Lua'按钮执行'Execute'测试方法，可在运行时修改该脚本
-----------------------------------------------------------------------

--region ------------- Header -------------

local Launcher = require("Launcher")
local LuaEditorApi = require("LuaEditorApi")
local Logger = require("Logger")

local Log = Logger and Logger.Error or _print_e

---@class FastLuaTest
local FastLuaTest = {}

--endregion ------------- Header -------------

---执行
function FastLuaTest.Execute1()
    Log(GL.Data.Gamer.backDrop)
end

---执行2
function FastLuaTest.Execute2()
    for _, v in pairs(GL.Model.ModelPvpFight.gamers) do
        if v.gid == GL.Data.Gamer.id then
            Log(v)
        end
    end
end

---执行3
function FastLuaTest.Execute3()
end

--region ------------- Inner -------------

---@private
function FastLuaTest.Dispatch(eventName, param)
    GL.File.LuaEvent.Dispatch(eventName, param)
end

---@private
function FastLuaTest.PushWindow(wndName)
    local wndCls = GL.UI.WindowClass.CreateParam()
    wndCls.wndName = wndName
    GL.UI.UIStack.PushWindow(wndCls)
end

---重载
function FastLuaTest.Reload()
    package.loaded = {}
    package.preload = {}
    require("Launcher")
    --local list = {
    --    "PotentialRecommendWindow"
    --}
    --for _, v in ipairs(list) do
    --    package.loaded[v] = nil
    --    package.preload[v] = nil
    --    _print_e(string.format("已重载  <color=aqua>%s</color>", v))
    --end
end

--endregion ------------- Inner -------------

---@return FastLuaTest
return FastLuaTest