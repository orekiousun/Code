%%%-------------------------------------------------------------------
%%% @author cd_ouymh
%%% @copyright (C) 2024, <COMPANY>
%%% @doc https://www.cainiaojc.com/erlang/erlang-data-types.html
%%% 数据类型
%%% @end
%%% Created : 28. 10月 2024 15:27
%%%-------------------------------------------------------------------
-module(b_data_type).
-author("cd_ouymh").

%% number(数字) - 整数或浮点数
%% atom(原子) - 是字母，是带有名称的常量，如果原子不以小写字母开头，或者包含字母数字字符，下划线_或@以外的其它字符，则需要将其括在单引号'中
%% Boolean(布尔) - 为亮哥保留的原子，true和false
%% Bit String(位串) - 使用位串存储位类型的内存区域
%% Tuple(元组) - 元组是具有固定数量项的复合数据类型。元组中的每个术语称为元素。元素的数量被称为元组的大小。
%% Map(映射) - 映射是具有可变数量的键-值关联的复合数据类型。映射中的每个键值关联都称为关联对。该对中的键和值部分称为元素。关联对的数量被称为映射的大小。
%% List(列表) - 列表是具有可变项数的复合数据类型。列表中的每个术语称为一个元素。元素的数量被称为列表的长度。
%% erlang没有特别定义字符串数据类型，erlang的字符串数据类型实际上是一个ASCII码组成的列表

%% API
-export([log_base/0, log_bit/0, log_tuple/0, log_map/0, log_list/0]).

%% 打印数字、原子和布尔类型
log_base() ->
  io:fwrite("~w~n",[1 + 1]),
  io:fwrite(atom1),
  io:fwrite("~n"),
  io:fwrite(2 =< 3),
  io:fwrite("~n").

%% 打印位串
log_bit() ->
  Bin = <<10,20>>,
  X = binary_to_list(Bin),
  io:fwrite("~w~n", [X]).

%% 打印元组
log_tuple() ->
  T = {john,24,{june,25}} ,
  io:fwrite("~w~n", [tuple_size(T)]).

%% 打印映射
log_map() ->
  M = #{name => john, age => 25},
  io:fwrite("~w~n", [map_size(M)]).

%% 打印列表
log_list() ->
  L = [10, 20, 30],
  io:fwrite("~w~n", [length(L)]).