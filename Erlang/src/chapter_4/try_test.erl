%%%-------------------------------------------------------------------
%%% @author ousun
%%% @copyright (C) 2024, <COMPANY>
%%% @doc
%%%
%%% @end
%%% Created : 29. 9月 2024 15:30
%%%-------------------------------------------------------------------
-module(try_test).
-author("ousun").

%% API
-export([test1/0, test2/0, test3/0]).

generate_exception(1) -> a;
generate_exception(2) -> throw(a);
generate_exception(3) -> exit(a);
generate_exception(4) -> {'EXIT', 1};
generate_exception(5) -> error(a).

catcher(N) ->
  try generate_exception(N) of
    Val -> {N, normal, Val}
  catch
    throw:X -> {N, caught, thrown, X};
    exit:X -> {N, caught, exit, X};
    error:X -> {N, caught, error, X}
  end.

test1() ->
  [catcher(I) || I <- [1,2,3,4,5]].

test2() ->
  [{I, (catch generate_exception((I)))} || I <- [1,2,3,4,5]].

%% 打印堆栈
test3() ->
  try generate_exception(5)
  catch
      error:X:StackTrace -> {X, StackTrace}
  end.