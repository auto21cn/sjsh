// mie.c ������  ����Ʈ��piao��

#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        object weapon;
        int i;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С��𽣡���\n");
        if (me->query_skill_mapped("force")!="emeiforce")
                return notify_fail("���𽣡�������϶����ķ�����ʹ�á�\n");
        if(!me->is_fighting())
                return notify_fail("���𽣡�ֻ����ս����ʹ�ã�\n");
        if((int)me->query("max_force") < 1000 )
                return notify_fail("�������������\n");
        if((int)me->query("force") < 1000 )
                return notify_fail("����������㣡\n");
        if((int)me->query("sen") < 500 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
         i=(int)me->query_skill("tianlei-sword",1)+(int)me->query_kar();
        if( i < 120)
                return notify_fail("�������˫�����𻹲�����ʹ����һ�л������ѣ�\n");
	 message_vision(HIG"\n$N��������������һ��ŭ����һ���޺�֮�·������С�"HIW"��"HIG"����\n"NOR,me);
	 me->delete("env/brief_message");
	 target->delete("env/brief_message");
        me->set_temp("QJB_perform", 7);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->delete_temp("QJB_perform");
        me->receive_damage("sen", 100+random(100));
        me->add("force", -200);
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        me->start_busy(1+random(1));
        return 1;
}
