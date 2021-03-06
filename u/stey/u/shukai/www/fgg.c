#include <ansi.h>
inherit SSERVER;
#include "/daemon/skill/eff_msg.h";

int def;
int perform(object me, object target)
{       
        string msg;
        int damage, p,time;
        if( !target ) target = offensive_target(me);
         if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("「分光化影」只能在战斗中使用。\n");
        if( (int)me->query_skill("mindsword", 1) < 60 ||
           (int)me->query_skill("zixia-shengong", 1) < 100 )
                return notify_fail("你有的功夫还不够娴熟，不会使用「分光化影」。\n");
                if(me->query("family/family_name") != "蜀山剑派" )
                return notify_fail("你是哪儿偷学来的武功！\n");
        if( (int)me->query("max_force") < 600 )
                return notify_fail("你的内力修为太弱，不能使用「分光化影」！\n");
        if( (int)me->query("force") < 600 )
                return notify_fail("你的真气不够！\n");
        msg = HIC "\n $N如痴如狂，口中喃喃自语：\n" NOR;
        message_vision(msg, me, target); 
       msg = HIW "\n        挫其锐！\n" NOR;
if (random(me->query("combat_exp")) > random((target->query("combat_exp")/3)))
        {
                me->start_busy(1);
                target->start_busy(1);
                damage = (int)me->query_skill("sword");
                 def=(int)target->query_temp("apply/armor_vs_force");
              damage -=damage*def/3000;
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/4);               
                me->add("force", -100);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
                if(me->query_skill("mindsword", 1) > 119)
                   call_out("perform2", 1, me, target);    
        } else 
        {       me->start_busy(3);
                me->add("force", -100);                
                msg += HIY"可是$p猛的一跃，躲开了对手的攻击。\n"NOR;
        }
        message_vision(msg, me, target);
        return 1;
}
int perform2(object me, object target)
{
  int damage, p,skill;
        string msg,weapon;
    weapon = me->query_temp("weapon");  
        if(!living(target)) 
          return notify_fail("对手已经不能再战斗了。\n");
        if(!me->is_fighting(target)) 
          return notify_fail("战斗已经结束了。\n");
        if( (int)me->query("force") < 300 )
                return notify_fail("你待要再出第二击，却发现自己的内力不够了！\n");     
        msg = HIY "\n紧接着，$N口中念道：\n" NOR;
        message_vision(msg, me, target); 
       msg = CYN "\n       解其纷。\n" NOR;
                me->start_busy(1);
                target->start_busy(1);
                damage = (int)me->query_skill("sword");
                damage = damage+(int)me->query_skill("zixia-shengong", 1);
 def=(int)target->query_temp("apply/armor_vs_force");
              damage -=damage*def/3000;
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/4);
                me->add("force", -200);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
                if(me->query_skill("mindsword", 1) > 179)
                   call_out("perform3", 1, me, target);    
        message_vision(msg, me, target);
        return 1;
}
int perform3(object me, object target)
{
  int damage, p,skill;
        string msg,weapon;
    weapon = me->query_temp("weapon");  
        if(!living(target)) 
          return notify_fail("对手已经不能再战斗了。\n");
        if(!me->is_fighting(target)) 
          return notify_fail("战斗已经结束了。\n");
        if( (int)me->query("force") < 400 )
                return notify_fail("你待要再出第三击，却发现自己的内力不够了！\n");     
        msg = HIY "\n紧接着，$N口中念道：\n" NOR;
        message_vision(msg, me, target); 
       msg = HIW "\n       和其光。\n" NOR;
                me->start_busy(1);
                target->start_busy(1);
                damage = (int)me->query_skill("sword");
                damage = damage+(int)me->query_skill("force", 1);
 def=(int)target->query_temp("apply/armor_vs_force");
              damage -=damage*def/3000;
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/4);
                me->add("force", -300);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
                if(me->query_skill("mindsword", 1) > 239)
                   call_out("perform4", 1, me, target);    
        message_vision(msg, me, target);
        return 1;
}
int perform4(object me, object target)
{
  int damage, p,skill;
        string msg,weapon;
    weapon = me->query_temp("weapon");  
        if(!living(target)) 
          return notify_fail("对手已经不能再战斗了。\n");
        if(!me->is_fighting(target)) 
          return notify_fail("战斗已经结束了。\n");
        if( (int)me->query("force") < 500 )
                return notify_fail("你待要再出第四击，却发现自己的内力不够了！\n");     
        msg = HIY "\n紧接着，$N口中念道：\n" NOR;
        message_vision(msg, me, target); 
       msg = HIC "\n       同其尘。\n" NOR;
                me->start_busy(1);
                target->start_busy(1);
                damage = (int)me->query_skill("sword");
                damage = damage+(int)me->query_skill("force");
 def=(int)target->query_temp("apply/armor_vs_force");
              damage -=damage*def/3000;
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/4);
                me->add("force", -400);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
                if(me->query_skill("mindsword", 1) > 299)
                   call_out("perform5", 1, me, target);    
        message_vision(msg, me, target);
        return 1;
}
int perform5(object me, object target)
{
  int damage, p,skill;
        string msg,weapon;
    weapon = me->query_temp("weapon");  
        if(!living(target)) 
          return notify_fail("对手已经不能再战斗了。\n");
        if(!me->is_fighting(target)) 
          return notify_fail("战斗已经结束了。\n");
        if( (int)me->query("force") < 1000 )
                return notify_fail("你待要再出必杀一击，却发现自己的内力不够了！\n");     
        msg = HIY "\n$N施展完分光化影，觉得意犹未尽。\n" NOR;
        message_vision(msg, me, target); 
       msg = HIW "\n   $N忽然悟出了什么，身与心合，心与剑合，身化长剑向$n飞去。\n" NOR;
                me->start_busy(1);
                target->start_busy(1);
                damage = (int)me->query_skill("sword");
                damage = damage+(int)me->query_skill("force");
                damage = damage+(int)me->query_skill("spells");
 def=(int)target->query_temp("apply/armor_vs_force");
              damage -=damage*def/3000;
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/4);
                me->add("force", -500);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
        message_vision(msg, me, target);
        return 1;
}
