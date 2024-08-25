%%%-------------------------------------------------------------------
%%% @author ousun
%%% @copyright (C) 2024, <COMPANY>
%%% @doc
%%% 文件服务器-服务端
%%% @end
%%% Created : 25. 8月 2024 17:22
%%%-------------------------------------------------------------------
-module(afile_server).
-author("ousun").

%% API
-export([start/1, loop/1]).

start(Dir) ->
  spawn(afile_server, loop, [Dir]).

loop(Dir) ->
  receive
    {Client, list_dir} ->
      %% 收到{Client, list_dir}的消息，回复一个文件列表
      %% 这里的self()就是服务器本身
      Client ! {self(), file:list_dir(Dir)};
    {Client, {get_file, File}} ->
      %% 收到{Client, {get_file, File}}的消息，回复这个文件
      Full = filename:join(Dir, File),
      Client ! {self(), file:read_file(Full)}
  end,
  loop(Dir).