
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_get", 1);
    set("no_give", 1);
    set("no_drop", 1);
    set("no_sell", 1);
  }
    if(this_player()==environment())
  add_action("do_eat", "eat");
}

void create()
{
set_name( HIY "高手平均丹" NOR , ({"gaoshou dan", "dan"}));
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
set("long", "一颗金黄色的高手大还丹，略微能闻到些许香气,不是常人能得之物。\n");
    set("value", 0);
    set("drug_type", "补品");
  }
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="dan" && arg!="huanhun dan")	return 0;
  
  me->set("eff_sen", (int)me->query("max_sen"));
  me->set("sen", 2*(int)me->query("max_sen"));
  me->set("eff_gin", (int)me->query("max_gin"));
  me->set("gin", 2*(int)me->query("max_gin"));
  me->set("eff_kee", (int)me->query("max_kee"));
  me->set("kee", 2*(int)me->query("max_kee"));
  me->set("mana", 2*(int)me->query("max_mana"));
  me->set("force", 2*(int)me->query("max_force"));
  me->set("food", 2*(int)me->max_food_capacity());
  me->set("water", 2*(int)me->max_water_capacity());
me->add("daoxing",200000);
me->add("potential",20000);
message_vision(HIG "$N轻轻掰开高手大还丹送入嘴中，一时间香气四溢。
只见$N脸上慢慢泛出红晕，看起来有精神多了！但请注意BACKUP哦!\n" NOR, me);
  destruct(this_object());
  return 1;
}

