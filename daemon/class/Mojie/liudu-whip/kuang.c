#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	int mypot,tapot,time;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「狂字决」只有在战斗中才能使用。\n");

	if( (int)me->query_skill("liudu-whip", 1) < 60 ) 
		return notify_fail("你的修为不够深，还使不出这一招！\n");


	if( (int)me->query("sen") < 100 ) 
		return notify_fail("你的精神不够，无法使出这一招！\n");

	if( target->is_busy() )
		return notify_fail(target->name()+"已经够忙了，你大胆的攻击吧。\n");

	message_vision(HIW"$N一声大喝，一招"HIG"「狂字决」"HIW"攻向$n，$n眼前仿佛出现了一条灵蛇！\n\n"NOR,me, target);
	message_vision(HIG"                          _,..,,,_ \n"NOR,me, target);
	message_vision(HIG"                     '``````^~'-,_`'-,_\n"NOR,me, target);
	message_vision(HIG"       .-~c~-.                    `~:. ^-.\n"NOR,me, target);
	message_vision(HIG"   `~~~-.c    ;                      `:.  `-,     _.-~~^^~:.\n"NOR,me, target);
	message_vision(HIG"         `.   ;      _,--~~~~-._       `:.   ~. .~          `.\n"NOR,me, target);
	message_vision(HIG"          .` ;'   .:`           `:       `:.   `    _.:-,.    `.\n"NOR,me, target);
	message_vision(HIG"        .' .:   :'    _.-~^~-.    `.       `..'   .:      `.    '\n"NOR,me, target);
	message_vision(HIG"       :  .' _:'   .-'        `.    :.     .:   .'`.        :    ;\n"NOR,me, target);
	message_vision(HIG"        `-.__,-~                  ~-.        ,' ':    '.__.`    :'\n"NOR,me, target);
	message_vision(HIG"                                     ~--..--'     ':.         .:'\n"NOR,me, target);
	message_vision(HIG"                                                     ':..___.:'\n"NOR,me, target);
	me->add("sen", -100);

	mypot=(int)me->query_skill("whip");
	mypot=mypot*mypot*mypot/10 + (int)me->query("combat_exp");

	tapot=(int)target->query_skill("parry");
	tapot=tapot*tapot*tapot/10 + (int)target->query("combat_exp");
    time=(int)me->query_skill("liudu-whip", 1) /10;
	if ( time > 10 ) time = 10;
	if ( time < 5  ) time = 5;

	if ( random( mypot + tapot ) > tapot ) {
		message_vision(HIW"$N别吓得当时目瞪口呆，身体别灵蛇缠住，动弹不得！\n"NOR,target);
		target->start_busy(time);
	}else {
	message_vision(HIW"不料招被$N看破，攻其不备，$n反被打了个措手不及！\n"NOR,target,
me);
		me->start_busy(2);
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
       