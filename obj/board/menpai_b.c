// nancheng_b.c

#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIC"三界神话"HIR"门派"HIC"讨论板"NOR, ({ "board" }) );
        set("location", "/d/wiz/menpai_room");
        set("board_id", "menpai_b");
        set("long",     HIC"这是一个供巫师们讨论门派发展建设用的新闻板。\n"NOR );
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}
