
// zhixin.c

#include <ansi.h>

int exert(object me)
{
	int skill;
        skill = (int)me->query_skill("emeiforce",1);

	if (me->query_condition("linji_zhixin"))
                return notify_fail("���Ѿ�����֮�Ķ����ˣ�\n");


	if( me->is_fighting() )
                return notify_fail("ս�����޷���֮�Ķ�����\n");

        if( (int)me->query("force") < 200)
		return notify_fail("�������������\n");

        if( (int)me->query_skill("emeiforce",1) < 60)
                return notify_fail("��Ķ����ķ����𲻹���\n");

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
                return notify_fail( "���Ѿ����˹��أ��޷��˹���\n");

	message_vision(
HIY "$N������������֮��ׯ���������������Ͽ������£��پ���̨������....\n"
"վ�������������Դ�������˲��١�\n" NOR, me );
	me->apply_condition("linji_zhixin", (int)skill/20);
        me->add("force", -200);
        me->add("eff_sen", -10);
        me->add("sen", -20);
	me->add("int", (int)skill/30);
	me->set("linji/int", (int)skill/30);
	return 1;
}
