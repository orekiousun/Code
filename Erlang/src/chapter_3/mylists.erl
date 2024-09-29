%%%-------------------------------------------------------------------
%%% @author ousun
%%% @copyright (C) 2024, <COMPANY>
%%% @doc
%%%
%%% @end
%%% Created : 08. 9月 2024 12:16
%%%-------------------------------------------------------------------
-module(mylists).
-author("ousun").
%% 导入外部模块

%% API
-export([total/1, total_/1]).

%% 将列表中的元素相加
sum([H | T]) ->
  H + sum(T);
sum([]) ->
  0.

%% 对列表中的所有元素执行某个函数
map(F, [H | T]) ->
  [F(H) | map(F, T)];
map(_, []) ->
  [].

%% 重写total，先利用map生成一个价格列表，再利用sum求和
total(L) ->
  sum(map(fun({What, N}) -> shop:cost(What) * N end, L)).

%% 列表推导
total_(L) ->
  lists:sum([shop:cost(A) * B ||{A, B} <- L]).