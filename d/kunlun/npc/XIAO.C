// worker.c

inherit NPC;
#include <ansi.h>

void create()
{
       set_name("С��ͯ", ({"xian tong","tong","xian","xiao","xiao tong"}));
        set("gender", "����" );
        set("class", "xian" );
        create_family("����ɽ���鶴", 4, "����");
        set("title",HIG"����ɽ���鶴"NOR);
        set("age", 17);
        set("long", "һ���ɰ���С��ͯ��\n");
        set("combat_exp", 30);
        set("attitude", "peaceful");
        setup();
}

