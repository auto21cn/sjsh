
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	int mypot,tapot;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「神气活现」只有在战斗中才能使用。\n");
	if( (int)me->query_skill("huoxin-sword", 1) < 60 ) 
		return notify_fail("你的神谷活心流等级不够，还使不出这一招！\n");
        if( (int)me->query("force") < 300 )      
                return notify_fail("你的内力不够。\n");


	if( target->is_busy() )
		return notify_fail(target->name()+"已经够忙了，根本没注意到你的剑招。\n");

	message_vision(HIG"$N扬起手中的长剑，舞起漫天剑花。只看见空中剑影闪动，虚虚实实，令人眼花缭乱。\n\n"NOR,me);

	me->add("force", -50);

	mypot=(int)me->query_skill("sword");
//	mypot=mypot*mypot*mypot/10 + (int)me->query("combat_exp");

	tapot=(int)target->query_skill("parry");
//	tapot=tapot*tapot*tapot/10 + (int)target->query("combat_exp");
	if ( random( mypot + tapot ) > tapot ) {
		message_vision(HIR"$N果然看得目瞪口呆，不知所措，哪里分得清什么虚实！\n"NOR,target);
		target->start_busy(5);
	}else {
	message_vision(HIR"$N凝神而立，不为虚招所动，$n反而被打了个措手不及。\n"NOR,target,me);
            me->start_busy(3);
	}

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        me->kill_ob(target);
        }
	return 1;
}
       