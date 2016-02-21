//shenyi.c 华佗老仙

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIW"华佗老仙"NOR, ({"master huatuo", "master"}));
       set("long", "救世济人的神仙。\n");
       set("title", HIC"救世济人"NOR);
       set("per", 40);
       set("gender", "男性");
       set("age", 1000);
        set("attitude", "peaceful");

        set("combat_exp", 20000000);
        set("daoxing", 500000);
        set("shen_type", 1);
        set("max_kee", 2000);
        set("max_gin", 1000);
        set("max_sen", 2000);
	set("max_force", 8888);
	set("force", 8888);
        set("max_mana", 8888);
	set("mana", 8888);
	set("force_factor", 200);
        set_skill("medical", 800);

        set("inquiry", ([
	"name"     : "老夫乃一介布衣，。\n",
	"here"     : "此乃济世堂，专给天下苍生治病的地方．\n",
	//"仙药"     : (: ask_me :),
	]));
	setup();
        carry_object("/d/obj/cloth/linen")->wear();
}

int recognize_apprentice(object ob)
{ob=this_player();
if ((int)ob->query("level") < 5 ) {
        command("say 你的等级不够5级，" + RANK_D->query_respect(ob) + "还需多加努力。\n");
	return 1;
	}
	return 1;
}

�
