%%%-------------------------------------------------------------------
%%% @author cd_ouymh
%%% @copyright (C) 2024, <COMPANY>
%%% @doc https://www.cainiaojc.com/erlang/erlang-loops.html
%%% 循环语句
%%% @end
%%% Created : 28. 10月 2024 16:27
%%%-------------------------------------------------------------------
-module(e_loop).
-author("cd_ouymh").

%% 函数式编程语言不提供循环构造，依赖于递归语句
%% 本节将用递归模拟实现while和for循环语句

%% API
-export([]).

while(L) -> while(L, 0).
while([], Acc) -> Acc;
while([H|T], Acc) ->
  while(T, Acc + H).
