//cast escape.c �����ڸ����Ӷݡ�
//this one is for emei...piao, 

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	target = offensive_target(me);

	if( (int)me->query("mana") < 100 )
		return notify_fail("��ķ��������ˣ�\n");

	if( (int)me->query("sen") < (int)me->query("max_sen")/2 )
                return notify_fail("������ͷ�Բ����ѣ��޷�������ü���㣡\n");

        if( (string)me->query("family/family_name") != "������" )
                return notify_fail("�㲢�Ƕ����ɵ��ӣ���ü���������㡣\n");

        if( (int)me->query_skill("mahayana",1) < 80 )
                return notify_fail("��Ĵ�����͹��������죬�޷�������ü���㣡\n");

        if (environment(me)->query("no_flee"))
                return notify_fail("��ü�޷��ݵ��������! \n");

        message_vision(HIW "$Nһ�����������У�ʦ����ң�\n" NOR, me);
        message_vision(HIW "ֻ����ü������̤���������˳�����\n\n" NOR, me);

	if(me->is_fighting() ) {
		if(random((int)me->query("max_mana")) > (int)target->query("max_mana")/2 && random((int)me->query("mana")) > (int)target->query("mana")/2 ) {
 message_vision(HIW "��ü��������ץס$N���׹�һ������ʱ������������Ӱ�����ˣ�\n" NOR, me);
			me->receive_damage("sen", 50);
			me->add("mana", -100);
                        if(random(3)==0) me->move("/d/emei/jinding");
                        else if(random(3)==1) me->move("/d/emei/duguangtai");
                        else me->move("/d/emei/dgtsheshenya");
			message_vision(HIC "ֻ��ſ����һ����$N�Ӱ���е����������˸�ƨ�ɿ�����\n" NOR, me);
		}
		else{
 message_vision(HIC "��ü�������£�ȴ��$n������ס���岻��ս�š�ֻ�ö���$N���һ�������˻�ȥ��\n" NOR, me, target);
			me->receive_damage("sen", 50);
			me->add("mana", -100);
		}
	}

	else{
message_vision(HIW "��ü��������ץס$N���׹�һ������ʱ����������һ��С��$N���˸��߻���أ�\n" NOR, me);
		me->add("mana", -100);
	}

	return 3+random(5);
}
