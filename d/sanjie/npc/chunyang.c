// chunyang.c 纯阳祖师

#include <ansi.h>
string ask_me();

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIW"纯阳祖师"NOR, ({"master zhaoyang", "master"}));
       set("long", "天一宫创教人，四百年前曾一人之力灭尽中土妖魔。\n");
       set("title", HIC"天一宫"NOR);
       set("per", 40);
       set("gender", "男性");
       set("age", 400);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "老祖师");
       set("max_kee", 2000);
       set("max_gin", 100);
       set("max_sen", 2000);
       set("force", 2400);
       set("max_force", 2400);
       set("force_factor", 240);
       set("max_mana", 2400);
       set("mana", 2400);
       set("mana_factor", 270);
       set("combat_exp", 2400000);
       set("daoxing", 3500000);

        set_skill("dodge", 220);
        set_skill("parry", 220);
        set_skill("spells", 220);  
        set_skill("tianmogong", 220);
        set_skill("literate", 160);
        set_skill("sword", 220);  
        set_skill("huxiaojian", 200);
        set_skill("zhaoyangbu", 200);
        set_skill("force", 220);   
        set_skill("huntianforce", 200);

        map_skill("spells", "tianmogong");
        map_skill("force", "huntianforce");
        map_skill("sword", "huxiaojian");
        map_skill("parry", "huxiaojian");
        map_skill("dodge", "zhaoyangbu");
        
        set("chat_msg_combat", ({
		(: cast_spell, "zhui" :),
        }) );

        create_family("三界山", 1, "蓝");
	
	set("inquiry", ([
	"name"     : "老夫乃天一宫创派人——郭纯阳。\n",
	"here"     : "此乃天一仙府也，能进来，也算你福泽不浅。\n",
	"内丹"     : (: ask_me :),
	]));
	
	set("time", 1);
	
	setup();
	carry_object("/d/sanjie/obj/xuantian");	
	carry_object("/d/sanjie/obj/jinjia")->wear();
        carry_object("/d/obj/stey/zhaoyangjian")->wield();
	carry_object("/d/sanjie/obj/chunyang")->wield();
}

void attempt_apprentice(object ob)
{	ob=this_player();
        if( (string)ob->query("family/family_name")=="三界山") {
	if ((int)ob->query("daoxing") < 500000 ) {
  	command("say 你的道行还不够，" + RANK_D->query_respect(ob) + "还需多加努力。\n");
	return;
	}

	if( (int)ob->query("pending/kick_out")) {
	command("say 这位" + RANK_D->query_respect(ob) + "你曾背我派，我不原再收你为徒了！\n");
	command("sigh");
	return;
	}

	if ((int)ob->query_int() < 35) {
	command("say 这位" + RANK_D->query_respect(ob) + "悟性太低，恐怕收了你也难有作为！\n");
	command("sigh");
	return;
	}
	if( (int)ob->query_skill("huntianforce", 1) < 120 ) {
	command("say 这位" + RANK_D->query_respect(ob) + "对混天宝鉴领会还不够深，现在收你也是勉为其难，不如作罢！\n");
	command("sigh");
	return;
	}
        command("smile");
        command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。");
        command("recruit " + ob->query("id") );
	return;
	}
        command("shake");
        command("say 老夫不收外门弟子，" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        ob->set("class", "sanjie");
}

string ask_me()
{
        object ob;
           
   if((int)this_player()->query("combat_exp") < 30000 )
     return "你功力尚浅，怕伤你性命，以后再说吧！\n";

   if (this_object()->is_fighting())
     return "没见老夫正打着吗，以后再说吧！\n";

   if ( present("neidan", this_player()) )
     return "吃，吃，吃，怕你丹田受不了，武功全废！\n";

        if ( present("neidan", environment()) )
     return "那不是有一颗呢嘛，吃完再说！\n";

   if(query("time") <1 )
     return "不巧，不巧，我也没了！\n";

     say("纯阳先师说道：那到要瞧你够不够格吃了，放马过来吧！\n");
     this_player()->set_temp("chunyang_fight", 1);
     return ("嘿嘿！\n");
}

int accept_fight(object who)
{
     object me;
    me = this_object();
     if (!who->query_temp("chunyang_fight")){
     command("say 不打不打，没见老夫正打着吗！\n");
         return 0;
   }
     if (me->is_fighting()){
     command("say 不打不打！\n");
         return 0;
   }
   say("纯阳笑道：老头子等了几百年了，算是等到一个有出息的！\n");
   me->set("eff_kee", (int)me->query("max_kee"));
        me->set("kee", (int)me->query("max_kee"));
        me->set("eff_sen", (int)me->query("max_sen"));
        me->set("sen", (int)me->query("max_sen"));

     who->set_temp("chunyang_fight",0);
     remove_call_out("check_fight");
     call_out("check_fight", 1, me, who);
     return 1;
}

void player_win (object me, object who)
{
     object obj;
   if (me->query("time")<=0)
     return;
   obj=new("/d/sanjie/obj/neidan");
   say("纯阳先师仰天大笑：哈哈哈……等了几百年了，终于找到继承人了！\n");
   say("如此武艺高强，真是令我等佩服啊！\n");
   obj->move(who);
        me->add("time", -1);
   message_vision("纯阳先师对$N哈哈笑道：现在我就传你老夫的四百年功力，你收下吧！\n", who);
   call_out("reg", 750);
}

int reg()
{
   object me=this_object();
   me->set("time", 1);
   return 1;
}

void player_lose (object me, object who)
{
     string msg;
     msg = RANK_D->query_respect(who);
   
   command("jump");
   say("纯阳先师哈哈大笑："+msg+"莫要不高兴，回去好好练武吧，来日方长嘛！\n");
}

void check_fight (object me, object who)
{
     int my_kee, whos_kee;
     int my_max_kee, whos_max_kee;

   if(!who) return;
     my_kee = me->query("kee");
     whos_kee = who->query("kee");
     my_max_kee = me->query("max_kee");
     whos_max_kee = who->query("max_kee");

     if (me->is_fighting()){
         remove_call_out("check_fight");
         call_out ("check_fight",1,me,who);
         return;
     }

   if (!present(who, environment(me)))
         return;

   if ((my_kee*100/my_max_kee) <= 50)
     player_win (me, who);
     else if ((whos_kee*100/whos_max_kee) <= 50)
     player_lose (me, who);
}

�
