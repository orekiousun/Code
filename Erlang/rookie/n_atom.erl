%%%-------------------------------------------------------------------
%%% @author ousun
%%% @copyright (C) 2024, <COMPANY>
%%% @doc https://www.cainiaojc.com/erlang/erlang-atoms.html
%%% 原子
%%% @end
%%% Created : 09. 11月 2024 14:58
%%%-------------------------------------------------------------------
-module(n_atom).
-author("ousun").

%% 原子是字面量，是带有名称的常量。
%% 如果原子不是以小写字母开头，或者包含字母数字字符，下划线(_)或@以外的其他字符，则将其括在单引号（'）中。

%% API
-export([start/0]).

start() ->
  io:fwrite("~w~n", [atom1]),
  io:fwrite("~w~n", [is_atom(atom1)]),
  io:fwrite("~w~n", [atom_to_list(atom1)]),
  io:fwrite("~w~n", [list_to_atom("atom1")]),
  BinaryAtom = atom_to_binary(atom1),
  io:fwrite("~w~n", [BinaryAtom]),
  io:fwrite("~w~n", [binary_to_atom(BinaryAtom)]).