
#include <ansi.h>

inherit F_AUTOLOAD;  
inherit ITEM;

void create()
{
set_name(HIY"龙卡"NOR, ({ "gold card", "card", "ka"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("value", 10000);
set("no_drop", "这可是你的龙卡耶，能随便扔掉吗？\n");
set("no_give", "这可是你的龙卡耶，能随便给别人吗？\n");
//set("no_get", "这是别人的龙卡哎！你知道卡的密码吗？\n");
set("no_sell", "这东西是可以买卖的吗?N~O~NO！\n");
		set("material", "steel");
	}
	setup();
}

void init()
 {
   add_action("do_look","look");
 }

   int do_look(string arg)  
 {
    if(arg!="card"&&arg!="gold card")
        return 0;
tell_object(this_player(),"这是一张珍贵的龙卡，当你急需用钱的时候可以使用它来帮忙。
液晶屏上幕显示卡上剩余金额为：\n"
    +MONEY_D->price_str(this_player()->query("card_money"))+"。\n");
      return 1;
 }

int query_autoload() { return 1; }
