
// daxiao.c

#include <ansi.h>

int exert(object me)
{
	int skill;
        skill = (int)me->query_skill("emeiforce",1);

	if (me->query_condition("linji_daxiao"))
                return notify_fail("你已经在运大小二术了！\n");


	if( me->is_fighting() )
                return notify_fail("战斗中无法运大小二术！\n");

        if( (int)me->query("force") < 500)
		return notify_fail("你的真气不够。\n");

        if( (int)me->query("sen") < skill + 100)
                return notify_fail("你的精神不够运大小二术。\n");

        if( (int)me->query_skill("emeiforce",1) < 150)
                return notify_fail("你的峨嵋心法级别不够。\n");

        if( (int)me->query("kee") < (int)me->query("max_kee") / 2 )
                return notify_fail( "你已经受伤过重，无法运功！\n");

	message_vision(
"$N坐了下来运起大小二术，呼吸吐纳，真气直透九重。脸上神色一会变"HIR"红"NOR"，\n"
"一会变"HIC"青"NOR"，一会又变成"HIY"黄"NOR"色，最后终于回复原来的脸色。\n" NOR, me );
	me->apply_condition("linji_daxiao", (int)skill/20);
        me->add("force",  -500);
        me->add("sen", 0 - skill);
        me->add("kee", 2 * skill);
	me->set("linji/jing", skill);
	return 1;
}

