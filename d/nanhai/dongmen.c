// 神话世界·西游记·版本（世纪）
/* <SecCrypt CPL V3R05> */

inherit ROOM;

void create ()
{
  set ("short", "东门");
  set ("long", @LONG

这是蠙城东门，再往东走就到了盘肠小路了。路到这里就很窄小了。城门
的两边是高高的山岭，中间一条羊肠小到通向东面，据说可以到达大圣禅
寺，南赡奇人大圣国师王菩萨就居住在那里。
LONG);

  set("objects", ([ /* sizeof() == 1 */
        __DIR__"npc/qian" : 1,
        __DIR__"npc/weishi" : 3,
]));
  set("outdoors", 1);
  
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"jiedao10",
  "east" : __DIR__"xiaolu0",
]));

  setup();
}

int valid_leave(object me, string dir)
{
   if(!me->query_temp("xuyi/monster")) return 1;
//        if( wizardp(me)) return 1;

        if (dir == "west") {

        return notify_fail("你现在有差事在身，办好再入城吧。\n");

        }   
        return ::valid_leave(me, dir);
}

