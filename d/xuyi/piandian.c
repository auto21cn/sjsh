// 神话世界·西游记·版本(佳音)
/* <SecCrypt CPL V3R05> */
 
// Room: /d/xuyi/lianwuchang.c

inherit ROOM;

void create ()
{
  set ("short", "偏殿");
  set ("long", @LONG

皇宫的偏殿，也是一个练武场，室内各种兵器琳琅满目，映着日光，熠熠
生辉。几个王府卫士正在演练，旁边的兵器架里有不少兵器可以选用。
LONG);


  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"taizifu",
  "west" : __DIR__"hualang",
  "east" : __DIR__"shuifang",
]));

  set("objects", ([
        __DIR__"obj/rack": 1,
         __DIR__"npc/zhangmen": 1,
        __DIR__"npc/weishi": 2,
                   ]));

  setup();
}


