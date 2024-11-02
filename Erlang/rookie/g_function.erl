%%%-------------------------------------------------------------------
%%% @author ousun
%%% @copyright (C) 2024, <COMPANY>
%%% @doc https://www.cainiaojc.com/erlang/erlang-functions.html
%%% 函数
%%% @end
%%% Created : 02. 11月 2024 14:04
%%%-------------------------------------------------------------------
-module(g_function).
-author("ousun").

%% API
-export([add/2, add/3, anonymous_func/0, log_x_greater/1]).

%% 定义普通函数
%% FunctionName(Pattern1.. PatternN) ->
%% Body;

add(X, Y) ->
  Z = X + Y,
  io:fwrite("Z = ~w~n", [Z]).

add(X, Y, Z) ->
  A = X + Y + Z,
  io:fwrite("A = ~w~n", [A]).

%% 匿名函数
anonymous_func() ->
  Fun = fun() ->
    io:fwrite("anonymous_func~n")
        end,
  Fun().

%% 函数序列
%% FunctionName(Pattern1.. PatternN) [when GuardSeq1] ->
%% Body;
%% 注意参数个数相同的函数，要以分号隔开
log_x_greater(X) when X > 3 ->
  io:fwrite("X > 3 ~w~n", [X]);
log_x_greater(X) when X =< 3 ->
  io:fwrite("X =< 3 ~w~n", [X]).