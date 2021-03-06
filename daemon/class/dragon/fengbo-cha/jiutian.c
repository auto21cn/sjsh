// writted by leox
// 2001/7

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{       
        string msg="";
        int damage,wound;
        object weapon=me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「龙啸九天」？\n");

        if(!me->is_fighting())
                return notify_fail("「龙啸九天」只能在战斗中使用！\n");
        
        if(me->query("family/family_name")!="东海龙宫")
                return notify_fail("你非龙族使不出「龙啸九天」！\n");
                
        if (me->query_skill_mapped("force")!="dragonforce")
                return notify_fail("「龙啸九天」必须以龙神心法为底子！\n");
                
        if((int)me->query("max_force") < 500 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 300 )
                return notify_fail("你的内力不足！\n");
        if((int)me->query("sen") < 300 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
        if((int)me->query_skill("dragonforce", 1) < 120)
                return notify_fail("你的龙神心法修为还不够，使用这一招会有困难！\n");
        if((int)me->query_skill("fengbo-cha", 1) < 120)
                return notify_fail("你的风波十二叉修为还不够，使用这一招会有困难！\n");
        message_vision(HIY"$N气沉丹田，犹如五爪金龙般腾空而起，使出「龙啸九天」绝招，向$n连续发动进攻！\n"NOR,me,target);
//        me->set("ciguangpudu", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
//        me->set("ciguangpudu", 7);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
//        me->set("ciguangpudu", 8);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
//        me->set("ciguangpudu", 9);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->delete("longxiaojiutian");
        me->start_busy(3+random(2));
        message_vision(HIW"$N仰天长吟,「龙啸九天」发功完毕，将内力收回丹田.\n"NOR,me,target);
        message_vision(msg,me,target);
        me->add("kee", -100);
        me->add("force", -250);
        me->add("sen",-100);
        return 1;
}
