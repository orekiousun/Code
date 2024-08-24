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
-export([hello/0, factorial/1, convert_length/1,
  reverse/1, area/1, sumL/1, area_case/1, convert_if/1, inside_fun/0, start_process/0, say_something/2]).

hello() ->
  io:format("Hello"),                   % 正常输出
  io:format("Hello~n"),                 % 换行
  io:format("1:~w 2:~w ~n", [a, b]),    % 占位
  io:format("~-10s~n",[abc]),             % -代表左对齐，10代表10位
  io:format("~-10.3.+s~n",[abc]),          % -代表左对齐，10代表10位，.3表示精度为3位，.+代表用+号填补空位
  io:format("~.2f~n",[3.1415926]).        % 输出两位精度浮点数

factorial(0) -> 1;
factorial(N) -> N * factorial(N - 1).

% 长度转换
convert_length({centimeter, X}) ->
  {inch, X / 2.54};
convert_length({inch, X}) ->
  {centimeter, X * 2.54}.

% 反转列表
reverse(List) ->
  reverse(List, []).
% 辅助函数
reverse([Head | Rest], Reversed_List) ->
  reverse(Rest, [Head | Reversed_List]);
reverse([], Reversed_List) ->
  Reversed_List.

% 计算面积
area({square, X}) ->
  X * X;
area({circle, R}) ->
  3.1415926 * R * R;
area({rectangle, X, Y}) ->
  X * Y.

% 列表求和
sumL(L) ->
  sumL(L, 0).
%辅助函数
sumL([], N) ->
  N;
sumL([H | T], N) ->
  sumL(T, H + N).

% case语句
area_case({Type, X}) ->
  case Type of
    square -> X * X;
    circle -> 3.1415926 * X * X
  end.

% if语句
convert_if({Type, X}) ->
  if
    Type == centimeter ->
      X / 2.54;
    Type == inch ->
      X * 2.54
  end.

% 内置函数
inside_fun() ->
  io:format("trunc(5.01) = ~w~n", [trunc(5.01)]),
  io:format("round(5.6) = ~w~n", [round(5.6)]),
  io:format("2004 rem 400 = ~w~n", [2004 rem 400]),
  io:format("is_atom(adam) = ~w~n", [is_atom(adam)]).

% 打印指定次数
say_something(What, 0) ->
  done;
say_something(What, Times) ->
  io:format("~p~n", [What]),
  say_something(What, Times - 1).

% 创建并启用进程
start_process() ->
  spawn(study_module, say_something, [five, 5]),
  spawn(study_module, say_something, [three, 4]).