//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("林月如", ({ "lin yueru", "lin", "yueru" }));
        set("title","蜀山剑派圣姑弟子");
        set("long", 
"刁蛮少女贵千金，比武招亲动芳心。\n");
        set("gender", "女性");
        set("age", 16);
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("per", 30);
        set("kee", 2200);
        set("max_kee", 2200);
        set("sen", 1600);
        set("max_sen", 1600);
        set("force", 3000);
        set("max_force", 3000);
        set("mana", 3000);
        set("max_mana", 3000);
        set("force_factor", 60);
        set("mana_factor", 60);

        set("combat_exp", 1800000);
        set("daoxing", 2500000);

        set_skill("force", 150);
        set_skill("dodge", 160);
        set_skill("parry", 140);
        set_skill("whip", 180);
        set_skill("unarmed",120);
        set_skill("hunyuan-zhang",120)
        set_skill("canxin-jian", 200);
        set_skill("xiantian-force", 140);
        set_skill("zuixiansteps",160);
        set_skill("literate", 80);
        set_skill("taoism",120);
        map_skill("spells", "taoism");
        map_skill("force", "xiantian-force");
        map_skill("dodge", "zuixiansteps");
        map_skill("parry", "yirubian");
        map_skill("sword", "yirubian");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: perform_action, "whip","yirubian" :),
                (: exert_function, "powerup" :),
        }) );
        setup();
        create_family("蜀山剑派", 5, "未入门弟子");
        carry_object("/obj/cloth")->wear();
        carry_object("/d/obj/weapon/whip/qingfeng")->wield();
}
void attempt_apprentice(object ob)
{
        if ( !((string)ob->query("gender")=="女性")){
        command("shake");
        command("say 我只收女徒，这位" +
           RANK_D->query_respect(ob) + "还是另请高就吧。\n");
           return ;
        }
	command("pat "+ob->query("id"));
        command("say 既然" + RANK_D->query_respect(ob) +"心向蜀山，那我只好收你为徒。\n");
        command("recruit " + ob->query("id") );
        return ;}
}
