#include <ansi.h> 
#include <skill.h> 
#include <weapon.h> 
#include <combat.h> 

inherit SSERVER; 

string *pfa_msg = ({  HIW+ "被这突如其来的变化所惊，竟然忘了防守被$N抛出的长剑当胸刺过，"+HIR+"鲜血"+HIW+"溅了一地！\n"NOR, 
                      HIB+ "看到长剑向自己飞来，急忙挥动手中兵器想将它挡开，可是没想到长剑突然转弯从其右肘穿过！\n"NOR, 
                      MAG+ "急忙转身跳起逃跑，想要躲开$N抛出长剑的攻击，却没想到长剑竟然从后方追上，从背心刺了个对穿！\n"NOR, 
}); 

int perform(object me, object target) 
{     
    int damage , zhao , i; 
    string msg; 
    object weapon , *ob; 

    if (!target ) target = offensive_target(me); 
    
    if (!objectp(weapon = me->query_temp("weapon")) 
        || (string)weapon->query("skill_type") != "sword") 
        return notify_fail(RED"开什么玩笑，没装备剑就想使「离剑式」？\n"NOR); 

    if (!target || !target->is_character() || !me->is_fighting(target)) 
        return notify_fail("「离剑式」只能对战斗中的对手使用。\n"); 

    if ((int)me->query_skill("dugu-jiujian", 1) < 150 ) 
        return notify_fail(WHT"你独孤九剑不够娴熟，使不出「离剑式」。\n"NOR); 

    if ((int)me->query("max_force")<2000) 
        return notify_fail(RED"你内力修为不足，无法运足内力。\n"NOR); 

    if ((int)me->query("force")<600) 
    { 
        return notify_fail(HIC"你现在内力不够，没能将「离剑式」使出！\n"NOR); 
    } 

    msg = HIW "$N突然纵身后跃，随手将长剑抛出看似一招逃命招事！\n"NOR; 
    msg += HIW "但长剑却化做一道"+HIG+"青光"+HIW+"象长了眼睛一样直向与$N交手的众人袭去！\n"NOR;             

    ob = all_inventory(environment(me)); 
    for(i=0; i<sizeof(ob); i++) 
    { 
        if( !living(ob[i]) || ob[i]==me ) 
            continue; 
                 
        if( !ob[i] || !ob[i]->is_character() || !me->is_fighting(ob[i])) 
            continue; 

        if (random(me->query_skill("force")) > ob[i]->query_skill("force")/2||  
            random(me->query("combat_exp")) > (int)ob[i]->query("combat_exp")/3|| 
            random(me->query_skill("dugu-jiujian")) > ob[i]->query_skill("sword")/2|| 
            random(me->query_skill("dodge")) > ob[i]->query_skill("dodge")/2) 
        {                    
            me->add("force", -150); 
            me->start_busy(2); 
            ob[i]->start_busy(random(3)); 
            damage = (int)me->query_skill("dugu-jiujian", 1) + (int)me->query_skill("sword", 1); 
            damage = damage + random(damage) + i * 500; 
            ob[i]->receive_damage("kee", damage/i); 
            ob[i]->receive_wound("kee", damage/(i+1)); 
            msg += HIY+ob[i]->query("name")+pfa_msg[random(sizeof(pfa_msg))]; 
       }else 
       { 
            me->start_busy(2); 
            msg += HIY+ob[i]->query("name")+HIG+"看准长剑的来袭方位，用手中兵器向外一搁挡开了这致命的一剑！\n"NOR; 
       } 
    } 
    msg += HIR"$N"+HIW+"抛出之剑终于再找不到目标，在空中转了一圈后飞回到"+HIR+"$N"+HIW+"的手中！\n"NOR; 
   message_vision(msg, me ,target);
    if(!target->is_fighting(me)) target->fight_ob(me); 
    return 1; 
} 
