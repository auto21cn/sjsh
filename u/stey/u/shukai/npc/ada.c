#include <ansi.h>
inherit NPC;

void create()
{
    set_name( HIM "蝴蝶菲菲" NOR, ({"hudie feifei", "feifei", "hudie"}));
    set("title", HIW "蝴蝶仙子" NOR);
    set("long", "这位就是风哥的夫人。\n");
    set("gender", "女性");
    set("age", 22);
    set("per", 40);
  set("rank_info/respect", HIW"蝴蝶仙子"NOR );
  set("attitude", "peaceful");
    set("combat_exp", 10000000);
    set("daoxing", 10000000);
    set("eff_kee", 99999);
    set("eff_sen", 99999);
    set("sen", 99999);
    set("kee", 99999);
    set("max_force", 99999);
    set("max_mana", 99999);
    set("force", 199998);
    set("mana", 199998);
    set("force_factor", 2000);
    set("mana_factor", 5000);
    set_skill("dodge", 555);
    set_skill("moondance", 555);
    set_skill("force", 999);
    set_skill("moonforce", 999);
    set_skill("spells", 999);
    set_skill("moonshentong", 999);
    set_skill("blade", 555);
    set_skill("xuanhu-blade", 555);
    set_skill("parry", 555);
    set_skill("unarmed", 999);
    set_skill("baihua-zhang", 999);
      map_skill("force", "moonforce");
      map_skill("spells", "moonshentong");
      map_skill("blade", "xuanhu-blade");
      map_skill("parry", "xuanhu-blade");
      map_skill("dodge", "moondance");
      map_skill("unarmed", "baihua-zhang");
     set("chat_chance_combat", 90);
    set("chat_msg_combat", ({
//        (: cast_spell, "arrow" :),
//        (: cast_spell, "mihun" :),
//        (: cast_spell, "invocation" :),
        (: cast_spell, "shiyue" :),
        (: cast_spell, "huimeng" :),
 (: perform_action, "blade", "duanfa" :),
        }) );
create_family("月宫", 2, "弟子");
        set("sleep_room",1);
        set("if_bed",1);

setup();
    carry_object("/u/shukai/weapon/cc")->wear();
    carry_object("/u/shukai/weapon/cloth")->wear();
    carry_object("/u/shukai/weapon/jia")->wear();
    carry_object("/u/shukai/weapon/pifeng")->wear();
    carry_object("/u/shukai/weapon/shoes")->wear();
    carry_object("/u/shukai/weapon/blade")->wield();
}
