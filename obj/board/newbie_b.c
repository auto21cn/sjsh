// wizard_b.c

inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
   set_name(HIR"�����񻰷�չ���԰�"NOR, ({ "board" }) );
        set("location", "/d/wiz/entrance3");
       set("board_id", "newbie_b");
	set("long",
		"����һ��ר�Ź���ϵͳ��Ѷ�İ��ӣ�ֻ����ʦ�� post��\n" );
	setup();
	set("capacity", 150);
	replace_program(BULLETIN_BOARD);
}