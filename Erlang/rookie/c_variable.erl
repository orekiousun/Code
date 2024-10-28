%%%-------------------------------------------------------------------
%%% @author cd_ouymh
%%% @copyright (C) 2024, <COMPANY>
%%% @doc https://www.cainiaojc.com/erlang/erlang-variables.html
%%% 变量
%%% @end
%%% Created : 28. 10月 2024 15:48
%%%-------------------------------------------------------------------
-module(c_variable).
-author("cd_ouymh").

%% Numbers − 用于表示整数或浮点数。例如：10。
%% Boolean − 这表示布尔值，可以为true或false。
%% Bit String − 使用位串存储未类型的内存区域。例如：<< 40,50 >>。
%% Tuple − 元组是具有固定数量项的复合数据类型。例如：{40,50}。
%% Map − 映射是具有可变数量的键-值关联的复合数据类型。映射中的每个键值关联都称为关联对。例如：{type => person，age => 25}。
%% List − 列表是具有可变项数的复合数据类型。例如：[40,40]。

%% API
-export([start/0, log/0]).

start() ->
  X = 40,
  Y = 50,  % 注意，如果定义了变量未使用，会收到报错
  Result = X + Y,
  io:fwrite("~w~n", [Result]).

log() ->
  X = 40.00,
  Y = 50.00,
  io:fwrite("~f~n", [X]),  % 打印浮点数
  io:fwrite("~e~n", [Y]).  % 用科学计数法打印