// 龙一 by Calvin

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
       set_name(HIB"龙一"NOR, ({"long yi", "long", "yi","tianshen"}));
       set("long", "龙族出生的龙一具有很强大的法力。\n");
       set("title", HIW"超俗天尊"NOR);
       set("gender", "男性");
       set("age", 3000);
       set("int", 25+random(5));
       set("attitude", "peaceful");
       set("combat_exp", 1000000);
       set("daoxing", 1000000);

       set("rank_info/respect", "龙一尊者");
       set("class","dragon");
       set("per", 30);
       set("max_kee", 5000);
       set("max_sen", 5000);
       set("force", 3000);
       set("max_force", 3000);
       set("force_factor", 100);
       set("max_mana", 3000);
       set("mana", 3000);
       set("mana_factor", 100);

       set_skill("literate", 350);
       set_skill("unarmed", 350);
       set_skill("dodge", 350);
       set_skill("force", 350);
       set_skill("parry", 350);
       set_skill("fork", 350);
       set_skill("spells", 350);
       set_skill("seashentong", 350);
       set_skill("dragonfight", 350);
       set_skill("dragonforce", 350);
       set_skill("fengbo-cha", 350);
       set_skill("dragonstep", 350);

       map_skill("spells", "seashentong");
       map_skill("unarmed", "dragonfight");
       map_skill("force", "dragonforce");
       map_skill("fork", "fengbo-cha");
       map_skill("parry", "fengbo-cha");
       map_skill("dodge", "dragonstep");
       set("chat_chance_combat", 50);
       set("chat_msg_combat", ({
                (: cast_spell, "hufa" :),
                (: perform_action, "fork", "fengbo" :),
                }) );
            create_family("东海龙宫", 1, "水族");
        setup();

        carry_object("/d/zj/armor/pifeng")->wear();
      carry_object("/d/zj/weapon/fork")->wield();
}

void attempt_apprentice(object ob)
{       ob=this_player();
        if( (string)ob->query("family/family_name")=="东海龙宫") {
        if ((int)ob->query("daoxing") < 5000000 ) {
        command("say 你的道行不是很高啊，" + RANK_D->query_respect(ob) + "还需多加努力才能有所作为啊。\n");
        return;
        }
/*
        if( (int)ob->query("pending/kick_out")) {
        command("say 这位" + RANK_D->query_respect(ob) + "反复无常，小仙不原再收你为徒了！\n");
        command("sigh");
        return;
        }
*/
        if ((int)ob->query_int() < 40) {
        command("say 这位" + RANK_D->query_respect(ob) + "悟性太低，恐怕收了你也难有作为！\n");
        command("sigh");
        return;
        }
        command("smile");
        command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。");
        command("recruit " + ob->query("id") );
        return;
        }
        command("shake");
        command("say 小仙不收外门弟子，" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "dragon");
}

