// Room: /moon/wroom.c
//cglaem...12/13/96.

#include <ansi.h>
inherit ROOM;
#include <ansi.h>

void create ()
{
    set ("short",HIR "「" HIB "广寒宫" HIR "」" NOR);
  set ("long", @LONG

   这是绿无常和雨点夫妇的卧室，虽然透着一股寒气，但却充满着温馨和甜蜜。
LONG);

  set("no_fight", 1);
  set("item_desc", ([ /* sizeof() == 1 */
  "bed" : "睡觉用的床铺(gosleep,gobed,bed)。 
",
]));
  set("exits", ([ /* sizeof() == 1 */
    "down" : __DIR__"workroom",
]));
  set("no_magic", 1);

  setup();
}

void init()
{
        add_action("do_bed", "gosleep");
        add_action("do_bed", "gobed", );
        add_action("do_bed", "bed");
}

int do_bed()
{       object me;
        me=this_player();
        message_vision(HIY "$N掀开纱帐，准备上床了。\n\n" NOR, me);
          me->move(__DIR__"bed_yudian");
            message_vision(HIY "\n纱帐轻轻一动，$N钻了进来。\n" NOR, me);
                return 1;
}

