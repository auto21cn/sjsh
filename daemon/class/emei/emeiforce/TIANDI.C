// heal.c

#include <ansi.h>

int exert(object me, object target,string name)
{
        if( me->is_fighting() )
                return notify_fail("战斗中运功疗伤？找死吗？\n");

        if( (int)me->query("force") < 50 )
                return notify_fail("你的真气不够。\n");

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
                return
notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");
        write( HIW "你坐了下来运起天地术，将手掌合并，缓缓地将真气轻轻扑在身上....\n" NOR);
        message("vision",
                HIW + me->name() +
"的脸上亮出晶莹的颜色，缓缓睁开的眼里透出健康的气息。\n"
NOR,
                environment(me), me);
        me->receive_curing("kee", 10 + (int)me->query_skill("force")/5 );
        me->add("force", -50);
        me->set("force_factor", 0);

        return 1;
}


