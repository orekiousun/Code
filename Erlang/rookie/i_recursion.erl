%%%-------------------------------------------------------------------
%%% @author ousun
%%% @copyright (C) 2024, <COMPANY>
%%% @doc https://www.cainiaojc.com/erlang/erlang-recursion.html
%%% 递归
%%% @end
%%% Created : 02. 11月 2024 14:19
%%%-------------------------------------------------------------------
-module(i_recursion).
-author("ousun").

%% API
-export([fac/1, len/1, tail_len/1, duplicate/2, tail_reverse/1]).

%% 递归实现阶乘
fac(N) when N == 0 ->
  1;
fac(N) when N > 0 ->
  N * fac(N - 1).

%% 利用模式匹配实现递归
len([]) ->
  0;
len([_|T]) ->
  1 + len(T).

%% 尾递归，利用一个中间值缓存结果
%% 注意函数参数个数不同，要以.结尾
tail_len(L) ->
  tail_len(L, 0).

tail_len([], Acc) ->
  Acc;
tail_len([_|T], Acc) ->
  tail_len(T, Acc + 1).

%% 重复输出
duplicate(0, _) ->
  [];
duplicate(N, Term) when N > 0 ->
  io:fwrite("~w~n", [Term]),
  [Term|duplicate(N - 1, Term)].

%% 列表反转
tail_reverse(L) ->
  tail_reverse(L, []).

tail_reverse([], L) ->
  L;
tail_reverse([H|T], L) ->
  tail_reverse(T, [H|L]).