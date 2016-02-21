 // hugujiu.c 

#include <ansi.h>
#include "medicine2.h"

void create()
{
        set_name( GRN"虎骨酒" NOR, ({"hugu jiu", "jiu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一棕色的虎骨酒，外伤的治疗很见成效。\n");
                set("base_unit", "瓶");
                set("value", 300);
                set("unit","瓶");
                set("drug_type", "yaodan"););
             }
        setup();
}

int do_eat(string arg)
{
        object me=this_player();
        mapping my;
       
        if ( !arg || arg != "hugu jiu" )
        {
                write("你要用什么药？\n");
                return 1;
        }
        if (time() - me->query_temp("last_eat/hugu") < 5)
        {
                write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
                return 1;
        }

         my = me->query_entire_dbase();
        if (my["eff_kee"] == my["max_kee"])
        {
                write("你现在并没有受伤，不必服用" + name() + "。\n");
                return 1;
        }

        me->set_temp("last_eat/hugu", time());

        message_vision(HIW "$N" HIW "咕嘟咕嘟地灌下两口" + name() +
                       HIW "，看上去精神好多了。\n" NOR, me);

        me->receive_curing("kee", 150);
        me->receive_heal("kee", 150);

//        me->start_busy(1);
        destruct(this_object());
        return 1;
}
