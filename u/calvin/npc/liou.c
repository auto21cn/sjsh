// 六重天神 calvin,2001.5

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("六重天神", ({"liu tianshen", "liu", "liuchong", "tianshen"}));
        set("title", "天宫守卫");
        set("gender", "男性" );
        set("age", 45);
        set("per", 30);
        set("str", 30);
set("long","这便是六重天界的守护神了,他脚穿六气飞靴,手持一条棍子,那样貌煞是威风!\n");

        set("attitude", "aggressive");
        set("class", "taoist");
       set("shen_type", 1);
       set("max_kee", 5000);
       set("max_gin", 5000);
       set("max_sen", 5000);
       set("force", 5000);
       set("max_force", 5000);
       set("force_factor", 250);
       set("max_mana", 5000);
       set("mana", 5000);
       set("mana_factor", 250);
       set("combat_exp", 3500000);
        set("daoxing", 25000000);

       set_skill("literate", 280);
       set_skill("unarmed", 280);
       set_skill("dodge", 280);
       set_skill("parry", 280);
        set_skill("stick", 280);
        set_skill("sword", 280);
        set_skill("liangyi-sword", 280);
        set_skill("spells", 300);
        set_skill("dao", 300);
        set_skill("puti-zhi", 280);
        set_skill("wuxiangforce", 280);
        set_skill("force", 280);
        set_skill("qianjun-bang", 280);
        set_skill("jindouyun", 280);
        map_skill("spells", "dao");
        map_skill("unarmed", "puti-zhi");
        map_skill("force", "wuxiangforce");
        map_skill("stick", "qianjun-bang");
        map_skill("parry", "qianjun-bang");
        map_skill("dodge", "jindouyun");
        map_skill("sword", "liangyi-sword");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: cast_spell, "light" :),
                (: cast_spell, "dingshen" :),
                (: cast_spell, "thunder" :)
        }) );

setup();
        carry_object("/d/calvin/armor/xue")->wear();
        carry_object("/d/lingtai/obj/putibang")->wield();
}

void init()
{
object who=this_player();
add_action("do_error", "mark");
add_action("do_error", "fight");
add_action("do_error", "fly");
add_action("do_error", "perform");
}

int do_error(string arg)
{
object who = this_player();
message_vision("不要捣蛋哦,小心被天界引起重视！\n",who);
return 1;
}
