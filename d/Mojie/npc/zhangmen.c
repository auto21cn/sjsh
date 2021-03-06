// worker.c

inherit NPC;
#include <ansi.h>
int rank_me();
void create()
{
        set_name("冷月·孤心", ({"zhang men","zhang","man"}));
        set("gender", "男性" );
        set("class", "mo" );
        set("title",HIY"魔域主教"NOR);
        set("age", 30);
        set("long", "魔界掌门大师兄。\n");
        set("combat_exp", 1500000);
	  set("daoxing", 1500000);
        set("attitude", "peaceful");
	  set("int", 25);
	  set("class", "mo");
        set("eff_dx", 30000);
        set("nkgain", 200);
              set("per", 30);
        set("max_kee", 2500);
        set("max_sen", 2500);
        set("force", 2500);
        set("max_force", 2500);
        set("force_factor", 50);
        set("mana", 2500);
        set("max_mana", 2500);
        set("mana_factor", 50);
        set_skill("unarmed", 280);
        set_skill("dodge", 280);
        set_skill("parry", 280);
        set_skill("spells", 280);  
        set_skill("molianspells", 280);
        set_skill("literate", 280);
        set_skill("sword", 280);  
        set_skill("xueling-jian", 280);
        set_skill("shifo-zhi", 280);  
        set_skill("moshenbu", 280);
        set_skill("dodge", 280);  
        set_skill("force", 280);   
        set_skill("heilianforce", 280);
        map_skill("spells", "molianspells");
        map_skill("unarmed", "shifo-zhi");
        map_skill("force", "heilianforce");
        map_skill("sword", "xueling-jian");
        map_skill("parry", "xueling-jian");
        map_skill("dodge", "moshenbu");
        create_family("魔界", 2, "弟子");
	 set("inquiry", ([
		"name" : "嘿嘿，我就是魔界掌门大弟子！\n",
		"here" : "无天魔界。\n",
		"掌门大弟子" :"你需要通过无天的同意才能出任掌门一职。\n",		
		"掌门弟子" :"你需要通过无天的同意才能出任掌门一职。\n",			
		"大弟子" :"你需要通过无天的同意才能出任掌门一职。\n",			
		"掌门" :"你需要通过无天的同意才能出任掌门一职。\n",		
		"职位" : (: rank_me :),	 
	]) );


        setup();
        carry_object("/d/obj/armor/jinjia.c")->wear();
        carry_object("/d/mojie/obj/sword")->wield();
}
int rank_me()
{
	object me=this_player();
	object ob=this_object();
	int exp;
	exp=(int)me->query("combat_exp");
        if( me->query("title") == "魔界无法无天魔尊"
          ||me->query("title") == "魔界无法无天神姬")
		return notify_fail("你已经是掌门身份，还来要什么职位．\n");
	if(me->query("gender") == "男性")
	{
	if( me->query("family/family_name") == "魔界")
	{
                if( exp <= 20000 ){
			me->set("title", "魔界伙房柴夫");
		} else if(exp <= 50000 ){
			me->set("title", "魔界送饭童仆");
		} else if(exp < 100000 ){
			me->set("title", "魔界护山道人");
		} else if(exp <= 200000 ){
			me->set("title", "魔界解剑池掌教");
		} else if(exp <= 500000 ){
			me->set("title", "魔界神机山人");
		} else if(exp <= 1000000 ){
			me->set("title", "魔界太乙真人");
		} else if(exp <= 2000000 ){
			me->set("title", "魔界龙虎天师");
		} else {
			me->set("title", "魔界万圣天尊");
		}

		tell_object(me, HIR""+ob->query("name")+"对你说：你可以做"+me->query("title")+"。\n"NOR);
		tell_room(environment(me),
HIR""+ob->query("name")+"对"+me->query("name")+"说：你可以做"+me->query("title")+"。\n"NOR, ({me, me}));
                
	}
        }
        else
        {
	if( me->query("family/family_name") == "魔界三星洞")
	{
                if( exp <= 20000 ){
			me->set("title", "魔界伙房橱娘");
		} else if(exp <= 50000 ){
			me->set("title", "魔界沏茶女童");
		} else if(exp < 100000 ){
			me->set("title", "魔界内院主管");
		} else if(exp <= 200000 ){
			me->set("title", "魔界医乐院道姑");
		} else if(exp <= 500000 ){
			me->set("title", "魔界紫须圣姑");
		} else if(exp <= 1000000 ){
			me->set("title", "魔界月露仙姑");
		} else if(exp <= 2000000 ){
			me->set("title", "魔界芙蓉圣母");
		} else {
			me->set("title", "魔界渌水神姬");
		}

		tell_object(me, HIR""+ob->query("name")+"对你说：你可以做"+me->query("title")+"。\n"NOR);
		tell_room(environment(me),
HIR""+ob->query("name")+"对"+me->query("name")+"说：你可以做"+me->query("title")+"。\n"NOR, ({me, me}));
	}
        }
	return 1;
}
