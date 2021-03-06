// zileidao.c 【紫雷刀法】

#include <ansi.h>

inherit SKILL;
string* skill_head =({
        "$N身形稍退，使出一招",
        "$N仰天长笑，看也不看，一招",
        "$N轻轻一跃，使了个",
        "$N神态悠闲，一招",
        "$N身形转个不停，突然一招",
        "$N脚下踏了个朝阳步，一招",
});

string* skill_tail =({
        "，手中$w势若飞瀑向$n拦腰一斩",
        "，手中$w对准$n的$l凌空一斩",
        "，反手将$w对准$n$l一剑劈去",
        "，手中$w轻妙地划向$n的$l",
        "，反手对准$n$l一刀劈去",
        "，趁$n转身之际，挥出一刀",
});


mapping *action = ({
        ([      "action":		"$N轻抚手中的$w，突然间只见刀光一闪，再闪，又一闪！\n使出一招"YEL"「春雷暴极」"NOR"，三道刺骨的寒气已然袭上了$n的$l",
     		"dodge":     -15,
     		"parry":     5,
     		"damage":    25,
     		"damage_type":     "割伤"
        ]),
        ([      "action":		"只见$N倒提$w，身形急冲，就在与$n错身之际，一招"HIR"「沉雷地狱」"NOR"突然反手一刀从$n后脑斜劈而下",
     		"dodge":     -15,
     		"parry":     5,
                "damage":    30,
                "damage_type":     "劈伤"
        ]),
        ([      "action":		"$N斜身飞起，带出一片匹练也似的刀光卷向$n的$l，好一招"HIG"「天旋地转」"NOR"。",
                "dodge":     -15,
     		"parry":     5,
                "damage":    35,
                "damage_type":     "劈伤"
        ]),
        ([      "action":		"$N突然一脚踢出，使出"HIY"「冬雷霹雳」"NOR"，手中的$w划出一道轻妙的圆弧，\n淡淡的刀光封住了$n的头脸，切断了$n的呼吸",
                "dodge":     -15,
     		"parry":     5,
                "damage":    30,
                "damage_type":     "割伤"
        ]),
        ([      "action":		"只见$N脸色一寒，一招"HIB"「狂雷震九宵」"NOR"使出，从眉捷到脚跟，\n$n周身的血液都似被这无尽的刀势冻住，而生命也仿佛要离体而去",
                "dodge":     -15,
     		"parry":     5,
                "damage":    40,
                "damage_type":     "劈伤"
        ]),   
        ([      "action":		""HIM"「惊雷爆五岳」"NOR"使出，$N刀势渐慢，而$w上带出的寒气却越来越浓。\n就在这时，$n的心头一紧，一道比针尖还要锐利的寒气已刺上了$n$l",
                "dodge":     -15,
     		"parry":     5,
                "damage":    50,
                "damage_type":     "刺伤"
        ]),   
        ([      "action":		"$N也不管三七二十一，高举$w呼！地就是一刀向$n迎面斩下！\n虽然只有一刀，可怕的刀势却似万古不化的寒冰封死了$n的一切退路，\n这招"HIC"「怒雷撕天裂地」"NOR"好狠那",
                "dodge":     -15,
     		"parry":     5,
                "damage":    60,
                "damage_type":     "劈伤"
        ]),   
});


int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return notify_fail("你的内力不够，没有办法练紫雷刀法，多练些内力再来吧。\n");
        if( !(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "blade" || (string)ob->query("material") != "gold" )
                return notify_fail("你必须先找一把地狱雷刀才能练紫雷刀法。\n");
        return 1;
}

int valid_enable(string usage)
{
  return usage =="blade" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30 || (int)me->query("force") < 5 )
                return notify_fail("你的内力或气不够，没有办法练习紫雷刀法。\n");
        me->receive_damage("kee", 30);
        me->receive_damage("sen", 30);
        write("你按着所学练了一遍紫雷刀法。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
 return CLASS_D("sanjie")+"/zileidao/"+action;
}

int stage(int level)
{
	if( level <10 ) return 1;
	else if ( level < 20 ) return 2;
	else if ( level < 40 ) return 3;
	else if ( level < 70 ) return 4;
	else if ( level < 110 ) return 5;
	else if ( level < 160 ) return 6;
	else if ( level < 220 ) return 7;
	else return 8;
}

string level_description(int level)
{
	if ( stage(level) < 1 )
		return YEL "第"+chinese_number( stage(level) )+"层　" NOR;
	else if ( stage(level) < 2 )
		return HIR "第"+chinese_number( stage(level) )+"层　" NOR;
	else if ( stage(level) < 3 )
		return HIG "第"+chinese_number( stage(level) )+"层　" NOR;
	else if ( stage(level) < 4 )
		return HIY "第"+chinese_number( stage(level) )+"层　" NOR;
	else if ( stage(level) < 5 )
		return HIB "第"+chinese_number( stage(level) )+"层　" NOR;
	else if ( stage(level) < 6 )
		return HIM "第"+chinese_number( stage(level) )+"层　" NOR;
	else if ( stage(level) < 7 )
		return HIC "第"+chinese_number( stage(level) )+"层　" NOR;
	else 
		return HIW "第"+chinese_number( stage(level) )+"层　" NOR;
}
void skill_improved(object me)
{
   int m_skill=me->query_skill("sanqing-jian",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"你对紫雷刀法的领悟加深了，你的紫雷刀法进入了一个新的境界！\n"NOR);

     if(random(me->query("kar"))<20){
        tell_object(me,HIW"然而你的心中居然产生了一种失落感！\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"然而你的心中升起一种惆怅的感觉，仿佛有一丝重要的东西没有抓住。\n"NOR);
       return;
     }
     tell_object(me,HIW"你突然福至心灵，对紫雷刀法领悟出了一招新的用法！\n"NOR);
     tell_object(me,"请为这招取一个名字：");
     input_to( (: call_other, __FILE__, "name_skill", me:));
   }
   return;
}

void name_skill(object me, string arg)
{
   mapping* m_actions;
   mapping m_act=([]);
   int content;
   string msg;

   m_actions=me->query("skill_sanqing-jian");
 if(!pointerp(m_actions))m_actions=({});

   content=me->query("str")+2*me->query_skill("unarmed",1)/10;
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=me->query("con")+me->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"刺伤"]);

   if(!arg||arg==" ")arg="紫雷刀法绝技"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+HIB"「"+arg+"」"NOR
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_sanqing-jian",m_actions);
}
