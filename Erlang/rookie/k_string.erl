%%%-------------------------------------------------------------------
%%% @author ousun
%%% @copyright (C) 2024, <COMPANY>
%%% @doc
%%%
%%% @end
%%% Created : 02. 11月 2024 14:55
%%%-------------------------------------------------------------------
-module(k_string).
-author("ousun").

%% API
-export([start/0]).

start() ->
  Str = "Hello World",
  io:fwrite("len(Str): ~p~n", [string:len(Str)]),
  io:fwrite("equal(Str, Str): ~p~n", [string:equal(Str, Str)]),
  io:fwrite("concat(Str, Str): ~p~n", [string:concat(Str, Str)]),
  io:fwrite("substr(Str, 1, 5): ~p~n", [string:substr(Str, 1, 5)]),
  io:fwrite("left(Str, 15, $.): ~p~n", [string:left(Str, 15, $.)]),
  io:fwrite("left(Str, 5): ~p~n", [string:left(Str, 5)]),
  io:fwrite("right(Str, 15, $.): ~p~n", [string:right(Str, 15, $.)]),
  io:fwrite("right(Str, 5): ~p~n", [string:right(Str, 5)]),
  io:fwrite("to_lower(Str): ~p~n", [string:to_lower(Str)]),
  io:fwrite("to_upper(Str): ~p~n", [string:to_upper(Str)]),
  io:fwrite("sub_string(Str, 1, 5): ~p~n", [string:sub_string(Str, 1, 5)]).
