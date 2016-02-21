// feitian-jian.c  飞天剑
// Modified by Cody March.2001
// Write by Cody

#include <ansi.h>

inherit SSERVER;


int perform(object me, object target)
{
        object weapon, ob;
        string msg;
        int myexp,yourexp,lvl;    
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展“ 晓风三月 ”?\n");
         
         if ((string)me->query("family/family_name")!="五庄观")
     return notify_fail("你不是五庄观弟子,乱用什么!!\n"); 
        if( !me->is_fighting() )
            return notify_fail("“ 晓风三月 ”只能在战斗中使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("你使用的武器不对。\n");

        if( environment(me)->query("no_fight") )
                return notify_fail("在这里不能攻击他人。\n");

        if( (int)me->query_skill("xiaofeng-sword", 1) < 100)
                return notify_fail("你的晓风残月剑等级不够，你怎么能使出“ 晓风三月 ”。\n");

    if( (int)me->query("combat_exp",1) < 150000 )
             return notify_fail("你的经验不足，不能使出“ 晓风三月 ”。\n");

        if (me->query("force") < 300)
                return notify_fail("你内力不继，难以使出“ 晓风三月 ”。\n");

        me->clean_up_enemy();
        ob = me->select_opponent();
        myexp = (int) me->query("combat_exp");
        yourexp = (int) target->query("combat_exp");
        lvl = (int)me->query_skill("xiaofeng-sword",1)/20;
        
           msg = HIC
"\n$N脸色忽转肃穆,手中剑芒幻出五彩光芒，你将剑身向$n极速圈去。\n" NOR;
       if(random(myexp)>yourexp/10)
        {
                message_vision(msg + "\n", me, target);
        msg = HIM "$n只觉三股剑气圈住自己,登时全身一麻,动弹不得!!\n" NOR;
                
                message_vision(msg, me, target);
target->start_busy(1+random(lvl));
        message_vision(HIM" 突然一股五彩剑气封住$n。"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        message_vision(HIW"突然第二股五彩剑气封住$n。"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        message_vision(HIC"突然第三股五彩剑气封住$n"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        }
    else {
            message_vision(msg +"\n", me, target);
           msg = HIY "可是$n似乎看破了$N的企图,化去了五彩剑气于无形。\n" NOR;
message_vision(msg, me, target);
            me->start_busy(2); }        
        me->add("force", -150);
        me->start_busy(1);
        return 1;  

}
