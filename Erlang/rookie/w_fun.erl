%%%-------------------------------------------------------------------
%%% @author ousun
%%% @copyright (C) 2024, <COMPANY>
%%% @doc https://www.cainiaojc.com/erlang/erlang-funs.html
%%% 函数
%%% @end
%%% Created : 16. 11月 2024 16:31
%%%-------------------------------------------------------------------
-module(w_fun).
-author("ousun").

%% API
-export([start/0]).

%% 定义匿名函数
%% F = fun(Arg1, Arg2, ... ArgN) ->
%%    ...
%% End

start() ->
  A = fun() ->
    io:fwrite("Hello~n")
  end,
  A(),

  Y = 1,
  B = fun(X) ->
    io:fwrite("X = ~w~n", [X]),
    io:fwrite("Y = ~w~n", [Y])  %% 可以访问外部变量
  end,
  B(2),

  %% 匿名函数嵌套，返回值是一个函数
  Adder =
    fun(M) ->
      fun(N) ->
        io:fwrite("~p~n", [M+N])
      end
    end,
  Fun = Adder(6),
  Fun(10).



