%%%-------------------------------------------------------------------
%%% @author ousun
%%% @copyright (C) 2024, <COMPANY>
%%% @doc
%%%
%%% @end
%%% Created : 08. 9月 2024 16:37
%%%-------------------------------------------------------------------
-module(lib_misc).
-author("ousun").

%% API
-export([quick_sort/1, pythag/1, perms/1, internal/0, max/2, filter/2, odds_and_evens1/1, odds_and_evens2/1]).

%% 列表推导实现快排
quick_sort([]) -> [];
quick_sort([Pivot | T]) ->
  quick_sort([X || X <- T, X < Pivot])
  ++ [Pivot] ++
    quick_sort([X || X <- T, X >= Pivot]).

%% 毕达哥拉斯三元数组，生成一个包含所有整数{A, B, C}组合的列表，其中A^2 + B^2 = C^2
pythag(N) ->
  [ {A, B, C} ||
    A <- lists:seq(1, N),
    B <- lists:seq(1, N),
    C <- lists:seq(1, N),  %% 提取A,B,C从[1,N]的所有可能值，满足下面的条件
    A + B + C =< N,
    A * A + B * B =:= C * C
    ].

%% 获取所有字符组合
perms([]) -> [[]];
perms(L) -> [[H | T] || H <- L, T <- perms(L -- [H])].

%% 内置函数
internal() ->
  A = list_to_tuple([12, cat, "hello"]),
  B = time(),
  {A, B}.

%% 关卡序列，由;分隔，对于关卡序列G1,G2,G3...Gn，只要其中一个关卡为true，关卡序列的值就为true
%% 关卡，由,分隔，关卡只有在关卡中所有的表达式为true时才返回true
%% 使用关卡获取X，Y中的最大值
max(X,Y) when X > Y -> X;
max(_,Y) -> Y.

%% case语句
filter(P, [H|T])  ->
  case P(H) of
    true -> [H|filter(P, T)];
    false -> filter(P, T)
  end;
filter(_, []) ->
  [].

%% 获取列表里的奇数和偶数列表，会遍历列表两次
odds_and_evens1(L) ->
  Odds = [X || X <- L, (X rem 2) =:= 1],
  Evens = [X || X <- L, (X rem 2) =:= 0],
  {Odds, Evens}.

%% 获取列表里的奇数和偶数列表，会遍历列表一次
odds_and_evens2(L) ->
  odds_and_evens_acc(L, [], []).

odds_and_evens_acc([H | T], Odds, Evens) ->
  case (H rem 2) of
    1 -> odds_and_evens_acc(T, [H | Odds], Evens);
    0 -> odds_and_evens_acc(T, Odds, [H | Evens])
  end;
odds_and_evens_acc([], Odds, Evens) ->
  {lists:reverse(Odds), lists:reverse(Evens)}.

