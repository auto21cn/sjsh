// 星索 by Calvin

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_love();
void create()
{
       set_name(HIM"星系"NOR, ({"xing xi", "xing", "xi","tianshen"}));
       set("long", "她和星索都是天界神仙之一。\n");
       set("title", HIW"依星双宿"NOR);
       set("gender", "女性");
       set("age", 3000);
       set("class","xian");
       set("attitude", "friendly");
       set("rank_info/respect", "星姑");
       set("cor", 30);
       set("per", 40);
set("max_kee", 5000);
       set("max_gin", 1000);
set("max_sen", 5000);
       set("force", 5000);
       set("max_force", 3000);
       set("force_factor", 125);
       set("max_mana", 2500);
       set("mana", 5000);
       set("mana_factor", 250);
       set("combat_exp", 3000000);
       set("daoxing", 3000000);
       set_skill("literate", 350);
       set_skill("unarmed", 350);
       set_skill("dodge", 350);
       set_skill("force", 350);
       set_skill("parry", 350);
       set_skill("sword", 350);
       set_skill("spells", 350);
       set_skill("whip", 350);
       set_skill("pansi-dafa", 350);
       set_skill("lanhua-shou", 350);
       set_skill("jiuyin-xinjing", 350);
       set_skill("chixin-jian", 350);
       set_skill("qin", 350);
       set_skill("yueying-wubu", 350);
       set_skill("yinsuo-jinling", 350);

   map_skill("spells", "pansi-dafa");
   map_skill("unarmed", "lanhua-shou");
   map_skill("force", "jiuyin-xinjing");
   map_skill("sword", "chixin-jian");
   map_skill("parry", "yinsuo-jinling");
   map_skill("dodge", "yueying-wubu");
   map_skill("whip", "yinsuo-jinling");
   set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "wuzhishan" :),
                (: cast_spell, "ziqi" :)
        }) );
   set("inquiry", ([
          "爱神" : (: ask_love :),
]));
create_family("盘丝洞", 1, "红");
setup();
        carry_object("/d/zj/armor/tianjia")->wear();
        carry_object("/d/zj/weapon/zijian")->wield();
}

void attempt_apprentice(object ob)
{
   if ( (string)ob->query("family/family_name")=="盘丝洞") {
   if (((int)ob->query("combat_exp") < 1500000 )) {
   command("say " + RANK_D->query_respect(ob) +"的道行不够高深，有些绝学秘法恐怕难以领悟。\n");
   return;
   }
        command("pat "+ob->query("id"));
        command("say 好，希望" + RANK_D->query_respect(ob) +"多加努力，他日早成正果。\n");
       command("recruit " + ob->query("id") );
           ob->set("title", "花果山盘丝小仙");
           ob->set("class", "xian");
   return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) +"还是先去学些基础功夫吧。\n");
        return;
}
int accept_fight(object me)
{
   return 0;
}

int ask_love()
{
        object ob=this_player();
        if(ob->query("family/family_name") != "盘丝洞")
        {
        command("say 你又不是盘丝洞的，学它做什么?");
        return 1;
        }
        if(ob->query("family/master_name")!= this_object()->query("name"))
        {
        command("say 你又不是我的徒弟，谁管你！");
        return 1;
        }
        if(!ob->query("pansi/love_master"))
        {
        ob->set("pansi/love_master",1);
        command("say 这一招爱神，是师妹多年修炼所悟，应该可以帮你保命的！");
        ob->set("pansi/ask_zixia_go", 1);
        return 1;
        } else
        {
        command("say 这一招爱神，我不是已经传给你了吗?");
        return 1;
        }
}
