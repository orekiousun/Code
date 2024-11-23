%%%-------------------------------------------------------------------
%%% @author ousun
%%% @copyright (C) 2024, <COMPANY>
%%% @doc https://www.cainiaojc.com/erlang/erlang-guards.html
%%% 关卡
%%% @end
%%% Created : 16. 11月 2024 15:29
%%%-------------------------------------------------------------------
-module(u_guard).
-author("ousun").

%% API
-export([start/0]).

%% Guard 可以用来增加模式匹配功能的结构，使用Guard，可以对模式匹配中的变量执行简单的测试和比较
%% function(parameter) when condition ->
%% Function(parameter) −这是在保护条件下使用的函数声明。
%% Parameter −通常，保护条件基于参数。
%% Condition −评估条件，以确定是否应执行函数。
%% 当指定了Guard条件时，必须使用when语句。

display(N) when N > 10 ->
  io:fwrite("display: greater than 10~n");
display(N) when N < 10 ->
  io:fwrite("display: less than 10~n").

%% guard也可以用于if语句
if_test(N) ->
  if
    N > 10 ->
      io:fwrite("if_test: N is greater than 10~n");
    true ->
      io:fwrite("if_test: N is less than 10~n")
  end.

%% case语句
case_test(A) ->
  case A of {A}
    when A > 10 ->
      io:fwrite("case_test: A if greater than 10~n");
    _ ->
      io:fwrite("case_test: A is less than 10~n")
  end.

%% 多次guard条件
multi_display(N) when N > 10, is_integer(N) ->
  io:fwrite("multi_display: greater than 10~n");
multi_display(N) when N < 10 ->
  io:fwrite("multi_display: less than 10~n").

start() ->
  display(11),
  display(9),
  if_test(9),
  case_test(9),
  multi_display(11),
  multi_display(9).
