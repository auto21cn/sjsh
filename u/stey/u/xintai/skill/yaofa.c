// yaofa
inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{	
	if(((int)me->query_skill("dao", 1)>1
         || (int)me->query_skill("taiyi",1)>1
         || (int)me->query_skill("gouhunshu", 1)>1
         || (int)me->query_skill("seashentong",1)>1
         || (int)me->query_skill("moonshentong", 1)>1
         || (int)me->query_skill("buddhism", 1)>1
//         || (int)me->query_skill("dengxian-dafa", 1)>1
         || (int)me->query_skill("baguazhou", 1)>1
//         || (int)me->query_skill("pingtian-dafa", 1)>1
//         || (int)me->query_skill("pansi-dafa",1)>1
         || (int)me->query_skill("taoism", 1)>1)
         &&(int)me->query_skill("yaofa", 1)>200)
         return notify_fail("你体内尚存仙家法力，无法继续提高[妖法]！\n");

        if( 2*(int)me->query_skill("spells") <= (int)me->query_skill("yaofa") )
        return notify_fail("你的法术修为还不够高深，无法学习「妖法」。\n");
        return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("yaomo") + "/wudidong/yaofa/"+spell;
}

string type() { return "magic"; } 
