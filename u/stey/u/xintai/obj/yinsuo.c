// 银索金铃

#include <weapon.h>
#include <ansi.h>

inherit WHIP;
inherit F_UNIQUE;

void create()
{
        set_name(HIC"银索"HIY"金铃"NOR, ({"yinsuo jinling", "whip"}));
        set_weight(5000);
	if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long","一条银白色的长索，细看上面缀满了金铃，缠在手上宛然就是一副手链。\n");
                set("unit", "副");
		set("replace_file", "/d/obj/weapon/whip/pibian");
                set("value", 20000);
                set("wield_msg", HIY"$N左手轻扬，叮叮当当一阵声响一条银色绸带忽地甩了出来。\n"NOR);
		set("unwield_msg", HIY"$N把手中$n缠回手腕．\n"NOR);
		set("weapon_prop/courage", 20);
		}
        init_whip(150);
        setup();
}

mixed hit_ob(object me, object victim)
{
    int damage_bonus = 0;
    
    if( (string)me->query("family/family_name") == "盘丝洞"
    		&& me->query_skill("yinsuo-jinling",1) > 1)
    damage_bonus = me->query_skill("yinsuo-jinling",1);
    damage_bonus = (damage_bonus+random(damage_bonus))/2;

    victim->receive_wound("kee",damage_bonus);
    return HIC"银索"+HIY"金铃"+HIW"上霞光映射！\n" NOR;

}
