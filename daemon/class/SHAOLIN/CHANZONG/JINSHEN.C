#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void remove_effect(object me, int amount);
int cast(object me, object target)
{
        int skill;
   if( target != me ) return 
    notify_fail("��ֻ�ܽ�"HIY"���������塹"NOR"�����Լ������ϡ�\n");
        if( (int)me->query("mana") < 2*(int)me->query_skill("chanzong"))
        return notify_fail("��ķ��������ˣ��޷�ʩչ"HIY"���������塹"NOR"��\n");
        if( (int)me->query_temp("daoqian") ) 
        return notify_fail("���Ѿ����˹����ˡ�\n");
        if( (int)me->query("sen") < 150 )
        return notify_fail("��ľ����޷����У��޷�ʩչ"HIY"���������塹"NOR"��\n");
        skill = (int) me->query_skill("chanzong",1);
        if(skill < 100) return notify_fail("������ڷ𷨵ȼ�������\n");
        skill = random(skill)+skill;
        me->add("mana", -150);
        message_vision( HIY"\n$N΢΢�������ڷ𷨣����Ͻ�������������ֳ�������\n" NOR, me);
        me->add_temp("apply/dodge", skill);
        me->set_temp("daoqian", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me,skill :), skill);
        if( me->is_fighting() ) me->start_busy(2);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("daoqian");
   message_vision(HIY"$N���ϵĽ�⽥��ɢȥ�ˡ�\n"NOR,me);
}