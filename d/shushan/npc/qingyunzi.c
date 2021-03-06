//qing yunzi-yushu 2001.2.
inherit NPC;
void create()
{
       set_name("轻云子", ({"qing yunzi", "yunzi", "zi"}));
       set("title", "蜀山剑派第三代弟子");   
       set("gender", "女性");
       set("age", 32);
       set("attitude", "peaceful");
       set("class", "swordsman");
       set("str", 30);
       set("int", 30);
       set("per", 40);
       set("con", 30);
       set("combat_exp", 500000);
       set("daoxing", 500000);
       set("max_kee", 1000);
       set("max_sen", 1000);
       set("force", 3600);
       set("max_force", 1800);
       set("force_factor", 90);
       set("max_mana", 1800);
       set("mana", 3600);
       set("mana_factor", 90);
	set_skill("zixia-shengong", 150);
	set_skill("yujianshu", 140);
       set_skill("dodge", 160);
       set_skill("literate", 100);
       set_skill("sword", 140);
       set_skill("force", 150);
       set_skill("parry", 150);
       set_skill("spells", 160);
       set_skill("taoism", 160);
       set_skill("sevensteps", 160);
       map_skill("dodge", "sevensteps");
	map_skill("parry", "yujianshu");
	map_skill("sword", "yujianshu");
       map_skill("force", "zixia-shengong");
       map_skill("spells", "taoism");
       create_family("蜀山剑派", 3, "弟子");
       setup();
       carry_object("d/obj/cloth/pink_cloth")->wear();
       carry_object("d/obj/weapon/sword/qingfeng")->wield();
}

void attempt_apprentice(object ob)
{

	if( (string)ob->query("family/family_name")=="蜀山剑派" )
	{

		if( (int)ob->query("family/generation") < 3  )
		{
			if ( (string)ob->query("gender") == "男性" ) command("say 师叔见笑了。\n");
			else command("say 师姑见笑了。\n");
		}
		else if( (int)ob->query("family/generation") ==3  )
		{
			if ( (string)ob->query("gender") == "男性" ) command("say 师兄太客气了。\n");
			else command("say 师妹太客气了。\n");
		}
		else 
		{
			command("consider");
			command("say 是你自己要拜的，可别怪我啊!。\n");
			command("recruit " + ob->query("id") );
		}
	}
            else
	{
		command("say 好，我蜀山剑派一门人才辈出，你可得给师父争气。\n");
		command("recruit " + ob->query("id") );
	}

	return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "swordsman");
                ob->set("title", "蜀山剑派第四代弟子");
                       }
              return 0;
}

�
