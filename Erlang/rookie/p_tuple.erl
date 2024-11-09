%%%-------------------------------------------------------------------
%%% @author ousun
%%% @copyright (C) 2024, <COMPANY>
%%% @doc https://www.cainiaojc.com/erlang/erlang-tuples.html
%%% 元组
%%% @end
%%% Created : 09. 11月 2024 15:21
%%%-------------------------------------------------------------------
-module(p_tuple).
-author("ousun").

%% API
-export([start/0]).

start() ->
  T = {ousun, 22, {puff, 22}},
  io:fwrite("~w~n", [T]),
  io:fwrite("is_tuple(T) ~w~n", [is_tuple(T)]),
  L = [ousun, puff],
  io:fwrite("list_to_tuple(L) ~w~n", [list_to_tuple(L)]),
  io:fwrite("tuple_to_list(T) ~w~n", [tuple_to_list(T)]).