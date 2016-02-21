
#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("[31m冥界召返只能对战斗中的对手使用。[37m\n");
//             if(me->query("family/family_name")!="剑客联盟")
//             return notify_fail("[冥界召返］只有剑客联盟弟子才可以使用！\n");
    if(me->query("swordman/dead_perform")!=1)
    return notify_fail("你还没学会「冥界召返」！\n");
	if((int) me->query_skill("huoxin-sword",1) < 250)
		return notify_fail("你的神谷活心流等级不够，无法使出冥界召返。\n");
  if (me->query_temp("dead_busy")) return notify_fail("你没办法连续使出冥界召返。\n");


	message_vision(RED"\n$N突然插剑归鞘，好象忘记了$n的存在一般，一阵令人窒息
的杀气从$N的身上缓缓散发出来，\n"NOR,me,target);
       me->start_call_out( (: call_other, __FILE__, "kill_him", me, target :), random(5)+5);
	me->start_busy(5);
       me->set_temp("dead_busy",1);
       call_out("remove_effect",6+random(3),me);
	return 1;
}

void kill_him(object me, object target)
{
	string msg;
         string myname=me->name(), npcname=target->name();
	if(me->is_fighting() && 
	environment(me) == environment(target))
	{
msg = RED "\n$N使出了神谷活心流的最终奥义[冥界召返]，普天之下无人可破的
必中必杀的招式！！！" ;
msg +=  "\n\n似乎带着九天十地所有恶魔的祝福一般，剑以藐视一切的姿态刺入了
$n的咽喉，鲜血箭一般的喷射而出，连惨叫都来不及，$n
便倒在了血泊之中。\n" NOR;

	message_vision(msg, me, target);
	target->die();
       {
	 message("channel:rumor",HIM"【风言风语】某人："+npcname+"被"+myname+"用神谷活心流的最高奥义[冥界召返]直接送去了地狱，尸体的脸上还带着诡异的笑容。\n"NOR,users());
	 }

	}
	return ;
}
void remove_effect(object me) {
  if (!me) return;
  me->delete_temp("dead_busy");
}

