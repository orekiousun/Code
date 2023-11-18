using UnityEditor;
using UnityEngine;

[InitializeOnLoad]
internal static class FastLuaTest
{
    private static GUIStyle CommandButtonStyle;

    static FastLuaTest()
    {
        UnityToolbarExtender.ToolbarExtender.RightToolbarGUI.Add(OnRightToolbarGUI);
    }

    private static void OnRightToolbarGUI()
    {
        if (CommandButtonStyle == null)
        {
            CommandButtonStyle = new GUIStyle("AppCommand")
            {
                fontSize = 13,
                alignment = TextAnchor.MiddleCenter,
                imagePosition = ImagePosition.ImageAbove
            };
        }

        //执行Lua测试代码
        GUIContent fastLuaTestContent = new GUIContent("L1",
            "点击后执行 FastLuaTest.Execute() 测试方法1，可在运行时修改该脚本");
        if (GUILayout.Button(fastLuaTestContent, CommandButtonStyle))
        {
            ExecuteLuaTest(1);
        }

        GUIContent fastLuaTestContent2 = new GUIContent("L2",
            "点击后执行 FastLuaTest.Execute() 测试方法2，可在运行时修改该脚本");
        if (GUILayout.Button(fastLuaTestContent2, CommandButtonStyle))
        {
            ExecuteLuaTest(2);
        }

        GUIContent fastLuaTestContent3 = new GUIContent("L3",
            "点击后执行 FastLuaTest.Execute() 测试方法3，可在运行时修改该脚本");
        if (GUILayout.Button(fastLuaTestContent3, CommandButtonStyle))
        {
            ExecuteLuaTest(3);
        }

        GUIContent luaReloadContent = new GUIContent("RLD");
        if (GUILayout.Button(luaReloadContent, CommandButtonStyle))
        {
            ExecuteLuaReload();
        }

        //执行LuaDebug连接
        GUIContent luaDbgContent = new GUIContent("DBG");
        if (GUILayout.Button(luaDbgContent, CommandButtonStyle))
        {
            ExecuteLuaDebug();
        }

        GUIContent updateProjectContent = new GUIContent("UPD");
        if (GUILayout.Button(updateProjectContent, CommandButtonStyle))
        {
            AssetDatabase.Refresh();
        }
    }

    public static void ExecuteLuaTest(int index)
    {
        if (!Application.isPlaying)
        {
            Debug.LogError("请在游戏运行后执行");
            return;
        }

        XLuaStart.Instance.SafeDoString("require('SelfLuaEditorApi').RemoveModule('FastLuaTest')");
        XLuaStart.Instance.SafeDoString($"require('FastLuaTest').Execute{index}()");
    }

    public static void ExecuteLuaReload()
    {
        if (!Application.isPlaying)
        {
            Debug.LogError("请在游戏运行后执行");
            return;
        }

        XLuaStart.Instance.SafeDoString("require('SelfLuaEditorApi').RemoveModule('FastLuaTest')");
        XLuaStart.Instance.SafeDoString("require('FastLuaTest').Reload()");
    }

    public static void ExecuteLuaDebug()
    {
        if (!Application.isPlaying)
        {
            Debug.LogError("请在游戏运行后执行");
            return;
        }

        XLuaStart.Instance.SafeDoString(@"
            if CS.UnityEngine.Application.isEditor then
                pcall(function()
                    CS.UnityEngine.Application.runInBackground = true
                    package.cpath = package.cpath .. ';C:/Users/Administrator/AppData/Roaming/JetBrains/IdeaIC2022.3/plugins/EmmyLua/debugger/emmy/windows/x64/?.dll'
                    local dbg = require('emmy_core')
                    dbg.tcpConnect('localhost', 9966)
                end)
            end
        ");
    }
}