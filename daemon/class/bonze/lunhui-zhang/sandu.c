// /daemon/class/bonze/lunhui-zhang/du.c 佛门三渡
// writted by jie 2001-2-9
// 连续三招：渡劫 渡难 渡厄 
// 杀气低于300 莲台心法100 轮回杖100就可发三招
// 最后一招慈光普渡
// 莲台心法120 轮回杖120就可发四招
// 西游记的pfm经过敌我双方计算比较确定成功率和出招数
// 比xkx系列直接设置连续出几招合理。
// 毕竟杀怪系统是西游记MUD的支撑
// modi by xintai 2/26/2001

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void sandu2(object me);
void sandu3(object me);
void sandu4(object me);
int perform(object me, object target)
{
        string msg;
        object weapon;
        int ap1, ap2, ap3, dp1, dp2, ap, dp, damage, wound;

        me->clean_up_enemy();
        target = me->select_opponent();
// 佛门杀气高？好象不符合现实，所以设定这杀气条件
        if( (int)me->query("bellicosity") > 300 )
        return notify_fail("你的杀气太重，无法施展佛门绝技。\n");

        if (me->query_skill("staff") < 120)
        return notify_fail("你的轮回杖法与基本杖法还不够纯熟，怕是无法运用！\n");

        if(me->query_skill("lotusforce",1) < 100)
        return notify_fail("你的内功底子不足，无法运杖如风，施展不出佛门三渡。\n");

        if((string)me->query_skill_mapped("force")!="lotusforce")
        return notify_fail("佛门三渡必须以莲台心法为底子。\n");

        if(me->query("max_force") < 500)
        return notify_fail("你的内力不足，难以随意挥动一把禅杖。\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［佛门三渡］只能对战斗中的对手使用。\n");

        weapon = me->query_temp("weapon");

        
        if( (int)me->query("force") < 200 )
                return notify_fail("你现在的内力不足。\n");

        msg = HIW "$N默吟佛号，手中的"+ weapon->query("name")+ HIW"带一层淡淡的白雾直直拍向$n的胸前！\n
        这第一招名唤「渡劫」！\n"NOR;
        message_vision(msg, me, target);

        ap1 = (int)me->query("combat_exp");
        dp1 = (int)target->query("combat_exp");
        ap2 = me->query_str();
        dp2 = target->query_str();
        ap3 = (int)me->query_skill("buddhism",1);
        
        ap = ap1 + ap2 + ap3;
        dp = (dp1 + dp2)/2;
        if( dp < 1 )
                dp = 1;
        if( ap3> 60 || random(ap) > dp )
        {
                msg = HIR "$n心神一慌，一个躲闪不及，被$N的"+ weapon->query("name")+ HIR"实实在在的印在胸膛，\n$n的胸膛立刻就塌了下去！\n\n"NOR;
                message_vision(msg, me, target);
                me->add("force",-100);
                damage = (50 + me->query_str() + random(me->query_skill("staff")))/2;
                wound=random(damage-(int)target->query_temp("apply/armor"));
                if(wound>0) target->receive_wound("kee", wound);
                target->receive_damage("kee", damage);
                COMBAT_D->report_status(target, 0);
                call_out("sandu2", 0, me);
                target->start_busy(1);
                me->start_busy(1);
        }
        else
        {
                msg = HIG "只见$n神色一凛，不敢硬接，一个翻身及时的退出战圈，躲开了$N凌厉的攻势！\n\n"NOR;
                message_vision(msg, me, target);
                me->add("force",-100);
                me->start_busy(3);
        }

        

        return 1;
}

