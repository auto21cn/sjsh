// Room: /d/nanhai/xiaoyuan.c

inherit ROOM;
#include <room.h>
void create()
{
	set("short", "台阶");
	set("long", @LONG
穿过山门殿，面前三道平行的青石台阶通向前方的一个高
台。台阶上精工镂刻着麒麟，玄龟，松鹤等瑞兽，形态逼真动
人。高台正中方着个二人高的青铜大香炉，前面摆着个香台，
几位香客正在虔诚谟拜。再往前就是天王殿。
LONG );
	 set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/gunseng" : 1,
]));
  set("outdoors", "/d/nanhai");
  set("exits", ([ /* sizeof() == 4 */
              "south" : __DIR__"gate",
               "northup" : __DIR__"twdian",
               "west" : __DIR__"beilin2",
               "east" : __DIR__"beilin1",
]));
	set("outdoors", "/d/shaolin");
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "south" : (: look_door,     "south" :),
]));

create_door("south", "石门", "north", DOOR_CLOSED);
  setup();
}
