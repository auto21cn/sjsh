//Cracked by Kafei
//sanhuang-wan.c
//kane 1998.6
#include <ansi.h>
inherit PILL;

void setup()
{}

int cure_ob(string);
void create()
{
	set_name(HIY"���Ʊ�����"NOR, ({"sanhuang wan","wan"}));
	set_weight(50);
	if (clonep())
    	set_default_object(__FILE__);
    else
    {
		set("unit", "��");
        set("long",
"һ�ŻƳγε�ҩ�裬��ţ�ơ��ۻơ��ƻ�������Ϊ������������ҩ��\n���ƶ��ɣ����䵱�����ˡ��ƶ�����ҩ���Գ涾����Ч��\n");
		set("value", 20000);
		set("medicine", 1);
    }
        setup();
}

int cure_ob(object me)
{
	if (me->query_condition("hot_drug") > 0)
	{
       	if (me->query("neili") > 500)
	       	me->add("neili", -500);
		else
			me->add("neili",-(me->query("neili")));

		message_vision(BLU"$N����һ��"+query("name")+BLU"�����������������У���������ԭ����ʳ\n̫��̫�࣬ҩЧ�ʵ��䷴��\n" NOR, me);
        destruct(this_object());
        return 1;
	}
   	
	message_vision(HIM"$N����һ��"+query("name")+HIM"��ֻ��ͨ����̩��������������ƴ��к�ת��\n"NOR, me);
	me->receive_heal("qi", 200+random(200));
	me->apply_condition("hot_drug", 15);

	if ((int)me->query_condition("insect_poison") > 0) 	
    		me->clear_condition("insect_poison");
        destruct(this_object());
   	return 1;
}

