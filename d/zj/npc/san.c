// 云飞 by Calvin

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void attempt_apprentice(object ob);

void create()
{
        set_name(HIC"云飞"NOR, ({ "yun fei", "yun", "fei","tianshen" }));
        set("title",HIW"飞云尊者"NOR);
        set("gender", "男性");
        set("long", "他是一派精深武道世家的神仙化身。\n");
        set("age", 3000);
        set("attitude", "peaceful");
        set("str", 20);
        set("int", 35);
        set("con", 30);
        set("per", 30);
        set("class","swordsman");
        set("kee", 100000);
        set("max_kee", 5000);
        set("sen", 100000);
        set("max_sen", 5000);
        set("force", 24000);
        set("max_force", 2000);
        set("max_mana", 3000);
        set("mana", 6000);
        set("force_factor", 80);
        set("mana_factor", 100);

        set("combat_exp", 3000000);
        set("daoxing", 3000000);

        set_skill("spells",350);
        set_skill("force", 350);
        set_skill("dodge", 350);
        set_skill("parry", 350);
        set_skill("sword", 350);
        set_skill("zixia-shengong", 350);
        set_skill("sevensteps", 350);
        set_skill("literate", 350);
        set_skill("unarmed", 350);
        set_skill("yujianshu",350);
        set_skill("hunyuan-zhang",350);
        set_skill("taoism",350);
        map_skill("spells", "taoism");
        map_skill("dodge", "sevensteps");
        map_skill("force", "zixia-shengong");
        map_skill("parry", "yujianshu");
        map_skill("sword", "yujianshu");
        map_skill("unarmed", "hunyuan-zhang");

        create_family("蜀山剑派", 1, "祖师");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "jianshen" :),
                (: exert_function, "recover" :),
        }) );
   add_temp("apply/damage", 15);
   add_temp("apply/armor", 40);

   set("inquiry", ([
// "去镇妖塔"     : (: ask_me :),
]) );

        setup();
           carry_object("/d/zj/armor/shenpao")->wear();
        carry_object("/d/zj/weapon/feixian")->wield();
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query_int() < 35) 
        {
                command("say 依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合学我蜀山剑派武功？");
                return;
        }
        if ( ob->query("daoxing") < 3000000) {
                command("say " + RANK_D->query_respect(ob) + "的道行是不是低的点？");
                return;
        }
        command("say 好吧，我就收下你了。");
        command("recruit " + ob->query("id"));
}
