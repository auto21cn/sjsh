#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
set_name(HIY"生日蛋糕", ({"birthday cake"}) );
set_weight(1);
set("unit", "个");
set("long", "奶黄色的蛋糕，烤的香喷喷的，奶油上还点缀着两颗可爱的红樱桃。\n");
set("value",100000);
setup();
}
void init()
{
add_action("do_eat","eat");
if (!query("owner")) add_action("do_celebrate","celebrate");
else {
add_action("do_cut","cut");
} 
}
int do_eat(string arg)
{
object me = this_player();
if (!id(arg))
return notify_fail("你要吃什么？\n");
write(HIY"你小心翼翼的把小红樱桃放到嘴里，真甜啊。看着满是奶油的蛋糕，不由的咽了咽口水。在众人的祝福声“Ｈappy Birthday”中狼吞虎咽的吃完了这块生日蛋糕。\n"NOR,me);
 return 1;
}
setup();
