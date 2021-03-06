// 姜子牙 by Calvin

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
       set_name(HIB"姜子牙"NOR, ({"jiang ziya", "jiang", "ziya","tianshen"}));
       set("long", "得封天天神,是天界专门负责封候的神仙。\n");
       set("title", HIW"得封封官"NOR);
       set("gender", "男性");
       set("age", 3000);
      set("attitude", "peaceful");
       set("rank_info/self", "小神");
        set("rank_info/respect", "得封天界封神榜掌榜门神");
        set("class", "bonze");
        set("str",24);
        set("per",30);
set("max_kee", 5000);
set("max_gin", 5000);
set("max_sen", 5000);
        set("force", 6000);
        set("max_force", 6000);
        set("force_factor", 1000);
        set("max_mana", 6000);
        set("mana", 6000);
        set("mana_factor", 1000);
set("combat_exp", 10000000);
set("daoxing", 10000000);

        set_skill("literate", 350);
        set_skill("spells", 350);
        set_skill("buddhism", 350);
        set_skill("unarmed", 350);
        set_skill("jienan-zhi", 350);
        set_skill("dodge", 350);
        set_skill("lotusmove", 350);
        set_skill("parry", 350);
        set_skill("force", 350);
        set_skill("lotusforce", 350);
        set_skill("staff", 350);
        set_skill("lunhui-zhang", 350);

        map_skill("spells", "buddhism");
        map_skill("unarmed", "jienan-zhi");
        map_skill("dodge", "lotusmove");
        map_skill("force", "lotusforce");
        map_skill("parry", "lunhui-zhang");
        map_skill("staff", "lunhui-zhang");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: cast_spell, "bighammer" :),
//              (: perform_staff, "pudu" :),
        }) );
        set("inquiry",([
      "封神": "你修道未成,封神难以得成啊 ... ..." ]));

        create_family("南海普陀山", 1, "菩萨");
        setup();
        carry_object("/d/zj/armor/fapao")->wear();
        carry_object("/d/zj/weapon/fengshen")->wield();
        carry_object("/d/zj/weapon/zhua")->wield();
}

void attempt_apprentice(object ob)
{
        if (!((string)ob->query("bonze/class") =="bonze" )) {
                command("say 我佛门神通广大，" + RANK_D->query_respect(ob) + "欲成正果，先入我门。\n");
                write("看样子姜子牙对你未剃度出家颇为不快。\n");
                return;
        }
        if (((int)ob->query_skill("buddhism", 1) < 250 )) {
                command("say " + RANK_D->query_respect(ob) + "不在佛法上苦修，恐怕难成正果。\n");
                return;
        }
        command("xixi" + ob->query("id") );
        command("say 好！这才是我佛门的好弟子。只要多加努力，定可早成正果。\n");
        command("recruit " + ob->query("id") );
        return; 
}
