// 神话世界·西游记·版本(世纪)
 
// create by jing 2000.7.24

void reset_balance(object me);
inherit BANK;
#include <ansi.h>

void create ()
{
  set ("short", "钱庄");
  set ("long", @LONG

这是一家新开的钱庄，老板钱百万从小就发誓要做个钱庄大老板，只为了
能够常常听到那从柜台里不时传来金银锭铜币落盘的声音……
LONG);

  set("exits", ([
     "north"  : __DIR__"jiedao4",
      ]));
  set("objects", ([
        __DIR__"npc/banker"   : 1,
      ]));

  setup();
}


void init()
{
    reset_balance(this_player());
    ::init();
}

void reset_balance(object me)
{
    int myexp=me->query("combat_exp")/1000;
    int allowed, removed_gold;
    string myid=me->query("id");
    string NPCNAME="钱百万";

    if(myexp<1) myexp=1;
    if(myexp>100) myexp=100;
    allowed=myexp*1000000;//each year can have 100 gold, range 100-10000. 
    if (me->query("balance") > allowed)
    {
   me->set("balance_old", me->query("balance"));
   me->set("balance", allowed);
   removed_gold = (me->query("balance_old") - me->query("balance"))/10000;
   log_file("MONEY_RESET", ctime( time() )+"：魏大人收缴了"+me->query("name")+"("+me->query("id")+")"+removed_gold+"两黄金。\n");
   tell_object(me, GRN+NPCNAME+"在你的耳边悄声说道："+RANK_D->query_respect(me)+
     "，这、这真不知怎么说是好．．．\n"NOR);
   tell_object(me, GRN+NPCNAME+"在你的耳边悄声说道："+
     "昨日魏大人派人前来察案，发觉你老的黄金来路．．．\n"NOR);
   tell_object(me, GRN+NPCNAME+"在你的耳边悄声说道："+
     "若不是在下帮你老辩解，你老的钱就全都充公了．．．\n"NOR);
    }
    return;
}

