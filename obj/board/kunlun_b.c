// kunlun_b.c

inherit BULLETIN_BOARD;
#include <ansi.h>


void create()
{
        set_name(HIW"昆仑山玉壁"NOR, ({ "board" }) );
        set("location", "/d/kunlun/gate.c");
        set("board_id", "shaolin_b");
        set("long", "这是一块石碑，上面密密麻麻地记着昆仑山玉虚洞弟子所立的战功。\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}
