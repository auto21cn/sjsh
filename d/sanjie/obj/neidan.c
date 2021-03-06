// neidan.c 纯阳内丹

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_get","你手里一松"+this_object()->query("name")+"从指间滑落！\n");
    set("no_give","这么珍贵的药，哪能随便给人？\n");
    set("no_drop","这么宝贵的丹药，扔了多可惜呀！\n");
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }
  add_action("do_eat", "eat");
}

void create()
{
  set_name(HIM "纯阳内丹" NOR, ({"chunyang neidan","neidan","dan"}));
  set_weight(200);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "纯阳先师积聚了四百年功力而成的内丹。\n");
    set("value", 0);
    set("drug_type", "补品");
  }
  
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  int force_add, howold;
  howold= (int)me->query("mud_age") + (int)me->query("age_modufy");
  if (!id(arg))
    return notify_fail("你要吃什么？\n");
  
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity());
    force_add = 100+random(2);
  me->add("eat_neidan", 1);
  if( (int)me->query("eat_neidan") > 10) {
  if( (int)me->query("maximum_force") > 100 ) {
    me->add_maximum_force(-5);
    }
    me->delete("eat_neidan");
    message_vision(HIM"$N还没有运气就吞下内丹，消化不了内丹的四百年内劲，觉得丹田胀的难受。\n" NOR, me);
    tell_object(me,BLK"哗……地一声，$N内息逆转，吐出一口鲜血！\n" NOR);
  }
  else if( me->add_maximum_force(force_add)){
    message_vision(HIM "$N吃下一颗内丹，只觉血气翻腾，舒畅无比，忍不住大叫：好吃！还要！\n" NOR, me);
  }
  else message_vision(HIM "$N吃下一颗内丹，脸色突然转红，过了许久才淡了下去！\n" NOR, me);
  if( howold > 1382400 ) {
    me->add("mud_age", -43200);
    me->add("mud_age_time", 1);
  }
  
  destruct(this_object());
  return 1;
}

