%%%-------------------------------------------------------------------
%%% @author ousun
%%% @copyright (C) 2024, <COMPANY>
%%% @doc
%%%
%%% @end
%%% Created : 08. 9月 2024 11:36
%%%-------------------------------------------------------------------
-module(shop).
-author("ousun").

%% API
-export([total/1, cost/1]).

%% 计算购买所有商品的价格
total([{What, N}| T]) -> cost(What) * N + total(T);
total([]) -> 0.

%% 常见的模式，类似于递归
%% total([Head|Tail]) ->
%%   some_function_of(Head) + total(Tail);
%% total([]) ->
%%   0.

cost(oranges) -> 5;
cost(newspaper) -> 8;
cost(apples) -> 2;
cost(pears) -> 9;
cost(milk) -> 7.