%%%-------------------------------------------------------------------
%%% @author ousun
%%% @copyright (C) 2024, <COMPANY>
%%% @doc https://www.cainiaojc.com/erlang/erlang-records.html
%%% 记录
%%% @end
%%% Created : 09. 11月 2024 15:26
%%%-------------------------------------------------------------------
-module(q_record).
-author("ousun").

%% API
-export([start/0]).
-record(person, {name, id}).
-record(employ, {person, id}).

%% Erlang具有创建记录的额外功能。这些记录由字段组成。
%% 使用记录标识符创建记录。在此记录标识符中，指定构成记录的各个字段。下面给出了一般语法和示例。
%% record(recordname , {Field1,Field2 ..Fieldn}) recordname为记录名，{Fieldn...}为字段列表

start() ->
  P = #person{name = ousun, id = 1},
  io:fwrite("P ~w~n", [P]),
  %% #recordname.Fieldname 访问记录的值
  io:fwrite("P#person.name ~w~n", [P#person.name]),
  %% 更新记录的值#recordname.Fieldname = newvalue
  P1 = P#person{id = 2},
  io:fwrite("P1 ~w~n", [P1]),
  %% 嵌套记录
  Puff = #employ{person = #person{name = puff, id = 2}, id = 2},
  io:fwrite("~w~n", [Puff]).


