// added to adm
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int myskill,times, damage;
        string number;
        myskill = (int)me->query_skill("wugou-jian", 1);  
        weapon = me->query_temp("weapon");
      
        if( !target ) target = offensive_target(me);
        
       
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「天外飞仙」？\n");

        if(!me->is_fighting())
                return notify_fail("「天外飞仙」只能在战斗中使用！\n");
                
        if(me->query("family/family_name") != "昆仑山玉虚洞" )
                return notify_fail("你是哪儿偷学来的武功，也想用「天外飞仙」?\n");
	
                
        if(!objectp(weapon = me->query_temp("weapon"))
           ||(string)weapon->query("skill_type")!="sword")
                return notify_fail("「天外飞仙」要用剑才能发挥威力。\n");

        if((int)me->query("max_force") < 300 )
                return notify_fail("你的内力不够！\n");

	if((int)me->query("force") < 300 )
		return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < (int)(me->query("max_sen")/2) )
                return notify_fail("你的精神不够，无法使用天外飞仙！\n");

        if(myskill < 40)
                return notify_fail("你的吴钩剑法级别还不够。\n");
        else 
            if(myskill <70){
                times = 3;        
                number = "三";}
            else
                if (myskill <90){
                    times = 4;
                    number = "四";}
                else
                    if(myskill <110 ){
                           times = 5;
                           number = "五";}
                     else{ 
                           times = 6;
                           number = "六";}

        me->delete("env/brief_message");
	target->delete("env/brief_message");
	damage = me->query_str() + random(me->query_skill("sword"));

message_vision(HIC"\n$N一声长啸，"+ weapon->query("name")+ HIC"光一转，闪电般连续向$n攻出了"+number+"剑，剑剑要命！\n"NOR,me,target);

        for(int i=1;i<=times;i++)
        COMBAT_D->do_attack(me, target, weapon);
        
        me->receive_damage("sen", 20);
        me->add("force", -(times*50+50));

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
	if(me->is_fighting() && target->is_fighting() &&
	environment(me) == environment(target) && times>5)
	{

                target->receive_damage("sen",damage,me);
	}
        me->start_busy(2+random(3));
        return 1;
}

