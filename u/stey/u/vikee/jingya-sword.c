//jingya-sword. 【静雅剑法】
//created by vikee
//2000-12-5 17:40

/*
静雅剑法    dodge  -10    parry  -10    damage  15
此剑法为李太白吟诗作赋时悟出，共八式，练习于气血修为颇有益处。
*/

inherit SKILL;

mapping *action = ({
	([	"name":			"幻",
		"action":
"$N一抖手中的$w，口中唱诺：蜀道难，难于上青天。瞬间刺出数剑，$n顿时手忙脚乱，分不清虚实",
		"dodge":		-10,
                "parry":                -20,
		"damage":		5,
		"damage_type":		"刺伤"
	]),
	
	([	"name":                 "绕",
		"action":
"$N一剑刺向$n，$n急忙向旁边一闪，\n"
"不料$N一运劲儿，口中吟道：而来四万八千岁，不与秦汉通人烟。手中的$w突然弯了过来，转而刺向$n的$l",
		"dodge":		-20,
                "parry":                -10,
		"damage":		10,
		"damage_type":		"刺伤"
	]),
	([	"name":                 "缠",
		"action":
"$N手中$w连续划出几个光环，一阵吸力带得$n向前踏出一步，嘴中喃喃自语：挥手自兹去，萧萧班马鸣。$N左手剑指已刺向$n的$l",
		"dodge":		-20,
                "parry":                -20,
		"damage":		15,
		"damage_type":		"刺伤"
	]),
	([	"name":                 "点",
		"action":
"$N一转身，背向$n，低头沉吟：举头望明月，低头思故乡。手中$w从腋下反手刺向$n的$l",
		"dodge":		-10,
                "parry":                -10,
		"damage":		10,
		"damage_type":		"刺伤"
	]),
	([	"name":                 "劈",
		"action":
"$N举起手中的$w，长啸而歌：飞流直下三千尺，疑是银河落九天。自上而下，劈向$n的$l",
		"dodge":		0,
                "parry":                -10,
		"damage":		25,
		"damage_type":		"割伤"
	]),
        ([      "name":                 "砍",
		"action":
"$N身子一侧，手中的$w平着挥出，朗声长吟：醉看风落帽，舞爱月流人。砍向$n的$l",
                "dodge":                -5,
                "parry":                -5,
                "damage":      		15, 
                "damage_type":  	"割伤"
        ]),
	([      "name":                 "刺",
		"action":
"$N向前踏出半步，手中$w中宫直进，低声长吟：红颜弃轩冕，白首卧松云。刺向$n的前心",
                "dodge":                -10,
                "parry":                0,
                "damage":     		20,
                "damage_type":  	"刺伤"
        ]),
	([      "name":                 "扑",
                "action":
"$N双脚一顿，低吟道：夫天地者，万物之逆旅。光阴者，百代之过客。身子凌空，头下脚上，手中$w刺向$n的头顶",
                "dodge":                -5,
                "parry":                -5,
                "damage":               20,
                "damage_type":  	"刺伤"
        ]),
});

int valid_learn(object me)
{
	
	object ob;
	
	if( (int)me->query("max_force") < 100 )
		return notify_fail("你的内力不够，没有办法练静雅剑法。\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry" || usage=="literate";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	
	int sword_level=(int)me->query_skill("sword");
	int pot=random(2)*random(2);
	
	

	if( (int)me->query("sen") < 20
	||	(int)me->query("force") < 3 )
		return notify_fail("你的精神或内力不够，没有办法练习静雅剑法。\n");
	
	if (me->query("max_kee")*1000 > me->query("combat_exp"))
		return notify_fail("你的武学修为没到，练习静雅剑法也是徒劳。\n");
	
			
	me->receive_damage("sen", 10);
	me->add("force", -2);
	
	write("你按照自己的学识，练习了一遍静雅剑法。\n");	
		
		if (me->query("max_kee") < (me->query_skill("jingya")+sword_level/2)*10)
		{
		 me->add("max_kee",pot);
		 me->add("eff_kee",pot);		
		}	
	
	return 1;
}
