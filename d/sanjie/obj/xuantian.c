// xuantian.c 【玄天宝鉴】

#include <ansi.h>
#include <weapon.h>

inherit ITEM;

void init();
int do_read(string arg);

void create()
{
        set_name(HIR"【玄天宝鉴】"NOR, ({"xuantian baojian","book","shu"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
	set("long","一本表装得很精美的书，里面没有一个文字，画满了卦像。\n");
        set("material", "paper");
        set("value", 500);   
	set("no_sell",1);
        }
}

void init()
{
	add_action("do_read", "read");
	add_action("do_read", "study");

	if( (int)this_object()->query("created") != 1 )
	{
		this_object()->set("created", 1);
		remove_call_out ("destroy_book");
		call_out ("destroy_book", 18000);

	}
}

void destroy_book()
{
	message_vision("一阵风吹来，" + (string)this_object()->query("name") + "片片碎落，随风而去了。\n", environment(this_object()));
	destruct(this_object());
}

int do_read(string arg)
{
	object me;
	int sen_cost, gain;
	
	me=this_player();

    	if( !this_object()->id(arg) ) return 0;
	if( environment(this_object())!=me ) return notify_fail("书要拿起来读。\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("安全区内不能读书。\n");

    	if( me->is_busy() )
        		return notify_fail("你现在忙着呢，哪有可能静心研读 ... \n");
   	if( me->is_fighting() )
        		return notify_fail("现在才想到精研法术，太晚了吧？\n");
	
	if( (int)me->query_skill("spells",1)<140 )
		return notify_fail("你看来看去，就是没明白这位猴爷写的都是啥。\n");
	if( (int)me->query_skill("spells",1)>200 )
		return notify_fail("你在法术方面已经很有造诣，这本书不会让你长进多少。\n");

	sen_cost = 35 + (35-(int)me->query("int"));
	if( (int)me->query("sen")<sen_cost )
		return notify_fail("你现在头晕脑胀，该休息休息了。\n");	
	me->receive_damage("sen", sen_cost);

	gain = (int)me->query_skill("spells", 1)/5+(int)me->query("int")+1;
	me->improve_skill("spells", gain);

    	message_vision("$N拿着本小册子边看边赞道：好！果然是一部天书，人间难寻！\n", me);
		
	return 1;
}

