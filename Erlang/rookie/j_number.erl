%%%-------------------------------------------------------------------
%%% @author ousun
%%% @copyright (C) 2024, <COMPANY>
%%% @doc https://www.cainiaojc.com/erlang/erlang-numbers.html
%%% 数字
%%% @end
%%% Created : 02. 11月 2024 14:50
%%%-------------------------------------------------------------------
-module(j_number).
-author("ousun").

%% API
-export([start/0]).

start() ->
  io:fwrite("~f~n", [1.1 + 1.2]),  %% 输出浮点数
  io:fwrite("~e~n", [1.1 + 1.2]).  %% 输出科学计数法
