// datie.c for shaolin
// 5-8-2001, piao

#include <ansi.h>

inherit F_VENDOR_SALE;

void create()
{
	set_name("����ɮ", ({ "datie seng", "datie", "seng" }) );
        set("gender", "����" );
        set("title",HIB"����������������"NOR);
	set("age", 38);
	set("long", "���Ǹ���ǿ��׳��Ƥ���ֺڵĴ���ɮ�ˡ�\n");
	set("attitude", "friendly");
	set("class", "bonze");
        set("combat_exp", 500000);
        set("max_force", 500);
        set("force", 500);
        set("max_mana", 500);
        set("mana", 500);
	set_skill("unarmed", 100);
	set_skill("banruo-zhang", 100);
	set_skill("dodge", 100);
	set_skill("shaolin-shenfa", 100);
	map_skill("dodge", "shaolin-shenfa");
	map_skill("unarmed", "banruo-zhang");
	create_family("������", 36, "����");

       set("per",25);
       set("daoxing", 20000);
       set("vendor_goods", ([
                               ]));
  setup();
  carry_object("/d/shaolin/obj/cloth")->wear();
        add_money("gold", 1);
}

void init()
{
  add_action("do_vendor_list", "list");
}
