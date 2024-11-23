%%%-------------------------------------------------------------------
%%% @author ousun
%%% @copyright (C) 2024, <COMPANY>
%%% @doc https://www.cainiaojc.com/erlang/erlang-macros.html
%%% 宏
%%% @end
%%% Created : 16. 11月 2024 14:57
%%%-------------------------------------------------------------------
-module(s_macro).
-author("ousun").
-define(a, 1).
-define(add(X, Y), {X + Y}).

%% 宏通常用于内联代码，在Erlang中，宏是这样定义的：
%% -define(Constant, Replacement)
%% -define(Func(Var1, Var2, ..., Var), Replacement)
%% undef(Macro)-未定义宏；此后，您将无法调用宏。
%% ifdef(Macro) −仅在定义了宏的情况下才评估以下各行。
%% ifndef(Macro) −仅当未定义宏时才评估以下几行。
%% else−在ifdef或ifndef语句之后允许。如果条件为假，则评估else后面的语句。
%% endif −标记ifdef或ifndef语句的结尾。

%% API
-export([test1/0, test2/0]).

test1() ->
  io:fwrite("~w~n", [?a]).

test2() ->
  io:fwrite("~w~n", [?add(1, 2)]).