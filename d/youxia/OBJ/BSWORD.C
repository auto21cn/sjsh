// Ҷ�³� �� ���ɽ�    created 17-06-2001 ����Ʈ(piao)

#include <weapon.h>
#include <ansi.h>


inherit SWORD;

void create()
{
	set_name(HIW"�w�ɽ�"NOR, ({ "feixian sword" ,"sword"}) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѿ�����Ӷ��ַ����Ľ�\n");
		set("value", 400);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������Ľ��ʡ�\n");
	}
	init_sword(160);
	setup();
}