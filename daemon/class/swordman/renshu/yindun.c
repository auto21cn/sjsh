// yindun.c 隐遁之术

inherit SSERVER;
#include <ansi.h>


int cast(object me)
{
	int howlong;
	int spell;
	spell=me->query_skill("spells")/2 + me->query_skill("renshu");
	if(spell < 100)
		return notify_fail("你还没学会隐遁之术。。。\n");
	if(me->query("family/family_name")!="剑客联盟")
                return notify_fail("不是剑客联盟弟子不能用「隐遁之术」！\n");

	if( (int)me->query("mana") < 2*(int)me->query_skill("spells"))
		return notify_fail("你的法力不够了！\n");

	if( (int)me->query("sen") < 50 )
		return notify_fail("你的精神无法集中！\n");

	message_vision("$N喃喃地念了几句咒语。\n", me);

	if( random(me->query("max_mana")) < 200 ) {
		me->add("mana",-(int)me->query_skill("spells"));
		me->receive_damage("sen",10);
		message("vision", "但是什么也没有发生。\n", environment(me));
		return 5+random(5);
	}

	me->add("mana", -2*(int)me->query_skill("spells"));
	me->receive_damage("sen", 20);

	howlong = 15 + random((me->query_skill("spells") -50));
	if (!me->query("env/invisibility"))
		call_out("free", howlong, me, howlong);
	me->set_temp("yinshentime", howlong+(int)me->query_temp("yinduntime"));

	me->set("env/invisibility", 1);
	me->set_temp("no_heal_up/yindun",1);
	
	message_vision(HIW"\n只见$N双手合一，一道白烟过后,$N踪迹皆无。\n\n"NOR, me);
	
	return 15+random(5);
}

void free(object user, int howlong)
{
        if(!user) return;
	if (!user->query("env/invisibility")) return;
	if (user->query_temp("yinshentime") - howlong) {
		user->set_temp("yinshentime", 
			user->query_temp("yinshentime") - howlong);
		call_out("free", user->query_temp("yinduntime"), 
			user, user->query_temp("yinduntime"));
		return;
		}
	user->delete_temp("yinshentime");
	user->set("env/invisibility", 0);      
	user->save();
	message_vision(HIW"\n一道白烟过后，$N从白烟中走了出来。\n\n"NOR, user);
	user->delete_temp("no_heal_up/yindun");
	return;
}

