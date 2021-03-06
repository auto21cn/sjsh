// zhanggui.c

inherit NPC;
// inherit F_VENDOR_SALE;
//inherit F_DEALER;
int ask_heal();
int ask_me(string);
int ask_yaofang();
#include <ansi.h>

void create()
{
	set_name("杨中顺", ({"yang zhongshun", "yang", "boss"}));
        set("title", "药铺掌柜");
        set("gender", "男性");
        set("age", 37);
        set("long",
            "杨老板是长安城里祖传的名医。虽然年轻，却早已名声在外。\n");
        set("kee", 900); 
        set("max_kee", 900);
        set("sen", 200);
        set("max_sen", 200);
        set("combat_exp", 5000000);
        set("attitude", "friendly");
        set("env/wimpy", 50);
        set_skill("literate", 70);
        set_skill("unarmed", 60);
        set_skill("dodge", 60);



        set("vendor_goods", ([
        "yao"   :"/d/obj/drug/jinchuang",
        "dan"   :"/d/obj/drug/hunyuandan",
        ]) );

    set("inquiry", ([
	"药方" : (: ask_yaofang :),
        "疗伤": (: ask_heal :),
        "金创药" : (: ask_me, "jc-yao" :),
        "养心丸" : (: ask_me, "yx-wan" :),
        "养精丹" : (: ask_me, "yj-dan" :),
        "清心散" : (: ask_me, "qx-san" :),
        "蛇药"   : (: ask_me, "she-yao" :),
        "百草丹" : (: ask_me, "bc-dan" :),
        "九花玉露丸" : (: ask_me, "none" :),
        "田七鲨胆散" : (: ask_me, "none" :),
        "续命八丹" : (: ask_me, "none" :),
        "黑石玉洞丹" : (: ask_me, "none" :),
        "玉真散" : (: ask_me, "none" :),
        "大力丸" : (: ask_me, "none" :),
        "三黄宝蜡丸" : (: ask_me, "none" :),
        "通犀地龙丸" : (: ask_me, "none" :),
        "白云熊胆丸" : (: ask_me, "none" :),
        ]) );
	setup();
        carry_object("/d/obj/cloth/choupao")->wear();
        add_money("gold", 1);
}



void init()
{	
	object ob; 
	mapping myfam; 

	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			command(query("name")+"笑咪咪地说道：这位" + 
RANK_D->query_respect(ob)+ "，可要买什么药？\n");
			break;
		case 1:
			say( query("name")+"笑咪咪地拱了拱手，说道：这位" + 
RANK_D->query_respect(ob)+ "，请进请进。\n");
			break;
	}
}

int ask_yaofang()
{
	object me = this_player();
    if (!me->query_temp("zg_mark"))
    {
	command("say 在下不才，医术平平，开不出什么药方。\n");
	    return 1;
    }
	command("say "+RANK_D->query_respect(me)+"要问什么药的方子，尽管说吧。\n");
	return 1;
}


int ask_heal()
{
//        此处还没做，我没时间了，mudring帮帮忙吧，我上班都迟到了。
        object ob;
        ob=this_player();
        if ((int)ob->query("mud_age")>500000 )
        {
        command("say 你应该自己去把医术学精点好自己给自己弄了！\n");
        return 1;
        }
        
       
        if ((int)ob->query("eff_kee") == (int)ob->query("max_kee")
                && (int)ob->query("eff_sen") == (int)ob->query("max_sen"))
        {
                command("?"+ob->query("id"));     
                command("say 你根本没受伤，跑我这里添乱！\n");
                command("knock"+ob->query("id"));
                return 1;
        }
        else
        {
                message_vision("杨掌柜拿出一根银针轻轻捻入$N受伤的部位附近的穴道，$N感觉舒服多了。\n", ob);
                remove_call_out("recover");
                call_out("recover",2,ob);
                return 1;
        }
        }
        
int recover(object ob)
{
        ob->set("eff_kee", (int)ob->query("max_kee"));
        ob->set("eff_sen", (int)ob->query("max_sen"));  
        message_vision("一柱香的工夫过去了，你觉得伤势已经基本痊愈了。\n",ob);
        command("say 江湖险恶,不小心的话，下次你就没这么幸运了。\n");
        command("pat"+ob->query("id"));
        return 1;
}

