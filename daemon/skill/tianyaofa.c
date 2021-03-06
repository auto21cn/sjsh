// tianyaofa.c 【天妖屠神法】

#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "action":		"$N发出一声厉叫，手中$w以一招"RED"「吸阴式」"NOR"，阵阵阴魂向$n的$l撞去",
                "dodge":                10,
		"parry":		-10,
                "damage":               30,
                "damage_type":  "砸伤"
        ]),
        ([      "action":               "$N身形一转，一招"YEL"「刁魂破」"NOR"使出，霹雳间$w已砸向$n的$l，$n只觉得六神无主",
                "dodge":                15,
		"parry":		-20,
                "damage":               30,
                "damage_type":  "砸伤"
        ]),
        ([      "action":		"$N舞动$w，一式"MAG"「妖魂冲宵」"NOR"，顿时妖气冲天，劈头盖脸的向$n的$l盖去",
                "dodge":                15,
		"parry":		0,
                "damage":               30,
                "damage_type":  "砸伤"
        ]),
        ([      "action":		"$N手中$w却轻轻一抖，一招"WHT"「吸天蚀日」"NOR"阴毒无比地刺向$n$l，顿时天昏地暗",
                "dodge":                -10,
		"parry":		-10,
                "damage":               25,
                "damage_type":  "刺伤"
        ]),
        ([      "action":		"$N舞动$w，使出"CYN"「千魂屠城」"NOR"，万千妖魂幻出了无数$w向$n砸去",
                "dodge":                0,
		"parry":		-10,
                "damage":               30,
                "damage_type":  "砸伤"
        ]),
        ([      "action":		"$N喉咙里发出几声嚎叫，高举$w向$n击出天魔四蚀球，好厉害的"HIB"「幻魅妖球」"NOR,
                "dodge":                -20,
		"parry":		-20,
                "damage":               50,
                "damage_type":  "刺伤"
        ]),
        ([      "action":		"$N发出一声厉叫，手中$w以一招"HIR"「妖锁囚神」"NOR"狂风骤雨般地向$n的$l连连扫去",
                "dodge":                -20,
		"parry":		-20,
                "damage":               50,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               "$N大喝一声，一招"HIC"「妖乱天地」"NOR"使出，$n只觉得上下颠倒、天地逆转",
                "dodge":                -15,
                "parry":                -15,
                "damage":               50,
                "damage_type":  "抽伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return notify_fail("你的内力不够，没有办法练天妖屠神法。\n");

        if( !(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "stick" )
                return notify_fail("你必须先找一根棒子才能练天妖屠神法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="stick" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30 || (int)me->query("force") < 5 )
                return notify_fail("你的内力或气不够，没有办法练习天妖屠神法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按着所学练了一遍天妖屠神法。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void skill_improved(object me)
{
        if( (int)me->query_skill("dali-bang", 1) > 30 
	 && (int)me->query_skill("dali-bang", 1)  % 10 == 0 ) {
                tell_object(me,
                        RED "\n你突然觉得一股恶气冲上心头，只觉得想杀人....\n\n" NOR);
                me->add("bellicosity", 200);
	}
}

string perform_action_file(string action)
{
return CLASS_D("sanjie") + "/tianyaofa/"+action;
}

int stage(int level)
{
	if( level <10 ) return 1;
	else if ( level < 20 ) return 2;
	else if ( level < 40 ) return 3;
	else if ( level < 80 ) return 4;
	else if ( level < 120 ) return 5;
	else if ( level < 160 ) return 6;
	else if ( level < 200 ) return 7;
	else if ( level < 240 ) return 8;
	else return 9;
}

string level_description(int level)
{
	if ( stage(level) < 1 )
		return RED "吸阴式　" NOR;
	else if ( stage(level) < 2 )
		return YEL "刁魂破　" NOR;
	else if ( stage(level) < 3 )
		return MAG "妖魂冲宵" NOR;
	else if ( stage(level) < 4 )
		return WHT "吸天蚀日" NOR;
	else if ( stage(level) < 5 )
		return CYN "千魂屠城" NOR;
	else if ( stage(level) < 6 )
		return HIB "妖锁囚神" NOR;
	else if ( stage(level) < 7 )
		return HIR "幻魅妖球" NOR;
	else if ( stage(level) < 8 )
		return HIC "妖乱天地" NOR;
	else 
		return HIW "妖极天世" NOR;
}