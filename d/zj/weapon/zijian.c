// 紫剑 by Calvin

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit SWORD;
void create()
{
        set_name(MAG"紫剑"NOR, ({"zi sword", "sword"}));
        set_weight(14000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把紫色宝剑，星系的兵器．\n");
                set("no_sell", 1);
                set("no_drop", 1);
                set("no_put", 1);
                set("no_break", 1);
                set("value", 30000);
                set("replace_file", "/d/obj/weapon/sword/qingfeng");
                set("material", "crimsonsteel");
                set("wield_msg", "$N「唰」地一声抽出一把$n握在手中．\n");
                set("unwield_msg", "$N将手中的$n插入腰间。\n");
            set("weapon_prop/int", 2);
        }
        init_sword(100);
        set("is_monitored",1);
        setup();
}
