%%%-------------------------------------------------------------------
%%% @author ousun
%%% @copyright (C) 2024, <COMPANY>
%%% @doc
%%% 文件服务器-客户端
%%% @end
%%% Created : 25. 8月 2024 17:37
%%%-------------------------------------------------------------------
-module(afile_client).
-author("ousun").

%% API
-export([ls/1, get_file/2]).

ls(Server) ->
  %% 向服务器发送{self(), list_dir}的消息，这里的self()是客户端本身
  Server ! {self(), list_dir},
  receive
    {Server, FileList} ->
      FileList
  end.

get_file(Server, File) ->
  Server ! {self(), {get_file, File}},
  receive
    {Server, Content} ->
      Content
  end.