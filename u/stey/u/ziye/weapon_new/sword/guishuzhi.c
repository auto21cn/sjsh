// guishuzhi.c
//add keenness by ziye 2001/3

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("����֦", ({ "guishuzhi","gui","zhi","jian", "sword" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
              set("keenness", 0);
		set("material", "wood");
		set("long", "����һ��ϸ���Ĺ���֦��\n");
		set("wield_msg", "$N���һ��ϸ���Ĺ���֦���������С�\n");
		set("unequip_msg", "$N�������е�$n��\n");
		set("weapon_prop/courage", -4);
	}
	init_sword(6);
	setup();
}