void sandu2(object me)
{
        string msg;
        object weapon, target;
        int ap1, ap2, ap3, dp1, dp2, ap, dp, damage, wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        if( !me->is_fighting()|| !living(me) )
                return;

        if( (int)me->query("force") < 300 )
                return;

        if(me->query_skill("staff") < 135)
                return;

        if(me->query_skill("force") < 135)
                return;
        weapon = me->query_temp("weapon");
        msg = HIW "$N手中"+ weapon->query("name")+ HIW"一振，白色劲气已然布满全身，风雷之声渐起，
        这第二式「渡难」猛然拍出！\n\n"NOR;
        message_vision(msg, me, target);
        ap1 = (int)me->query("combat_exp");
        dp1 = (int)target->query("combat_exp");
        ap2 = me->query_str();
        dp2 = target->query_str();
        ap3 = (int)me->query_skill("buddhism",1);
        
        ap = ap1 + ap2 + ap3;
        dp = (dp1 + dp2)/2;
        if( dp < 1 )
                dp = 1;
        if( ap3> 70 || random(ap * 7 / 6) > dp )
        {
                msg = HIR "$n正瞠目间，"+ weapon->query("name")+ HIR"已到了胸前，内劲一吐，\n$n立时口喷鲜血，倒飞出三丈有余！\n\n"NOR;
                message_vision(msg, me, target);
                me->add("force",-200);
                damage = (100 + me->query_str() + random(me->query_skill("staff")))/2;
                wound=random(damage-(int)target->query_temp("apply/armor"));
                if(wound>0) target->receive_wound("kee", wound);
                target->receive_damage("kee", damage);
                COMBAT_D->report_status(target, 0);
                call_out("sandu3", 0, me);
                target->start_busy(1);
                me->start_busy(1);
        }
        else
        {
                msg = HIG "$n躲无可躲，就地一滚，非常狼狈的堪堪躲开了这第二招。\n\n"NOR;
                message_vision(msg, me, target);
                me->add("force",-100);
                me->start_busy(3);
        }

        

        return;
}
void sandu3(object me)
{
        string msg;
        object weapon, target;
        int ap1, ap2, ap3, dp1, dp2, ap, dp, damage, wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        if( !me->is_fighting()|| !living(me) )
                return;

        if( (int)me->query("force") < 400 )
                return;

        if(me->query_skill("staff") < 150)
                return;

        if(me->query_skill("force") < 150)
                return;
        weapon = me->query_temp("weapon");
        msg = HIW "$N梵唱又起，"+ weapon->query("name")+ HIW"象鼓满了风的劲帆，汹涌而出！
        「渡厄」一式之凶险显见佛家动嗔也会做“狮子吼”！\n\n"NOR;
        message_vision(msg, me, target);
        ap1 = (int)me->query("combat_exp");
        dp1 = (int)target->query("combat_exp");
        ap2 = me->query_str();
        dp2 = target->query_str();
        ap3 = (int)me->query_skill("buddhism",1);
        
        ap = ap1 + ap2 + ap3;
        dp = (dp1 + dp2)/2;
        if( dp < 1 )
                dp = 1;
        if( ap3> 80 || random(ap * 4 / 3) > dp )
        {
                msg = HIR "$n被这弧形的汹涌劲气一罩，身法全乱，象喝醉了的东倒西歪！\n\n"NOR;
                message_vision(msg, me, target);
                me->add("force",-300);
                damage = (150 + me->query_str() + random(me->query_skill("staff")))/2;
                wound=random(damage-(int)target->query_temp("apply/armor"));
                if(wound>0) target->receive_wound("kee", wound);
                target->receive_damage("kee", damage);
                COMBAT_D->report_status(target, 0);
                call_out("sandu4", 0, me);
                target->start_busy(1);
                me->start_busy(1);
        }
        else
        {
                msg = HIG "$n临危不乱，看准来势，堪堪拆了这一招。\n\n"NOR;
                message_vision(msg, me, target);
                me->add("force",-100);
                me->start_busy(3);
        }
        
        return;
}

void sandu4(object me)
{
        string msg;
        object weapon, target;
        int ap1, ap2, ap3, dp1, dp2, ap, dp, damage, wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        if( !me->is_fighting()|| !living(me) )
                return;

        if( (int)me->query("max_force") < 800 )
                return;

        if( (int)me->query("force") < 400 )
                return;

        if(me->query_skill("staff") < 180)
                return;

        if(me->query_skill("force") < 180)
                return;
        weapon = me->query_temp("weapon");
        msg = HIC "$N轻声禅唱“回头是岸”，周身七尺劲气涌动，这普陀佛门禅功的无上功力终化作
        「慈光普渡」澎湃而出！\n\n"NOR;
        message_vision(msg, me, target);
        ap1 = (int)me->query("combat_exp");
        dp1 = (int)target->query("combat_exp");
        ap2 = me->query_str();
        dp2 = target->query_str();
        ap3 = (int)me->query_skill("buddhism",1);
        
        ap = ap1 + ap2 + ap3;
        dp = (dp1 + dp2)/2;
        if( dp < 1 )
                dp = 1;
        if( ap3> 100 || random(ap * 3 / 2) > dp )
        {
                msg = HIR "$n似一片枯叶，被「慈光普渡」的劲气包围、卷起、压扁、抛下，\n重重的摔在地上，眼看是不行了！\n\n"NOR;
                message_vision(msg, me, target);
                me->add("force",-400);
                damage = (200 + me->query_str() + random(me->query_skill("staff")))/2;
                wound=random(damage-(int)target->query_temp("apply/armor"));
                if(wound>0) target->receive_wound("kee", wound);
                target->receive_damage("kee", damage);
                COMBAT_D->report_status(target, 0);
                target->start_busy(random(2));
                  me->start_busy(1+random(2));
        }
        else
        {
                msg = HIG "$n一颗流星般急退而出，总算从鬼门关上拣回了一条命。\n\n"NOR;
                message_vision(msg, me, target);
                me->add("force",-100);
                me->start_busy(3);
        }

        

        return;
}
