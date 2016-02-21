#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
string msg;
int extra;
object weapon;
extra = me->query_skill("deisword",1);
if( !target ) target = offensive_target(me);
if( !target
||      !target->is_character()
||      !me->is_fighting(target) )
       return notify_fail("［彩蝶狂舞］只能对战斗中的对手使用。\n");
weapon = me->query_temp("weapon");
message_vision(HIC  "\n$N使出蜀山心剑中的第一招---彩蝶生波\n\n"+ "一招连环三剑，手中的"+ weapon->name()+  "闪电般向$n攻出第一剑！" NOR,me,target);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg
);
message_vision(HIC"\n$N第二招---飞蝶扑火!"NOR,me,target);
if (extra = me->query_skill("mindsword",1)<100) return notify_fail("你的蝶恋花剑法还不够纯熟！\n");
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg
);
message_vision(HIC"\n$N第三剑---群碟乱舞"NOR,me,target);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"+10),TYPE_REGULAR,msg
);
me->start_busy(2);
return 1;
}
