// 医术得治疗功能
//by koker@sjsh 2001/11

#include <ansi.h>
inherit F_CLEAN_UP;

//int do_heal(object me, object obj, object who);

//void create() { seteuid(getuid()); }

int main(object me, object target)
{
        
        object obj, who;
        int lv;
        lv=me->query_skill("medical",1);
        if(this_player()->is_busy())
           return notify_fail("你正忙着呢．．．\n");
                                 
        //if( !target)
        //   return notify_fail("你要给谁疗伤？\n");

        //if( !objectp(obj = present(target, environment(me))))
         //       return notify_fail("这里没有这个人。\n");
        if((int)me->query_skill("medical",1)<1)
		return notify_fail("你还不会医术,不能疗伤。\n");
        if((int)me->query("force")<50) 
		return notify_fail("你的真气不够，不能疗伤。\n");
	if((int)me->query("sen")<=50)
		return notify_fail("你现在太累了，休息休息吧！\n");
	if((int)me->is_fighting() )
                return notify_fail("战斗中疗伤？找死吗？\n");
       // if(wizardp(who)&&!wizardp(me)) 
        //       return notify_fail("需要吗？\n");
//if( who == me )  {
        
        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
                return notify_fail("你已经受伤过重，只怕以你得医术是不能治好的！\n");
               message_vision("$N盘腿而坐，全身笼起一层"HIW"白雾"NOR"，脸色渐渐"HIR"红晕"NOR"起来。\n", me);
        me->receive_curing("kee", 20 + lv );
       me->add("force", -50);
        me->set("force_factor", 0);
               // return 1;
 //       }
//else{if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
//                return notify_fail("你已经受伤过重，还想给别人治疗。\n");
  //      if( (int)me->query("eff_kee") < (int)target->query("eff_kee"))
    //            return notify_fail("$n不需要你的治疗！\n");
      //  message_vision(HIW"$N一掌拍在$n背心，顺势运气将体内真气传送过去。$n看起来好多了。//\n"NOR, who,target);
//        target->receive_curing("kee", (50 + lv)/2 );}
       
     return 1;    
}


int help(object me)
{	
	write(@HELP
指令格式 : heal [<某人>]

治疗:可以给自己治疗伤口也可以给别人治疗。
     （暂时只开放给自己治疗的功能。）

HELP
    );
    return 1;
}
