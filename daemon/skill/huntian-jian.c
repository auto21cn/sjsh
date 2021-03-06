

inherit SKILL;
#include <ansi.h>

mapping *action = ({
([	  "name":   "刀枪如白雪",
	"action" : "$N使一式"+BLINK""+HIW"『刀枪如白雪』"NOR"，手中$w顿时幻出,\n"
"刀光剑影，刺向$n的$l！",
	"force" : 120,
	"dodge" : 20,
	"damage" : 300,
	"lvl" : 0,
	"damage_type" : "刺伤"
]),
([	  "name":   "马走似奔狼",
	"action" : "$N使一式"+BLINK""+CYN"『马走似奔狼』"NOR"，腾身飞跃，手中$w于半空中闪下，\n"
"化作一道白色长弧洒向$n的$l",
	"force" : 120,
	"dodge" : 20,
	"damage" : 280,
	"lvl" : 0,
	"damage_type" : "刺伤"
]),
([	  "name":   "刁斗传新令",
	"action" : "$N使一式"+BLINK""+HIG"『刁斗传新令』"NOR"，微微一个转身，\n"
"手中$w却已自肋下穿出，罩向$n的$l",
	"force" : 140,
	"dodge" : 15,
	"damage" : 350,
	"lvl" : 0,
	"damage_type" : "刺伤"
]),
([	  "name":   "冲冠射碧空",
	"action" : "$N使一式"+BLINK""+HIR"『冲冠射碧空』"NOR"，一片燥雷之声，\n"
"手中$w反手疾挑而出，“唰”的一声往$n的$l刺去！",
	"force" : 150,
	"dodge" : 15,
	"damage" : 280,
	"lvl" : 0,
	"damage_type" : "刺伤"
]),
([	  "name":   "时雨庆壶浆",
	"action" : "$N使一式"+BLINK""+HIW"『时雨庆壶浆』"NOR"，剑气漫天飞下，\n"
"手中$w如匹链般洒向$n的$l",
	"force" : 130,
	"dodge" : 25,
	"damage" : 300,
	"lvl" : 0,
	"damage_type" : "刺伤"
]),
([	  "name":   "金鼓震空桑",
	"action" : "$N使一式"+BLINK""+HIY"『金鼓震空桑』"NOR"，一个侧身，\n"
"手中$w疾往斜上挑起，直指$n的$l",
	"force" : 120,
	"dodge" : 25,
	"damage" : 320,
	"lvl" : 0,
	"damage_type" : "刺伤"
]),
([	  "name":   "军行如骤雨",
	"action" : "$N使一式"+BLINK""+HIC"『军行如骤雨』"NOR"，剑招突变，\n"
"接着手中$w如暴风骤雨般的地往$n的胸口刺去！",
	"force" : 110,
	"dodge" : 15,
	"lvl" : 0,
	"damage" : 400,
	"damage_type" : "刺伤"
]),
([	  "name":   "杀气振遐方",
	"action" : "$N使一式"+BLINK""+HIR"『杀气振遐方』"NOR"，面露杀气，\n"
"手中$w从从四面八方刺向$n的$l",
	"force" : 150,
	"dodge" : 35,
	"damage" : 400,
	"lvl" : 0,
	"damage_type" : "刺伤"
]),

([	  "name":   "闪闪快如风",
	"action" : "$N使一式"+BLINK""+HIB"『闪闪快如风』"NOR"，蓦地疾退一步，又冲前三步，\n"
"手中$w化为光弧往$n的$l刺去！",
	"force" : 150,
	"dodge" : 35,
	"damage" : 400,
	"lvl" : 0,
	"damage_type" : "刺伤"
]),
([	  "name":   "剑戟似堆霜",
	"action" : "$N使一式"+BLINK""+HIW"『剑戟似堆霜』"NOR"，身形一晃，疾掠而上，\n"
"手中$w龙吟一声，对准$n的$l连递数剑！",
	"force" : 150,
	"dodge" : 35,
	"damage" : 400,
	"lvl" : 0,
	"damage_type" : "刺伤"
]),


});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够，没有办法练混天一剑。\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
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

int practice_skill(object me)
{
	int flvl=(int)me->query_skill("force");
	int slvl=(int)me->query_skill("sword");

	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("你的内力或气不够，没有办法练习混天一剑。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("你按著所学练了一遍混天一剑。\n");
	if(random(slvl)>flvl)
		me->improve_skill("force", 1);
	return 1;
}
string perform_action_file(string func)
{
return CLASS_D("kunlun") + "/huntian-jian/" + func;
}