int ask_me(string name)
{
	object me = this_player();
	string myid;
	myid = me->query("id");

        if (!me->query_temp("zg_mark"))
        {
        	
command("say "+RANK_D->query_respect(me)+"要买什么药尽管说，至于这药方嘛………\n");
			return 1;
		}
		
        if ( name == "none" ) 
		{
			command("doubt "+query("id"));
			command ("say 这个。。这个。。。我可实在不知道了。\n");
			return 1;
		}
		
		
		if (name == "jc-yao")
		{
			switch (random(5))
			{
				case 0:
	                command("whisper " + myid + " " + "川贝两钱加生地一钱，加水煎熬就可制成一包金创药。");
					break;
				case 1:
	                command("whisper " + myid + " " + "枸枳子四包，外加生地一钱，加水煎熬就可制成一包金创药。");
					break;
				case 2:
	                command("whisper " + myid + " " + "枸枳子两包，川贝一钱，外加生地一钱，加水煎熬就可制成一包金创药。");
					break;
				case 3:
	                command("whisper " + myid + " " + "川贝两钱加防风三钱，加水煎熬就可制成一包金创药。");
					break;
				case 4:
	                command("whisper " + myid + " " + "枸枳子两包川贝一钱，再加防风一钱，加水煎熬就可制成一包金创药。");
					break;
			}
		}
		
        if (name == "yx-wan")
        {
	    	command("whisper " + myid + " " + "川贝一钱，枸枳子一包，菊梗一钱，加水煎熬就可制成。");
		}
        
        if (name == "yj-dan")
        {
	    	command("whisper " + myid + " " + "荷叶一张，菊梗一钱，加水熬干就可制成。");
		}
        	
        if (name == "qx-san")
        {
			switch (random(2))
			{
				case 0:
	                command("whisper " + myid + " " + "雄黄一钱，以巴豆为清泻剂，加水熬干就可制成。");
					break;
				case 1:
	                command("whisper " + myid + " " + "菊梗两钱，以巴豆为清泻剂，加水熬干就可制成。");
					break;
			}
		}
        
        if (name == "she-yao")
        {
			switch (random(2))
			{
				case 0:
	                command("whisper " + myid + " " + "牛黄一钱，雄黄一钱，加水熬干就可制成。");
					break;
				case 1:
	                command("whisper " + myid + " " + "牛黄一钱，菊梗两钱，加水熬干就可制成。");
					break;
			}
		}
 
        if (name == "bc-dan")
       {
			switch (random(2))
			{
				case 0:
	                command("whisper " + myid + " " + "藏红花一钱，生地两钱，加水熬干就可制成。");
					break;
				case 1:
	                command("whisper " + myid + " " + "藏红花一钱，穿山甲一只，加水熬至成型即可。");
					break;
			}
		}
 	me->delete_temp("zg_mark");
 	return 1;
 }

int accept_object(object who, object ob)
{
	int i;
	if ( ob->query("money_id") )
    {
    	if ( ob->value() >= 100 )
        {
			
command 
("say 既承"+RANK_D->query_respect(who)+"重金之惠，有何疑问尽管说出，我是知无不言，言无不尽。\n");
           	who->set_temp("zg_mark",1);
			return 1;
		}

		command(":)");
		return 1;
	}

	return 0;
}		

void accept_kill(object me)
{       object ob;
        if(is_fighting()) return;
        if( query("called") ) return;

        command("help!");

        ob=present("xunluo guanbing");
        if( !ob) {
                seteuid(getuid());
                ob=new("/d/city/npc/xunluobing");
                ob->move(environment());
        }
        message_vision("\n忽然从门外冲进来个巡逻官兵，对$N大喊一声“干什么？想杀人谋财么！\n\n",me);        

        ob->kill_ob(me);
        ob->set_leader(me);
        me->fight_ob(ob);
        set("called", 1);
        call_out("regenerate", 300);
}
int regenerate()
{
        set("called", 0);
        return 1;
}
