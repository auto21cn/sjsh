// bighammer.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;

	success_adj = 150;
	damage_adj = 140;

	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
                return notify_fail("你要用狮子吼攻击谁？\n");

	if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 20 )
                return notify_fail("你无法集中精力，别震伤了自己！\n");

	me->add("mana", -25-2*(int)me->query("mana_factor"));
	me->receive_damage("sen", 10);

	if( random(me->query("max_mana")) < 50 ) {
		write("好象没反应，再来一次吧！\n");
		return 1;
	}

	SPELL_D->attacking_cast(
		me, 
			//attacker 
		target, 
			//target
		success_adj, 	
			//success adjustment
		damage_adj, 	
			//damage adjustment
		"both", 		
			//damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
                HIY "$N深深地吸一口气，发出有如山崩海啸般的一声巨吼！\n
"HIR"        狮        "HIW"★"HIR"        子        "HIW"★"HIR"         吼\n" NOR,
			//initial message
                HIY "$n觉得眼前一阵金星乱冒，耳朵痛得像是要裂开一样！\n" NOR, 
			//success message
                HIY "但是$n好像跟聋子一样，什么也没听见。\n" NOR, 
			//fail message
                HIY "但是狮子吼被$n以法力一引，$N反而被自己的吼声所震！\n" NOR, 
			//backfire initial message
                HIY "$n觉得眼前一阵金星乱冒，耳朵痛得像是要裂开一样！\n" NOR, 
			//backfire hit message. note here $N and $n!!!
	);

	me->start_busy(1+random(2));
	return 3+random(5);
}

