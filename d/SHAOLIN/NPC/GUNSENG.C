//gunseng.c

int ask_name(); 

inherit NPC;
#include <ansi.h>
void create()
{

	set_name("��ɮ", ({"gun seng", "seng"}));
        set("gender", "����" );
        create_family("������", 10, "����");
        set("title", HIG"������"NOR );
	set("age", 28);
	set("long", "���������¹�ɮ��\n");
	set("class", "bonze");
	set("attitude", "heroism");

        set("force", 1700);
        set("max_force", 900);
        set("force_factor", 70);
        set("mana", 1700);
        set("max_mana", 900);
        set("mana_factor", 20);
        set("combat_exp", 800000);
        set("daoxing", 500000);

        set_skill("banruo-zhang", 80);
        set_skill("yijinjing", 80);
        set_skill("chanzong", 80);
        set_skill("spells", 80);
        set_skill("unarmed", 80);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("stick", 100);
        set_skill("zui-gun", 100);
        map_skill("unarmed", "banruo-zhang");
        map_skill("stick", "zui-gun");
        map_skill("parry", "zui-gun");
        map_skill("force", "yijinjing");
        map_skill("spells", "chanzong");

	set("max_kee", 1300);
	set("max_sen", 1300);
	setup();
        carry_object("/d/shaolin/obj/cloth.c")->wear();
        carry_object("/d/shaolin/obj/qimeigun.c")->wield();


}


