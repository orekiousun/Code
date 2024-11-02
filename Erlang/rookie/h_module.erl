%%%-------------------------------------------------------------------
%%% @author ousun
%%% @copyright (C) 2024, <COMPANY>
%%% @doc https://www.cainiaojc.com/erlang/erlang-modules.html
%%% 模块
%%% @end
%%% Created : 02. 11月 2024 14:14
%%%-------------------------------------------------------------------

%% 模块定义
-module(h_module).
-author("ousun").

%% 模块属性
%% -Tag(Value)
%% 例如-author("ousun").

%% 导出API
-export([start/2]).

%% 道具模块
-import(g_function, [add/2]).

start(A, B) ->
  X = add(A, B),
  io:fwrite("X = ~w~n", [X]).