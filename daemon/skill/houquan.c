// houquan.c 猴拳

inherit SKILL;

mapping *action = ({
([      "action" : "\n$单腿微曲，忽的向前扑出，一式「仙猴摘桃」，二爪直出，抓向$n的双眼",
        "force" : 130,
        "dodge" : 5,
        "parry": 10,
        "damage_type" : "抓伤",
        ]),
([      "action" : "$N左手虚晃，一式「灵猴攀枝」，右手直击，反扣$n的肩井大穴",
        "force" : 150,
        "dodge" : 10,
        "parry": 20,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N一臂前伸，一臂后指，一式「猿臂轻舒」，攻向$n的两肋",
        "force" : 180,
        "dodge" : 10,
        "parry": 25,
        "damage_type" : "瘀伤",
]),
([      "action" : "\n$N忽然缩成一团，使一式「八方幻影」，双掌无形无定，一爪抓向$n的胸口",
        "force" : 180,
        "dodge" : 25,
        "parry": 20,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N猛吸一口气，一弯腰，使一式「水中揽月」，双爪疾扣向$n的小腹",
        "force" : 170,
        "dodge" : 15,
        "parry": 10,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N猛的向上高高跃起，一式「落地摘星」，居高临下，一爪罩向$n的头骨",
        "force" : 190,
        "dodge" : 20,
        "parry": 20,
        "damage_type" : "抓伤",
]),
([      "action" : "$N左掌一晃，轻飘飘的抓向$n的$1",
        "force" : 80,
        "dodge" : -20,
        "parry": -20,
        "damage_type" : "抓伤",
]),
([      "action" : "$N右拳紧接着对着$n$1直击过去",
        "force" : 190,
        "dodge" : 20,
        "parry": 20,
        "damage_type" : "瘀伤",
]),
([      "action" : "$N吱的一声怪叫，和身扑上，又向$n抓来",
        "force" : 200,
        "dodge" : 0,
        "parry": 0,
        "damage_type" : "抓伤",
]),
});

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练猴拳必须空手。\n");
        if ((int)me->query_skill("force", 1) < 30)
                return notify_fail("你的基本内功火候不够，无法学猴拳。\n");
        if ((int)me->query("max_force") < 100)
                return notify_fail("你的内力太弱，无法练猴拳。\n");
        return 1;
}

int valid_enable(string usage) { return usage=="unarmed"||usage=="parry"; }

mapping query_action(object me, object weapon)
{
        int i;
        i=me->query_temp("TP_perform");
        if( !me->query_temp("TP_perform") ) {
        return action[random(6)];
        }else {
        return action[i];
        }
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 30)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("force") < 10)
                return notify_fail("你的内力不够练猴拳。\n");
        me->receive_damage("kee", 15);
        me->add("force", -5);
        return 1;
}

string perform_action_file(string func)
{
return CLASS_D("tianpeng") + "/houquan/" + func;
}
