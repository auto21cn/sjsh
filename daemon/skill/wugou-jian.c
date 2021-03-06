

inherit SKILL;
#include <ansi.h>

mapping *action = ({
([	  "name":   "玲珑舍利超凡俗",
	"action" : "$N左脚向前，蹬地跳起，右手勇气剑突向前刺，随转体变向，
使出一式"+BLINK""+HIW"「玲珑舍利超凡俗」"NOR"，剑光如匹练般泄向$n",
	"force" : 120,
	"dodge" : 20,
	"damage" : 300,
	"lvl" : 0,
	"damage_type" : "刺伤"
]),
([	  "name":   "八德池中生紫焰",
	"action" : "$N屈腕抬臂，剑由前向后上方抽带，挺起中平剑奋勇向前，右手勇气剑使出
一式"+BLINK""+HIM"「八德池中生紫焰」"NOR"刺向$n",
	"force" : 120,
	"dodge" : 20,
	"damage" : 280,
	"lvl" : 0,
	"damage_type" : "刺伤"
]),
([	  "name":   "三乘妙典法门开",
	"action" : "$N身形不动，右前臂外旋，剑刃上崩，一招"+BLINK""+HIR"「三乘妙典法门开」"NOR"，
手中勇气剑向前下反刺，一剑指向$n",
	"force" : 140,
	"dodge" : 15,
	"damage" : 350,
	"lvl" : 0,
	"damage_type" : "刺伤"
]),
([	  "name":   "只因东土多英俊",
	"action" : "$N侧身退步，左手剑指划转，右手勇气剑一记"+BLINK""+HIW"「只因东土多英俊」"NOR"，自下上撩指向$n",
	"force" : 150,
	"dodge" : 15,
	"damage" : 280,
	"lvl" : 0,
	"damage_type" : "刺伤"
]),
([	  "name":   "来遇前绿结圣胎",
	"action" : "$N碎步急进，提剑沿剑身方向疾速上崩，一招"+BLINK""+HIG"「来遇前绿结圣胎」"NOR"直取$n",
	"force" : 130,
	"dodge" : 25,
	"damage" : 300,
	"lvl" : 0,
	"damage_type" : "刺伤"
]),
([	  "name":   "七珍妙树长金苔",
	"action" : "$N左上步，抱剑当胸，右手勇气剑一式"+BLINK""+HIY"「七珍妙树长金苔」"NOR"，剑意圆润，刺向$n",
	"force" : 120,
	"dodge" : 25,
	"damage" : 320,
	"lvl" : 0,
	"damage_type" : "刺伤"
]),
([	  "name":   "璎珞明珠绝世埃",
	"action" : "$N平剑斜洗，臂圆剑直，双脚交替弧形迈进，右手勇气剑使出一式"+BLINK""+HIB"「璎珞明珠绝世埃」"NOR"，
剑锋往来运转如梭，连绵不绝刺向$n",
	"force" : 110,
	"dodge" : 15,
	"lvl" : 0,
	"damage" : 400,
	"damage_type" : "刺伤"
]),
([	  "name":   "朝垂泣子规",
	"action" : "$N使一式"+BLINK""+HIC"「朝垂泣子规」"NOR"，手中勇气剑“嗤”的一声斜刺向天空，
随即向下“唰唰”两下，划出一个叉字，往$n的$l刺去",
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
		return notify_fail("你的内力不够，没有办法练吴钩剑法。\n");

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
		return notify_fail("你的内力或气不够，没有办法练习吴钩剑法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("你按著所学练了一遍吴钩剑法。\n");
	if(random(slvl)>flvl)
		me->improve_skill("force", 1);
	return 1;
}
string perform_action_file(string func)
{
return CLASS_D("kunlun") + "/wugou-jian/" + func;
}

