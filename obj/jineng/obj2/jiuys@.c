// jiuys.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name( MAG"九转易髓丹" NOR, ({"jiuzhuan dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一种十分珍贵的药丸，对增加功力大有益处。\n");
                set("unit", "粒");
                set("value", 60000);
                set("drug_type", "yaodan");
                set("base_unit","粒");
        }
        setup();
}

int do_eat(string arg)
{
        mapping my;
        object me=this_player();
        int lv;
        if(! arg || arg!="jiuzhuan dan")
                {
                write("你使用什么药？\n");
                return 1;
                }
        if (time() - me->query("last_eat/jz") < 90000)
        {
                write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
                return 1;
        }

        lv = me->query("level",1);
        
        if (lv < 50 )
        {
                write("你现在仙界等级太低，吃了" + name() + "也是没用。\n");
                return 1;
        }

        me->set("last_eat/jz", time());

        message_vision(CYN "$N" CYN "吃下" + name() +
                       CYN "，顿时青筋暴长。\n" NOR, me);

        me->add_maximum_force(50);
        me->add_maximum_mana(50);
        me->start_busy(3);
        destruct(this_object());
        return 1;
}
