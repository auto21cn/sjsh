#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit F_UNIQUE;
inherit NECK;

int do_wear(string arg);
int do_remove(string arg);
object offensive_target(object me);

void create()
{
        set_name(HIW"天绝灵珠"NOR, ({"tianjue lingzhu"}) );
        set_weight(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("material", "crystal");
                set("value",0);
set("no_steal",1);
//              set("no_drop", "如此宝贵的宝物再世难求啊。\n");
        set("no_give", "这是精华台得来的宝物,怎么可以随便给人呢?\n");
        set("no_steal", "这种稀世之宝怎么能轻易被偷呢?\n");
               set("no_sell", "卖?这种稀世之宝谁买得起啊!\n");
                set("long","这是原本是精华台的一滴水珠,因为长期在精华台吸收了无数日月精华而变为了一件宝物！\n
n");
//              set("replace_file", "/d/obj/flower/rose");
                set("armor_prop/armor", 1);
                set("spells/fire", 2);
                set("spells/thunder",2);
                set("spells/water",2);
                set("spells/wind",2);
                set("spells/earth",2);
        }
        setup();
}

int init()
{
        object who = this_player();
        {
        if ( interactive(environment()) && 
        environment()->query("combat_exp") < 800000 )
        this_object()->move("/obj/empty"); 
         }
        add_action("do_wear","wear");
        add_action("do_remove", "remove");

}

// This function selects a random target for offensive spells/functions.
object offensive_target(object me)
{
        int sz;
        object *enemy;

        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0;

        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4;

        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
}

int do_wear (string arg)
{
  object me = this_player();
  object zhu = this_object();
  string name = zhu->query("name");
  string msg;

if(arg!="all"&&arg != "sheng lingzhu" )
    return notify_fail("你要佩带什么？\n");
  msg = "$N戴上一颗"+name+"，顿感神清气爽。\n"; 
  zhu->set("wear_msg",msg);
remove_call_out("shengzhuconditions");
call_out("shengzhuconditions",1,me,zhu);
  return 0;
}

int do_remove (string arg)
{
  object me = this_player();
  object zhu = this_object();
  string name = zhu->query("name");
  string msg;

if ( arg!= "all" && arg != "sheng lingzhu")
    return notify_fail("你要摘掉什么？\n");

  msg = "$N将"+name+"轻轻地摘下来……\n"; 
  zhu->set("unequip_msg",msg);
remove_call_out("shengzhuconditions");
  return 0;
}

void shengzhuconditions(object who,object ob)
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
        msg = HIW"天绝灵珠"HIG"五彩毫光"HIR"猛然四射，刹时"HIG"*"HIY"风"HIG"*"HIC"雨"HIG"*"HIB"雷"HIG"*"HIW"电"HIG"*"HIR"齐至，"HIG"山崩地裂！"HIR"那声势不是一般"HIW"宝物"HIR"所比及的！\n"NOR;
//divid by 10;

                ap = 500000;
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
call_out("shengzhuconditions",7,who,ob);
}
