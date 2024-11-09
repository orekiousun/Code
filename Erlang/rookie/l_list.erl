%%%-------------------------------------------------------------------
%%% @author ousun
%%% @copyright (C) 2024, <COMPANY>
%%% @doc https://www.cainiaojc.com/erlang/erlang-lists.html
%%% 列表
%%% @end
%%% Created : 09. 11月 2024 10:52
%%%-------------------------------------------------------------------
-module(l_list).
-author("ousun").

%% API
-export([all_list/1, any_list/1, append_list/2, delete_list/2, drop_last_list/1, duplicate_list/2,
  last_list/1, max_list/1, member_list/2, merge_list/3, nth_list/2, nth_tail_list/2, reverse_list/1, sort_list/1, sublist_list/2, sum_list/1]).

%% 如果 Pred (Elem)对 List 中的所有元素 Elem 返回 true，则返回 true，否则为 false。
all_list(L) ->
  Pred = fun(E) -> E rem 2 == 0 end,
  Status = lists:all(Pred, L),
  io:fwrite("~w~n", [Status]).

%% 如果 Pred (Elem)对 List 中至少一个元素 Elem 返回 true，则返回 true。
any_list(L) ->
  Pred = fun(E) -> E rem 2 == 0 end,
  Status = lists:any(Pred, L),
  io:fwrite("~w~n", [Status]).

%% 返回一个新列表List3，该列表由List1的元素和List2的元素组成。
append_list(L1, L2) ->
  L3 = lists:append(L1, L2),
  io:fwrite("~w~n", [L3]).

%% 从列表中删除一个元素并返回一个新列表。
delete_list(Pos, L) ->
  L2 = lists:delete(Pos, L),
  io:fwrite("~w~n", [L2]).

%% 删除列表的最后一个元素。
drop_last_list(L) ->
  L2 = lists:droplast(L),
  io:fwrite("~w~n", [L2]).

%% 返回一个列表，其中包含术语Elem的N个副本
duplicate_list(Num, Element) ->
  L = lists:duplicate(Num, Element),
  io:fwrite("~w~n", [L]).

%% 返回列表的最后一个元素
last_list(L) ->
  Last = lists:last(L),
  io:fwrite("~w~n", [Last]).

%% 返回列表中具有最大值的元素。
max_list(L) ->
  Max = lists:max(L),
  io:fwrite("~w~n", [Max]).

%% 检查列表中是否存在元素。
member_list(M, L) ->
  io:fwrite("~w~n", [lists:member(M, L)]).

%% 返回通过合并ListOfLists的所有子列表而形成的排序列表。
merge_list(L1, L2, L3) ->
  io:fwrite("~w~n", [lists:merge([L1, L2, L3])]).

%% 返回List的第N个元素。
nth_list(Idx, L) ->
  io:fwrite("~w~n", [lists:nth(Idx, L)]).

%% 返回除去前n个元素的尾列表。
nth_tail_list(Idx, L) ->
  io:fwrite("~w~n", [lists:nthtail(Idx, L)]).

%% 反转元素列表。
reverse_list(L) ->
  io:fwrite("~w~n", [lists:reverse(L)]).

%% 对元素列表进行排序。
sort_list(L) ->
  io:fwrite("~w~n", [lists:sort(L)]).

%% 返回元素的前n个元素的子列表。
sublist_list(L, N) ->
  io:fwrite("~p~n",[lists:sublist(L, N)]).

%% 返回列表中元素的总和。
sum_list(L) ->
  io:fwrite("~p~n", [lists:sum(L)]).