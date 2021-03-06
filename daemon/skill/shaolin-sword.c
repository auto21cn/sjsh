
// shaolin-sword.c【少林伏魔剑】
//for 道士 NPCs, if going to be used by players, need refine. 

#include <ansi.h>

inherit SKILL;
string* skill_head =({
        "$N一招",
        "只见$N纵身轻轻跃起,一招",
        "$N使出",
        "$N飘然而进，一式",
        "$N纵身轻轻跃起,剑光如轮急转，一招",
        "$N按剑而发，一招",
});

mapping *action = ({
	([	"action":
"$N握紧手中$w一招"+BLINK""+BLK"「无影剑法」"NOR"中的"+BLINK""+HIW"「来去自如」"NOR"点向$n的$l,
$n却无法找到$N的身影,心中大惊",
		"dodge":		-5,
                "parry":                -10,
		"damage":		10,
		"damage_type":	"刺伤"
	]),
	([	"action":
"$N一招"+BLK"「无影剑法」"NOR"中的"+BLINK""+HIW"「日月无光」"NOR"，无数$w上下刺出，直向$n逼去,
仿佛剑光遮住了太阳,$n眼前一黑",
		"dodge":		-25,
                "parry":                -5,
		"damage":		20,
		"damage_type":	"割伤"
	]),
	([	"action":
"$N淡淡一笑，向前跨上一步，手中$w使出"+BLINK""+BLK"「无影剑法」"NOR"中的"+BLINK""+HIW"「剑气封喉」"NOR"直刺$n的喉部,
$n被吓的连退几步,此时已无还手之力",
		"dodge":		-10,
                "parry":                -15,
		"damage":		15,
		"damage_type":	"刺伤"
	]),
	([	"action":
"$N虚恍一步，使出"+BLK"「无影剑法」"NOR"中的"+BLINK""+HIW"「心境如水」"NOR"手中$w直刺$n的要害,
$N如此冷静令$n觉得其中有诈",
		"dodge":		-20,
                "parry":                -5,
		"damage":		15,
		"damage_type":	"刺伤"
	]),
	([	"action":
"只见$N抡起手中的$w，使出"+BLK"「无影剑法」"NOR"中的"+BLINK""+HIW"「佛光普照」"NOR"万点金光直射$n,
金光遮住了$n的眼睛,可见此招造诣之深",
		"dodge":		-20,
                "parry":                -20,
		"damage":		15,
		"damage_type":	"刺伤"
	]),
        ([      "action":
"$N抡起手中的$w，使出"+BLK"「无影剑法」"NOR"中的"+BLINK""+HIW"「风行叶落」"NOR"无数剑光直射$n,
四周顿时刮起了狂风,周围的树叶与剑气暴雨一般卷向招架中的$n",
                "dodge":                -25,
                "parry":                -5,
                "damage":      		20, 
                "damage_type":  "刺伤"
        ]),
	([      "action":
"$N使出"+BLK"「无影剑法」"NOR"中的"+BLINK""+HIW"「声东击西」"NOR"，手中$w如刮起狂风一般闪烁不定，
看似没有危机,突然剑气合为一处刺向$n",
                "dodge":                -5,
                "parry":                -10,
                "damage":     		10,
                "damage_type":  "刺伤"
        ]),
           ([      "action":
"$N随手使出"+BLK"「无影剑法」"NOR"之奥义"+BLINK""+HIW"「无影无踪」"NOR"，手中$w如鬼魅一般铺天盖地的刺向$n,
$n使出浑身介术难挡此招,唯有撤身而退",
                "dodge":                -25,
                "parry":                -10,
                "damage":     		20,
                "damage_type":  "刺伤"
        ]),
            ([      "action":
"$N使出"+BLK"「无影剑法」"NOR"之最终绝技"+BLINK""+HIW"「蛟龙出水」"NOR",手中$w犹如蛟龙一般刺向$n ,
$n仿佛看到一条蛟龙脱水而出,顿时不知所措",
                "dodge":                -25,
                "parry":                -10,
                "damage":     		30,
                "damage_type":  "刺伤"
        ]),	
       ([	   "action":
"$N使一式"+BLK"「达摩剑法」"NOR"中"+BLINK""+HIC"「万事随缘往」"NOR"，手中$w嗡嗡微振，幻成一条疾光刺向$n的$l",

		"dodge":		-5,
                "parry":                -10,
		"damage":		10,
		"damage_type":	"刺伤"
	]),
	([	"action":
"$N错步上前，使出"+BLK"「达摩剑法」"NOR"中"+BLINK""+HIC"「来去若梦行」"NOR"，剑意若有若无，$w淡淡地向$n的$l挥去",
		"dodge":		-25,
                "parry":                -5,
		"damage":		20,
		"damage_type":	"割伤"
	]),
	([	"action":
"$N淡淡一笑，一式"+BLK"「达摩剑法」"NOR"中"+BLINK""+HIC"「浮世沧桑远」"NOR"，纵身飘开数尺运发剑气，手中$w遥摇指向$n的$l",
		"dodge":		-10,
                "parry":                -15,
		"damage":		15,
		"damage_type":	"刺伤"
	]),
	([	"action":
"$N纵身轻轻跃起，一式"+BLK"「达摩剑法」"NOR"中"+BLINK""+HIC"「轮回法舟轻」"NOR"，剑光如轮疾转，霍霍斩向$n的$l",

		"dodge":		-20,
                "parry":                -5,
		"damage":		15,
		"damage_type":	"刺伤"
	]),
	([	"action":
"$N手中$w中宫直进，一式"+BLK"「达摩剑法」"NOR"中"+BLINK""+HIC"「水月通禅寂」"NOR"，无声无息地对准$n的$l刺出一剑",
		"dodge":		-20,
                "parry":                -20,
		"damage":		15,
		"damage_type":	"刺伤"
	]),
        ([      "action":
"$N手中$w斜指苍天，剑芒吞吐，一式"+BLK"「达摩剑法」"NOR"中的"+BLINK""+HIC"「鱼龙听梵音」"NOR"，对准$n的$l斜斜击出",

                "dodge":                -25,
                "parry":                -5,
                "damage":      		20, 
                "damage_type":  "刺伤"
        ]),
	([      "action":
"$N左指凌空虚点，右手$w逼出丈许雪亮剑芒，一式"+BLK"「达摩剑法」"NOR"中"+BLINK""+HIC"「千里一苇去」"NOR"刺向$n的$l", 
               "dodge":                -5,
                "parry":                -10,
                "damage":     		10,
                "damage_type":  "刺伤"
        ]),
           ([      "action":
"$N合掌跌坐，一式"+BLK"「达摩剑法」"NOR"中"+BLINK""+HIC"「禅心顿自明」"NOR"，$w自怀中跃出，如疾电般射向$n的胸口",
                "dodge":                -5,
                "parry":                -10,
                "damage":     		10,
                "damage_type":  "刺伤"
        ]),
          ([      "action":
"$N收剑运气,将"+BLK"「无影剑法」"NOR"和"+BLK"「达摩剑法」"NOR"浑然一体,使出双剑合一"+BLINK""+HIY"「慈航普渡」"NOR"式，
$w如飞龙般自掌中跃出，直向$n的胸口穿入。",
                "dodge":                -35,
                "parry":                -10,
                "damage":     		40,
                "damage_type":  "刺伤"
        ]),

});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够，没有办法练少林伏魔剑。\n");

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

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("你的内力或气不够，没有办法练习少林伏魔剑。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("你按着所学练了一遍少林伏魔剑。\n");
	return 1;
}
string perform_action_file(string action)
{
  return CLASS_D("shaolin") + "/shaolin-sword/" + action;
}
