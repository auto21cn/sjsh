// taiyi.c 【太乙仙法】
inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
    if(((int)me->query_skill("yaofa", 1)>1
//     || (int)me->query_skill("dao",1)>1
     || (int)me->query_skill("gouhunshu", 1)>1
     || (int)me->query_skill("seashentong",1)>1
     || (int)me->query_skill("moonshentong", 1)>1
//     || (int)me->query_skill("buddhism", 1)>1
     || (int)me->query_skill("dengxian-dafa", 1)>1
     || (int)me->query_skill("baguazhou", 1)>1
     || (int)me->query_skill("pingtian-dafa", 1)>1
     || (int)me->query_skill("pansi-dafa",1)>1)
//     || (int)me->query_skill("taoism", 1)>1)
     &&(int)me->query_skill("taiyi", 1)>200)
     return notify_fail("你体内尚存魔界法力，太乙仙法无法精进！\n");
     
	if( (int)me->query_skill("spells", 1) < 10 
		|| (int)me->query_skill("spells", 1) <= (int)me->query_skill("taiyi", 1) )
		return notify_fail("你的法术修为还不够高深，无法学习太乙仙法。\n");
	return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("zhenyuan") + "/taiyi/" + spell;
}

string type() { return "magic";} 
