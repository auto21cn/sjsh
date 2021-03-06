//by koker@sjsh 20020107..
#include <weapon.h>
#include <dbase.h>
#include <ansi.h>

inherit F_UNIQUE;
//inherit NECK;
inherit SWORD;
object offensive_target(object me);
void create()
{
        set_name(HIG"惊雷剑"NOR, ({ "jinglei sword","sword","jian"}) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", HIG"这是蜀山派的镇山宝剑之一。\n"NOR);
                set("material", "force");
        }
        init_sword(600);
       setup();
}
int init()
{
   add_action("do_wear","wield");
   add_action("do_remove","unwield");
      remove_call_out("do_melt");
      call_out("do_melt", 1);
}

void do_melt()
{
	if(this_object()) call_out("melt", 10+random(10));
}

void melt()
{
	object env;

	if(!this_object()) return;

	env=environment(this_object());

	if( env->is_character() )
	{//a player or a NPC.
		if( (int)env->query_skill("zixia-shengong", 1) < 100 )
		{
			if(environment(env))
				message_vision(HIW"你的紫霞神功还不纯熟，惊雷剑突然化做一道白光冲入云霄不见了。\n", env);
			destruct(this_object());
			return;
		}
	}

	else if( (int)env->query_max_encumbrance() > 0 && !environment(env) )
	{//a room.
		if( (string)env->query("outdoors") != "shushan" )
		{
			tell_object(env,HIW"你的紫霞神功还不纯熟，惊雷剑突然化做一道白光冲入云霄不见了。\n");
			destruct(this_object());
			return;
		}
	}
}

int do_wear(string arg)
{
   string str,name;
     if (arg!="ice sword"&&arg!="sword"&&arg!="jian")
                  return 0;
    name=this_object()->query("name");
          str="$N暗运真气，两掌间突然射出一道五彩的"+name+"\n";
  this_object()->set("wield_msg",str);
    remove_call_out("cool");
    call_out("cool",1,this_object());
    return 0;
}
int do_remove(string arg)
{
   string str,name;
     if (arg!="ice sword"&&arg!="sword"&&arg!="jian")
                  return 0;
    name=this_object()->query("name");
    str="$N一反手,暗收真气，"+name+"瞬间消失在空中.\n";
    this_object()->set("unwield_msg",str);
  remove_call_out("cool");
   return 0;
}
void cool(object who,object ob)
{
     object target;
     int ap,dp,damage;
     string msg;
          
string type;
type = ob->query("armor_type");
if( who->query_temp("armor/" + type) && ob->query("equipped")!="worn")
return;
  if( who->is_fighting())
     {
        target = offensive_target(who);
  if( ! target ) return ;      
 if( ! present( target,environment(who)) ) return ;    
        msg = HIR"$N的惊雷剑光猛然四射，刹时风雨雷电齐至，山崩地裂！\n"NOR;
//divid by 10;

                ap = 5000000;
                dp = target->query("combat_exp");
                        
                        
                if( random(ap + dp) > dp )
                 {
                        damage = 500+random(300);
                        damage -= (int)target->query("max_mana") / 10 + random((int)target->query("eff_sen") / 5);
                        damage -= random((int)target->query("mana_factor"));

                        if( damage > 0 ) 
                        {
                                msg += HIC "结果$n躲避不及，被雷电劈个正着，又被地火烧得皮焦骨烂。\n
被山石砸得皮破血流，还被风迷了双眼，又被水浇个透心凉，肌肤尽裂。\n" NOR;

                                target->receive_damage("sen", damage*8/5);
                                target->receive_wound("sen", damage*2/3);
                                target->receive_damage("kee", damage*8/5);
                                target->receive_wound("kee", damage/2);
                                target->start_busy(5);
                        } 
            else
//here, cast failed and the target's mana_factor will be added to the previous
//damage to hurt yourself:(...note damage<0.
                msg += HIC "\n谁知$n毫无反应。\n" NOR;   
                }
                else
                        msg += "但是被$n躲开了。\n";

                message_vision(msg, who, target); 
        }
call_out("cool",7,who,ob);
}
