#include <ansi.h>
inherit NPC;
void create()
{ set_name(HIW"汽水泡泡"NOR,({"pao pao"}));
  set("long","
   紫夜的小美人，汽水泡泡，她曾经答应嫁给紫夜的，紫夜也/n
说过，要让她成为MUD里最漂亮的新娘，后来她离开了，最后也没/n
能成婚，但有什么关系呢，紫夜还是把她放到了自己的房里，让/n
她身上穿满了各种漂亮的衣服，做为永恒的记念。
               <<<<<forever>>>>>/n"
    );
  set("title",HIR"紫夜的小美人"NOR);
  set("gender","女性");
  set("per",40);
  set("age",18);
  set("max_force",5000);
  set("force",10000);
  set("max_mana",5000);
  set("mana",10000);
  set_skill("dodge",700);
  set_skill("moondance",700);
  map_skill("dodge","moondance");
  set("combat_exp",50);
  set("daoxing",5000000);
  set("inquiry",([
       "name": "我叫汽水泡泡，晶晶亮的汽水泡泡。\n",
       "here":"这里是紫夜的工作室呀。\n",
       "ziye":"他是想天天陪着我啦，可是他最近好忙的，没时间陪我。inn。\n",
       "love":"我知道紫夜他爱我，可是我。。。。。\n",
       "photo":"嘻嘻，那都是我的照片啦\n",
       "sunr" :"那是个漂亮 可爱的 姐姐啦！！！\n",
       "paopao" :"paopao就是我，是ziye的最爱啦！！！\n",
       "lylw" :"那是个大美女啦！！！！\n",
       "aileen" :"那些一个好好好好有名的玩MUD的女孩子啦！！！\n",
        ]));
    setup();
   carry_object("/u/ziye/obj/marry/baihe")->wield ();
   carry_object("/u/ziye/obj/marry/hunsha")->wear();
   carry_object("/u/ziye/obj/marry/jiezhi")->wear ();
}
 
void die()
{
  if (environment())
    message("sound", "\n"+this_object()->query("name")+"怎么你们都欺负我呢?n\n", environment());

  set("eff_kee", 2000);
  set("eff_gin", 2000);
  set("eff_sen", 2000);
  set("kee", 2000);
  set("gin", 2000);
  set("sen", 2000);
  set("force", 2000);
  set("mana", 2000);
}
void unconcious()
{
  die();
}

void init()
{
  object ob;
  ::init();
  if( interactive(ob= this_player()))
    { remove_call_out("greeting");
      call_out("greeting", 1, ob);
    }
 }

void greeting (object ob)
 {
  if( !ob || environment(ob) != environment() ) return;
     {if(ob->query("id") == "shukai")
             say( HIW"汽水泡泡"NOR HIR"说到原来是疯哥来啦！请进请进！！！\n"NOR);
     else
           if(ob->query("id") == "repoo")
                       say( HIW"汽水泡泡"NOR HIB"说到，原来是小叶子来了，请进来吧！！！\n"NOR);
           else  if(ob->query("id") == "xuexu")
             say(HIW"汽水泡泡"NOR HIY"看到柳絮昏了，猛的捏着柳絮的鼻子，一嘴下去做了一口人工呼吸，柳絮醒来又昏了过去。\n"NOR);
           else if(ob->query("id") == "fayu")
                         say(HIW"汽水泡泡"NOR HIB"对晶莹笑道：晶莹妹妹好。\n"NOR);
          else if(ob->query("id") == "ziye")                                          say(HIW"汽水泡泡"NOR HIR"轻柔的在"NOR HIM"紫夜"NOR HIR"脸上吻了一下，害羞地低下了头。\n"NOR);
          else
             say(HIW"汽水泡泡"NOR HIY"赶忙说到原来是"+ob->query("name")+"来了，快请进，快请进！！\n"NOR);
     }
 }


