// worker.c

inherit NPC;
#include <ansi.h>

void create()
{
        set_name("Ůͯ", ({"nu tong", "tong"}));
        set("gender", "Ů��" );
        set("class", "xian" );
        create_family("������", 6, "����");
        set("age", 17);
        set("title", HIM"������ɽ��ӭ��"NOR);
        set("long", "һλ�����ɵ��ӣ�ÿ�츺���ڻ��϶�ӭ��Զ�������Ŀ��ˣ�\n");
        set("combat_exp", 200000);
        set("attitude", "friendly");
        set_skill("dodge", 180);
        set_skill("unarmed", 180);
        set("per", 30);
        set("max_kee", 150);
        set("max_gin", 150);
        set("max_sen", 150);
        setup();
        carry_object("/d/shaolin/obj/cloth.c")->wear();

}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting()
	&& !this_player()->query("env/invisibility") ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "Ůͯ˵������λ" + RANK_D->query_respect(ob) +
"����ӭ�����Ƕ���ɽ����\n");
}
