//lands'留言板 
//made by lands

#include <ansi.h> 
inherit BULLETIN_BOARD; 

void create() 
{
        set_name(HIM"试心石"NOR, ({ "board" }) ); 
        set("location", "/u/lands/workroom"); 
        set("board_id", "kissess_b"); 
        set("long",     "这是蓝德的工作台。\n" ); 
        setup(); 
        set("capacity", 200); 
        replace_program(BULLETIN_BOARD); 
}
