%%%-------------------------------------------------------------------
%%% @author cd_ouymh
%%% @copyright (C) 2024, <COMPANY>
%%% @doc https://www.cainiaojc.com/erlang/erlang-operators.html
%%% 运算符
%%% @end
%%% Created : 28. 10月 2024 16:00
%%%-------------------------------------------------------------------
-module(d_operator).
-author("cd_ouymh").

%% Erlang 有以下类型的运算符：算术运算符，关系运算符，逻辑运算符，位运算符
%% 算术运算符：+ - * / rem(取余) div(返回整数部分)
%% 逻辑运算符：or and not xor(异或)
%% 位运算符：band(按位与) bor(按位或) bxor(按位异或) bnot(按位取反)

%% API
-export([algorithm/0, logic/0, bit/0]).

algorithm() ->
  io:fwrite("~w~n", [1 + 1]),
  io:fwrite("~w~n", [1 - 2]),
  io:fwrite("~w~n", [1 * 2]),
  io:fwrite("~w~n", [6 / 2]),
  io:fwrite("~w~n", [6 rem 4]),
  io:fwrite("~w~n", [10 div 4]).

logic() ->
  io:fwrite(true or false),
  io:fwrite("~n"),
  io:fwrite(true and false),
  io:fwrite("~n"),
  io:fwrite(not false),
  io:fwrite("~n"),
  io:fwrite(true xor true),
  io:fwrite("~n").

bit() ->
  io:fwrite("~w~n", [2#101 band 2#000]),
  io:fwrite("~w~n", [2#101 bor 2#010]),
  io:fwrite("~w~n", [2#101 bxor 2#010]),
  io:fwrite("~w~n", [bnot 2#010]). % 补码，前面还有个符号位，实际为0010，按位取反后为1101，表示-3


