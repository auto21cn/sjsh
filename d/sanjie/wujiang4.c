// sanjie wujiang4.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "乌江边");
  set ("long", @LONG
	
滚滚乌江水，浪花拍打着岸边，白花花的浪花夹着清爽的空
气，让人顿时忘记了曾经在这里发生的一段悲惨故事。
LONG);

  set("exits", ([
  "west" : __DIR__"wujiang3",
  "eastup" : __DIR__"wujiang5",
]));
  set("outdoors", 1);

  setup();
}
