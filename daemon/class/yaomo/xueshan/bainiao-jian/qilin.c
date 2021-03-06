#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int i;
        string str;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「麒麟九式」？\n");

        if(!me->is_fighting())
                return notify_fail("「麒麟九式」只能在战斗中使用！\n");
         
        if(me->query("family/family_name")!="大雪山")
                return notify_fail("你不能用别派的特殊攻击\n");

        if((int)me->query("max_force") < 1000 )
                return notify_fail("你的内力不够！\n");

         if((int)me->query("force") < 900 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("kee") < 200 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

              i=(int)me->query_skill("bainiao-jian",1)+(int)me->query_cor();

        if( i < 120)
                return notify_fail("你的百鸟剑法别还不够，使用这一招会有困难！\n");

        message_vision(HIC"$N蓦地一声巨吼，声如狻猊，状若麒麟，手中"+me->query_temp("weapon")->name()+
                                      HIC"左突右击，剑气氤氲，「麒麟九式」的精髓尽展无疑！\n"NOR,me,target);

        me->delete("env/brief_message");
        target->delete("env/brief_message");

        me->set_temp("QJB_perform", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("QJB_perform", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("QJB_perform", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("QJB_perform", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("QJB_perform", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("QJB_perform", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("QJB_perform", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("QJB_perform", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("QJB_perform", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete_temp("QJB_perform");

        me->receive_damage("kee", 200);
        me->add("force",-300);
           me->start_busy(1+random(1));

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
           if (target->query("eff_kee")<0 || (!living(target) && target->query("kee")<0))  
                       {str=HIW+target->name()+HIM"被"HIG+me->name()+HIM"用百鸟剑法之精髓"+HIY+"「麒麟九式」"+HIM+"杀死了，听说"+target->name()+"身中九剑,尸首被戳成了马蜂窝！";
                         message("channel:rumor",HIM"【"+HIC+"江湖传闻"+HIM+"】某人："+str+"\n"NOR,users());                       
                       }


        return 1;
}


