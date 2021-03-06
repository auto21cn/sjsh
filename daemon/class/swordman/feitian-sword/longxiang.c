
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［龙翔闪］只能对战斗中的对手使用。\n");
       if(me->query("family/family_name")!="剑客联盟")
       return notify_fail("［龙翔闪］只有剑客联盟弟子才可以使用！\n");
	if( (int)me->query_skill("feitian-sword", 1) < 120 ) 
	return notify_fail("你的飞天御剑流等级不够，还使不出龙翔闪！\n");
       if( (int)me->query("force") < 600 )      
       return notify_fail("你的内力不够。\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("sword");
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
       me->add("force", -100);
	message_vision(HIG  "\n$N突然身形跃起，如神龙翱翔在天，手中的"+ weapon->name() +"挟雷霆万钧之势，闪电般的刺向$n！\n" NOR,me,target);
             
        if(me->query("swordman/jiulong_perform",1) != 100000)
        {
        me->add("swordman/longxiang_perform",1);
        tell_object(me,HIY"你觉得自己对飞天御剑流的理解加深了。\n"NOR);
        }
        if(me->query("swordman/longxiang_perform",1) > 300)
        {
        me->set("swordman/jiulong_perform",1);
        tell_object(me,HIY"你在不知不觉间领悟到了「九头龙闪」的要领。\n"NOR);
        me->delete("swordman/longxiang_perform");
        }

	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
          me->start_busy(1);
	return 1;
}
