%%%-------------------------------------------------------------------
%%% @author ousun
%%% @copyright (C) 2024, <COMPANY>
%%% @doc https://www.cainiaojc.com/erlang/erlang-pattern-matching.html
%%% 模式匹配
%%% @end
%%% Created : 16. 11月 2024 15:26
%%%-------------------------------------------------------------------
-module(t_pattern_matching).
-author("ousun").

%% API
-export([]).

%% 以下模式匹配将成功
%% B = 1
%% 2 = 2
%% {ok, C} = {ok, 40}
%% [H | T] = [1, 2, 3, 4] 竖线表示分隔开头和结尾

%% 以下模式匹配将失败
%% 1 = 2
%% {ok, A} = {1, 2}
%% [H | T] = []

