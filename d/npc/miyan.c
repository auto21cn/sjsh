// dizi.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
	set_name(HIY"明神弥彦"NOR, ({ "master miyan", "miyan", "master" }) );
	set("gender", "男性" );
       set("title", HIC"神谷道场大弟子"NOR);
	set("age", 14);
	set("long", "神谷道场的大弟子，虽然还只有十多岁，但是剑术上的修为
已超过了一般的剑客。\n");
set("daoxing",500000);
	set("combat_exp",500000);
       set("attitude", "peaceful");
	set("int", 30);
	set("class", "swordman");
       create_family("剑客联盟", 3, "弟子");
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("spells", 80);  
        set_skill("renshu", 80);
        set_skill("literate", 80);
        set_skill("sword", 80);  
        set_skill("huoxin-sword", 80); 
        set_skill("fengyu-piaoxiang", 80);
        set_skill("dodge", 80);  
        set_skill("force", 80);   
        set_skill("guixi-force", 80);
        map_skill("spells", "renshu");
        map_skill("force", "guixi-force");
        map_skill("sword", "huoxin-sword");
        map_skill("parry", "huoxin-sword");
        map_skill("dodge", "fengyu-piaoxiang");
        set("per", 30);
        set("max_kee", 800);
        set("max_gin", 800);
        set("max_sen", 800);
        set("force", 2400);
        set("max_force", 1200);
        set("force_factor", 40);
        set("mana", 2400);
        set("max_mana", 1200);
        set("mana_factor", 40);

           set("chat_chance",2);
           set("chat_msg", ({
        HIG"弥彦看着手中的剑说道：总有一天我要成为像世上最强的剑客。\n"NOR,
        HIG"弥彦喃喃说道：听说神谷活心流剑法中隐藏了一个很大的秘密。\n"NOR,
        HIG"弥彦说道：什么时候剑心肯传授飞天御剑流给我就好了。\n"NOR,
        }));

        setup();
	carry_object("/d/obj/cloth/zhanpao")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
}
void attempt_apprentice(object ob, object me)
{ 
if (((int)ob->query("swordman/dead_perform"))) {
   command("say " + RANK_D->query_respect(ob) +
"你不适合在我的门下学习。\n");
   return;
   }
        command("say 很好，" + RANK_D->query_respect(ob) +
"让我们一起努力，变得更强。\n");
        command("recruit " + ob->query("id") );
	   ob->set("title", "神谷道场弟子");
	return;
}				

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "swordman");
}
