%%%-------------------------------------------------------------------
%%% @author ousun
%%% @copyright (C) 2024, <COMPANY>
%%% @doc https://www.cainiaojc.com/erlang/erlang-maps.html
%%% 映射
%%% @end
%%% Created : 09. 11月 2024 15:05
%%%-------------------------------------------------------------------
-module(o_map).
-author("ousun").

%% API
-export([start/0]).

start() ->
  Lst = [{a, 1}, {b , 2}, {c, 3}],
  Map1 = maps:from_list(Lst),
  io:fwrite("maps:from_list(Lst) ~w~n", [Map1]),
  %% find 用于查找是否存在
  io:fwrite("maps:find(a, Map1) ~w~n", [maps:find(a, Map1)]),
  %% get 用于获取键值
  io:fwrite("maps:get(a, Map1) ~w~n", [maps:get(a, Map1)]),
  %% is_key 是否是键
  io:fwrite("maps:is_key(a, Map1) ~w~n", [maps:is_key(a, Map1)]),
  %% keys 返回所有键
  io:fwrite("maps:keys(Map1) ~w~n", [maps:keys(Map1)]),
  %% merge 合并两个映射
  M1 = #{name => ousun},
  M2 = #{age => 22},
  io:fwrite("maps:merge(M1, M2) ~w~n", [maps:merge(M1, M2)]),
  %% put 将键值对添加到映射
  M3 = maps:put(girl_friend, puff, M1),
  io:fwrite("maps:put(girl_friend, puff, M1) ~w~n", [M3]),
  %% values 返回所有值
  io:fwrite("maps:values(M3) ~w~n", [maps:values(M3)]),
  M4 = maps:remove(age, M2),
  io:fwrite("maps:remove(age, M2) ~w~n", [M4]).
