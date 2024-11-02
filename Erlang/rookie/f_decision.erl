%%%-------------------------------------------------------------------
%%% @author ousun
%%% @copyright (C) 2024, <COMPANY>
%%% @doc https://www.cainiaojc.com/erlang/erlang-decision-making.html
%%% 条件语句
%%% @end
%%% Created : 02. 11月 2024 13:40
%%%-------------------------------------------------------------------
-module(f_decision).
-author("ousun").

%% API
-export([if_syntax/2, case_syntax/1]).

%% if语句
if_syntax(A, B) ->
  %% 注意单个分支语句结束用分号隔开，每个语句后都要跟上 -> 表达式
  %% if表达式需以end结尾
  %% 单条件分支
  if
    A =:= B ->
      io:fwrite("True~n");
    true ->
      io:fwrite("Flase~n")
  end,

  %% 多条件分支
  if
    A =:= B ->
      io:fwrite("A = B~n");
    A < B ->
      io:fwrite("A < B~n");
    true ->
      io:fwrite("A > B~n")
  end,

  %% 嵌套if语句
  if
    A < B ->
      if
        A > 5 ->
          io:fwrite("A > 5~n");
        true ->
          io:fwrite("A < 5~n")
      end;
    true ->
      io:fwrite("A < B~n")
  end.

%% case语句
case_syntax(A) ->
  case A of
    4 -> io:fwrite("A = 4~n");
    5 -> io:fwrite("A = 5~n");
    6 -> io:fwrite("A = 6~n");
    %% 使用下划线可以代表任何值
    _ -> io:fwrite("A = ~w~n", [A])
  end.
