#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_UNIQUE;
void create()
{
        set_name( HIR "诛仙剑" NOR, ({ "zhuxian jian", "jian", "sword" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
                        
"诛仙剑\n"
);
                set("value", 0);
                set("material", "purplegold");
                set("sheenness", 50);
                set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
        }

        init_sword(150);
        setup();

}

/*
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        pro = (int) victim->query_temp("apply/armor_vs_spells");
        dam = (int) me->query("force");

        if(dam > pro)
        {
        victim->receive_damage("sen",150);
        return HIR "诛仙剑闪出妖异的红光。\n" NOR;
        }
}
*/

