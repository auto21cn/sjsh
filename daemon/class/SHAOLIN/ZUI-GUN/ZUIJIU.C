// zuijiu.c ��������

#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
        int skill;
        if( !target ) target = offensive_target(me);
         if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��"HIB"��������"NOR"��ֻ�ܶ�ս���еĶ���ʹ�á�\n");


        
                if( !target->query_temp("zui_baxian") )
               target->set_temp("zui_baxian", 1);
                skill = (int)me->query_skill("zuibaxian") / 15;

        if (me->query_skill_mapped("dodge") != "shaolin-shenfa")
                return notify_fail("������û�����ֵ��������޷�ʩչ��"HIB"��������"NOR"����\n");
        if( (int)me->query_skill("shaolin-shenfa", 1) < 100 )
                return notify_fail("�����������������죬ʹ������"HIB"��������"NOR"����\n");
        if( (int)me->query_skill("yijinjing", 1) < 100 )
                return notify_fail("����׽�񹦲�����죬ʹ������"HIB"��������"NOR"����\n");
        if( (int)me->query("force", 1) < 300 )
                return notify_fail("�������������㣡\n");     

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
        
        message_vision(
    HIB "ֻ��$N���һ�ھ�����һʽ"HIW"���������ơ�"NOR""HIB"��Χ��$n"HIB"һҡһ�ڵ��߶��š�"NOR"\n" NOR, me, target);

        me->start_busy(random(1));
        me->add("force", -200);
        me->add("sen", -10);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                 message_vision(
    HIR " $N����ȴ�ǰ������ԣ��������ƣ�ʹ��$n"HIR"��֪���룡"NOR"\n" NOR, me, target);
                target->start_busy( skill/50 + 3);
        } 
        else if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                 message_vision(
    HIR " ȴ��$N���°������ԣ��������ƣ�ʹ��$n"HIR"�����ڵ����Գ��У�"NOR"\n" NOR, me, target);
                target->start_busy( skill/50 + 5);
        }
        else {
          message_vision(
    CYN "����$n"CYN"������$N��������������˿�ȥ��"NOR"\n" NOR, me, target);
          me->start_busy(2);
        }
        target->add_temp("zui_baxian", 1);
        return 1;
}