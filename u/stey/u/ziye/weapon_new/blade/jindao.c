#include <weapon.h>
//add keenness by ziye 2001/3

inherit BLADE;

void create()
{
        set_name("金刀", ({"jin dao", "dao"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把金光闪闪的圆头长刀，刀把上镶嵌有白玉。\n");
                set("value", 2500);
                set("material", "purplegold");
                            set("keenness", 30);
                set("wield_msg", "$N「唰」地一声抽出一把$n握在手中，金光闪闪！\n");
                set("unwield_msg", "$N将手中的$n插入金色刀鞘。\n");
        set("weapon_prop/courage", 15);

        }
        init_blade(50);
        setup();
}

