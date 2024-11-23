%%%-------------------------------------------------------------------
%%% @author ousun
%%% @copyright (C) 2024, <COMPANY>
%%% @doc https://www.cainiaojc.com/erlang/erlang-binaries.html
%%% 二进制
%%% @end
%%% Created : 16. 11月 2024 16:29
%%%-------------------------------------------------------------------
-module(v_binary).
-author("ousun").

%% API
-export([start/0]).

start() ->
  io:fwrite("~p~n", [<<5, 10, 20>>]),
  io:fwrite("~p~n", [<<"hello">>]).