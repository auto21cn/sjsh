
inherit NPC;
inherit F_MASTER;
int ask_wuxiang();
#include <ansi.h>

void create()
{
	set_name(HIC"濑田宗次郎"NOR, ({ "master zongcilang", "master", "zongcilang" }) );
       set("title", WHT"天剑"NOR);
	set("gender", "男性" );
	set("age", 18);
	set("long", "有着“天剑”称号的十本刃最强剑客。悲惨的童年遭遇使他只能表
现喜怒哀乐中喜的一面。没有感情波动的宗次郎能将杀人剑术的精髓
发挥到极致。\n");
       set("class", "swordman");
       set("attitude", "friendly");
       set("spi", 40);
       set("str", 40);
       set("con", 40);
       set("kar", 40);
       set("per", 40);
	set("int", 40);
       set("max_kee", 3000);
       set("max_gin", 3000);
       set("max_sen", 3000);
       set("force", 6000);
       set("max_force", 3000);
       set("force_factor", 240);
       set("max_mana", 3000);
       set("mana", 3000);
       set("mana_factor", 240);
       set("combat_exp", 2600000);
        set("daoxing", 2600000);
        set("inquiry", ([
                 "无想斩" : (: ask_wuxiang :),
                 "wuxiang" : (: ask_wuxiang :),
         ]) );
        create_family("剑客联盟", 2, "弟子");
        set_skill("unarmed", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("spells", 200);  
        set_skill("renshu", 200);
        set_skill("literate", 200);
        set_skill("sword", 240);  
        set_skill("doom-sword", 240); 
        set_skill("fengyu-piaoxiang", 200);
        set_skill("dodge", 200);  
        set_skill("force", 200);   
        set_skill("guixi-force", 200);
        map_skill("spells", "renshu");
        map_skill("force", "guixi-force");
        map_skill("sword", "doom-sword");
        map_skill("parry", "doom-sword");
        map_skill("dodge", "fengyu-piaoxiang");

           set("chat_chance",5);
           set("chat_msg", ({
        WHT"宗次郎微笑着说道：弱肉强食，始终是这个世界不变的真理。\n"NOR,
        WHT"宗次郎微笑着说道：志志雄大人要我转告大家，这个世界志志雄大人要了。\n"NOR,
        WHT"宗次郎微笑着说道：杀人的时候，如果剑快的话，血从伤口喷出来的时候像风声一样，很好听。\n"NOR,
        }));

              setup();
	 carry_object("/d/obj/cloth/zhanpao")->wear();
        carry_object("/d/obj/weapon/sword/qinghong")->wield();
}



void attempt_apprentice(object ob)
{
        if ( (int)ob->query("int") <25){
	  command("shake");
	command("say 以在下看这位" +
RANK_D->query_respect(ob) + "的天赋并不适合在我门下学习剑术，还是另请高就吧。\n");
  ob->set_temp("denied_by_zogncilang",1);
	return;}

        if ( (int)ob->query("kar") <25){
	  command("shake");
	command("say 以在下看这位" +
RANK_D->query_respect(ob) + "的天赋并不适合在我门下学习剑术，还是另请高就吧。\n");
  ob->set_temp("denied_by_zogncilang",1);
	return;
}

        command("pat "+ob->query("id"));
        command("say 希望你能够助志志雄大人早日达成他的大业。\n");
        command("recruit " + ob->query("id") );
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
	            ob->set("title", WHT"十本刃剑客"NOR);
              ob->set("class", "swordman");
}

int ask_wuxiang()
{

    object ob=this_player();
    if(ob->query("family/master_name") != HIC"濑田宗次郎"NOR)
    {
    command("say 你不是在下弟子，恕在下不能将无想斩的秘密告诉你。");
    return 1;
    }
    if(ob->query("combat_exp") < 1000000 ) 
    {
    command("say 你的修为不够，无法领会到无想斩的秘密。");
    return 1;
    }
    if(ob->query("swordman/wuxiang_perform"))
    { 
    command("say 你不是问过了吗? ");
    return 1;
    }
    if(ob->query("family/master_name") == HIC"濑田宗次郎"NOR)
    {
    command("say 无想斩的秘密就是没有秘密！^^");
    ob->set("swordman/wuxiang_perform",1);
    return 1;
    }
}

