inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short","前 院");
  set ("long", @LONG
        ……  无 优 宫  ……
这里是〖无优谷〗的总坛大院，院中种满了花花草草，逢春季节，花
茂盛，鲜花顿开，煞是灿烂。院中有一堵风水墙，是人们的风俗习惯
，据说可以挡煞辟邪。墙上面大大的一个〖无优〗字。

LONG);

  set("exits",([ "northup" : __DIR__"juyitang", ]));
//set("objects", ([ __DIR__"" : 1, ]));
  set("outdoors", 1);
  set("no_clean_up", 1);
  setup();
}