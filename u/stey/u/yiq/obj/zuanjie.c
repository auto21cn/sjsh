#include <armor.h>

#include <ansi.h>
inherit FINGER;

void create()
{
  set_name(HIW"结婚钻指"NOR, ({ "zuan jie", "zuanjie", "ring" }));
  set("long","晶莹剔透的"+query("name")+"上面刻着衣青和舟儿于公元二零零一年二月二十六日成婚"+"。\n");
  set("weight", 0);
                set("armor_prop/armor", 50);
                set("armor_prop/dodge", 50);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "枚");
    set("value", 12000);
    set("material", "diamond");
    set("armor_prop/armor", 1);
    set("armor_prop/personality", 10);
  }
  setup();
}       
int query_autoload() { return 1; }
