// huxiaojian.c 【虎啸皇剑】

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"action":		"$N一抖手中的$w，使出一招"HIR"「一啸红尘惊」"NOR"，瞬间刺出三十六剑，$n顿时手忙脚乱，分不清虚实",
		"dodge":		-10,
                "parry":                -20,
		"damage":		35,
		"damage_type":		"刺伤"
	]),
	([	"action":		"$N一剑刺向$n，使出一招"HIC"「再啸湖海翻」"NOR"，$n急忙向旁边一闪，\n不料$N一运劲儿，手中的$w突然弯了过来，转而刺向$n的$l",
		"dodge":		-20,
                "parry":                -10,
		"damage":		50,
		"damage_type":		"刺伤"
	]),
	([	"action":		"$N手中$w连续划出几个光环，一阵吸力带得$n向前踏出一步，$N左手剑指已刺向$n的$l，正是一招"HIB"「三啸鬼神辟」"NOR,
		"dodge":		-20,
                "parry":                -20,
		"damage":		55,
		"damage_type":		"刺伤"
	]),
	([	"action":		"第四招"HIW"「绝啸穹苍灭」"HIW"，$N一转身，背向$n，手中$w从腋下反手刺向$n的$l",
		"dodge":		-10,
                "parry":                -10,
		"damage":		60,
		"damage_type":		"刺伤"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够，没有办法练虎啸皇剑。\n");
	if( !(ob = me->query_temp("weapon")) ||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int valid_effect(object me, object weapon, string name, int skill)
{
}
string perform_action_file(string action)
{
	return CLASS_D("sanjie")+"/huxiaojian/"+action;
}

int practice_skill(object me)
{
	int flvl=(int)me->query_skill("force");
	int slvl=(int)me->query_skill("sword");

	if( (int)me->query("kee") < 30 || (int)me->query("force") < 3 )
		return notify_fail("你的内力或气不够，没有办法练习虎啸皇剑。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("你按著所学练了一遍虎啸皇剑。\n");
	if(random(slvl)>flvl)
		me->improve_skill("force", 1);
	return 1;
}

int stage(int level)
{
	if( level <60 ) return 1;
	else if ( level < 120 ) return 2;
	else if ( level < 180 ) return 3;
	else return 4;
}

string level_description(int level)
{
	if ( stage(level) < 1 )
		return HIR "第"+chinese_number( stage(level) )+"层　" NOR;
	else if ( stage(level) < 2 )
		return HIC "第"+chinese_number( stage(level) )+"层　" NOR;
	else if ( stage(level) < 3 )
		return HIB "第"+chinese_number( stage(level) )+"层　" NOR;
	else 
		return HIW "第"+chinese_number( stage(level) )+"层　" NOR;
}