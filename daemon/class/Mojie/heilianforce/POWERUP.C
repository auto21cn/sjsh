// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;


        skill = me->query_skill("heilianforce",1);

	if( skill > 300 ) {
		skill=300;
	}

        if( target != me ) 
		return notify_fail("��ֻ���ú����ķ�׳���Լ���ս������\n");

        if( (int)me->query("force") < skill*2 )     
		return notify_fail("�������������\n");
        if( (int)me->query_temp("powerup") ) 
		return notify_fail("���Ѿ����˹����ˡ�\n");

        me->add("force", -skill);
        me->receive_damage("kee", 50);

        message_vision(
                HIW "$N�������,�����������"BLK"����֮��"NOR""HIY"������Ѹ�ٵ������˼��� \n" NOR, me);

        me->add_temp("apply/attack", skill/3);
        me->add_temp("apply/armor", skill/3);
        me->add_temp("apply/dodge", skill/3);
	me->add_temp("apply/strength", skill/3);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5 :), skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        if(!me) return;
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
	me->add_temp("apply/strength", - amount);
	me->add_temp("apply/armor", - amount);
        me->delete_temp("powerup");
        tell_object(me, "��ĺ���֮������һ������ϣ��������ջص��\n");
}
