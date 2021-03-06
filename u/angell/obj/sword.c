#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name("绝世好剑",({ "jueshi haojian", "jueshi", "sword", "jian" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 1);
                set("rigidity", 10);
                set("sharpness", 10);
                set("unique", 1);
                set("material", "steel");
                set("weapon_prop/dodge", 5);
                set("weapon_prop/parry", 5);
                set("treasure",1);              
                set("long", "这是一柄四尺来长，全身乌黑，出自东海拜剑山庄，经山庄三代铸剑师历时百年而成的剑中之王。\n"); 
                set("wield_msg", "刹那间，一道气壮山河的黑虹，宛似天际忽起的闪电一般，在尚不及眨眼的微小空隙，出现在众人眼前！\n");
                set("unwield_msg", "\n但见$N将$n向天一直，数匹布条随风而起，将$n严严实实地裹了起来！\n");
        }
        init_sword(500);
        setup();
}

int wield()
{
        object ob = environment();
        object me = this_object();
        mapping weapon_prop;
        object *obj, *inv, weapon;
        int ret, i, j;

        if (ob->query("combat_exp") < 500000 
            || ob->query_str() < 30 || ob->query("max_force") < 3000 
            || ob->query("force") < 2000){
                message_vision(HIY"$N的手刚刚触摸到$n的剑把，突然一股由天而生的力量自剑中穿来，将$N击出丈远！
$n也随之掉落地上。\n"NOR, ob, me);
                ob->receive_damage("qi", 100);
                ob->receive_wound("qi", 50);
                me->move(environment(ob));
                return 0;
                }
       else if (ret=::wield()){
           message_vision(HIB"\n只见$N将一裹在帆布里的长剑缓缓抽出，乌黑的剑身带出来的却是王霸的气势！\n\n"NOR, ob, me);
           ob->add("force", -200);
           obj = all_inventory(environment(ob));
           if(sizeof(obj) > 1)
               message_vision(HIY"忽然，众人身上所带之剑纷纷自动跃出，插在$N身前的地上，剑尖指天！\n"NOR, ob);
           for(i=0; i<sizeof(obj); i++) {
                if(obj[i]==ob ) continue;
                inv = all_inventory(obj[i]);
                for(j= 0;j< sizeof(inv);j++){
                       if(!mapp(weapon_prop = inv[j]->query("weapon_prop"))) continue;        
                       if(inv[j]->query("skill_type")!="sword") continue;
                       if(inv[j]->query("equipped")){
                          if(obj[i]->query("force") > 5000){
                             obj[i]->add("force", -100);
                             tell_object(obj[i], HIW"你觉得手中之"+inv[j]->name()+HIW"在猛烈震动，幸而你双手紧握，才没有让它飞出！\n"NOR);
                             continue;  
                             }
                           else {
                                tell_object(obj[i], HIW"你觉得手中之"+inv[j]->name()+HIW"在猛烈震动，你把握不住，竟然脱手飞出！\n"NOR);
                                tell_room(environment(ob), YEL+obj[i]->name()+"一个把握不住，手中"+inv[j]->name()+YEL"竟然脱手飞出！\n"NOR,({ obj[i] }));
                                }
                           }
                       inv[j]->move(environment(ob));
                       }
           }
           return ret;
       }
}

