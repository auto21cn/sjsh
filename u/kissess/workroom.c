#include <ansi.h>
inherit ROOM;
void create()
{
set ("short",HIW"风中的"BLINK HIG"承诺"NOR);
set ("long",@LONG

需要么？不需要么？需要么？不需要么？........
这是我给你的承诺，没有理由...
可不可以给我个理由先？？？。。。。。
我给你的承诺，是没有理由的。。。。
就象风中的那朵白玫瑰,摇曳着莫名的妩媚。。。
追风少年何处有，泉大mud风中寻。。

LONG
BLINK HIC @LONG
欢迎来到风中追风的家!

LONG NOR);
set("exits",([
"kz":"/d/city/kezhan",
"wiz":"/d/wiz/wizroom",
]));
        set("objects", 
        ([
           __DIR__"npc/announcer" : 1,
        ]));
set("outdoors", 1);
        set("no_time",1);
        set("no_upgrade_age",1);
        replace_program(ROOM);
set("no_clean_up", 1);
set("valid_startroom", 1);
set("if_bed",1);
setup();
call_other( "obj/board/kissess_bbs","???");
}
