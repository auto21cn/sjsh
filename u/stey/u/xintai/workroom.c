inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "含秀轩");
  set ("long", @LONG

    这里就是天神心太的住处，居然建在了九天之上。轩内外皆有白云飘
动，四壁光彩流动，奇丽不可名状。这里没有昼夜之分，只有空气中不时
传来缕缕清香，令人感到平静安宁。在这样舒适的环境里面，主人一定可
以工作的非常努力。仔细看去，西边的墙壁上有一付对联 (duilian)。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "duilian" : HIC" 宁 静 以 至 远，淡 薄 而 明 志。"NOR,
]));  
  set("no_time",1);
  set("valid_startroom", 1);
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 1 */
  "kz" : "/d/city/kezhan",
]));

  setup();
}
