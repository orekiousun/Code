%%%-------------------------------------------------------------------
%%% @author cd_ouymh
%%% @copyright (C) 2024, <COMPANY>
%%% @doc https://www.cainiaojc.com/erlang/erlang-basic-syntax.html
%%% 基本语法
%%% @end
%%% Created : 28. 10月 2024 15:22
%%%-------------------------------------------------------------------
-module(a_basic_syntax).
-author("cd_ouymh").

%% API
-export([start/0]).

%% 这一行为注释
start() ->
  io:fwrite("Hello World!~n").
