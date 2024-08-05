%%%-------------------------------------------------------------------
%%% @author 11877
%%% @copyright (C) 2024, <COMPANY>
%%% @doc
%%%
%%% @end
%%% Created : 04. 8月 2024 16:42
%%%-------------------------------------------------------------------
-module(study_module).
-author("11877").

%% API
-export([hello/0, factorial/1, convert_length/1, reverse/1, area/1, sumL/1]).

hello() ->
  io:format("Hello").

factorial(0) -> 1;
factorial(N) -> N * factorial(N - 1).

% 长度转换
convert_length({centimeter, X}) ->
  {inch, X / 2.54};
convert_length({inch, X}) ->
  {centimeter, X * 2.54}.

reverse(List) ->
  reverse(List, []).

% 辅助函数
reverse([Head | Rest], Reversed_List) ->
  reverse(Rest, [Head | Reversed_List]);
reverse([], Reversed_List) ->
  Reversed_List.

area({square, X}) ->
  X * X;
area({circle, R}) ->
  3.1415926 * R * R;
area({rectangle, X, Y}) ->
  X * Y.

sumL(L) ->
  sumL(L, 0).

%辅助函数
sumL([], N) ->
  N;
sumL([H | T], N) ->
  sumL(T, H + N).