// banruo.c

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
        int damage, ap, dp, p;
        float at;
        string dodge_skill, msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) || !living(target))
                return notify_fail("���������ࡹֻ����ս����ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʹ�á��������ࡹ��\n");

        if( (int)me->query_skill("banruo-zhang", 1) < 60 )
                return notify_fail("��İ�����δ�ɣ�����ʹ�á��������ࡹ��\n");

        if( (int)me->query_skill("yijinjing", 1) < 60 )
                return notify_fail("����׽δ�ɣ�����ʹ�á��������ࡹ��\n");

        if( (int)me->query("force") < 800 )
                return notify_fail("���������Ϊ���㣬����ʹ�á��������ࡹ��\n"); 

        if( (int)me->query_str() < 20)
                return notify_fail("����������㣬�޷����ӡ��������ࡹ�����ơ�\n");
        if( (int)me->query_con() < 20)
                return notify_fail("��ĸ���Ƿ�ѣ��޷�ʹ�á��������ࡹ��\n");

msg = MAG "\nֻ��$N����ׯ�ϣ�һʽ��"HIY"��������"MAG"������һ��������Ʈ�����ϣ���������ƽ�����һ���ھ���������
�ˣ������������Ƶ磬��һ���ĳ�������$n����ʽƽƽ������һ�ɲ��䣬��ȴ���޿ɵ������޿ɱܣ�\n"NOR;

ap = (int)me->query_skill("banruo-zhang") * (int)me->query("force") * (int)me->query_str();
dp = (int)target->query_skill("force", 1) * (int)target->query("force") * (int)target->query_con();

        ap *= (int)me->query("combat_exp")/200;
        dp *= (int)target->query("combat_exp")/200;    
        ap /= 1000;
        dp /= 1000;

        me->start_busy(3);        
        if(random(ap) > dp/2){
                target->start_busy(random(3));
                damage = me->query_skill("yijinjing",1) + me->query_skill("banruo-zhang", 1);
                damage *= 3;
                if(target->query("force") < 1) at = 5;
                else at = me->query("force") / target->query("force");
                if(at < 1){
                    if(at < 0.5) damage /= 2;
                    damage /= 2;
                    }
                else damage *= at;
                damage -= target->query_temp("apply/armor")*2;
                if (damage < 0) damage = 0;
                if (damage > 1500) damage = 1500;
                damage = damage + random(damage / 2);
                if (target->query_skill_mapped("force") == "wuji-force" &&
                    target->query_skill("wuji-force", 1) > 200){
                      tell_object(me, HIY"\n��֪��һ�ƴ���"+target->name()+"���ϣ�ȴ���罭���뺣������ˮ�齻�ڣ�������ʱ��Ӱ���٣�\n"NOR);
                      msg += "��������Ȼһ�����죬$N�Ѵ�����$n�ؿڣ�ֻ��$p��Ȼȫ���������顣��֪һ�ƹ�ȥ��$n��¶��ɫ�����ö˶˵�վ�ţ�$Nȴ���������ң�����΢΢������\n";
                      target->start_busy(2);
                      message_vision(msg, me, target);
                      me->add("force", -500);
                      me->add("mana", -100);
                      return 1;
                      }

                if ((target->query_skill_mapped("force") == "yijinjing" ))
                        damage /= 2;
                target->add("kee", -100);
                target->receive_wound("kee", damage/3);
                target->add("force", -damage/5);
                me->add("force", -damage/3);
                me->add("combat_exp", (int)me->query_int()*2);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += HIR"$n��ʱ��ǰһ������������,�۵����һ����Ѫ����\n"NOR;
                }
        else {
              msg += CYN"\n$p��æ�������Ծ�����ɣ�����ǿ������������һ����\n"NOR;
                dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
                msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        }
        me->add("force", -400);
        me->add("mana", -100);
        message_vision(msg, me, target);
        return 1; 
}
