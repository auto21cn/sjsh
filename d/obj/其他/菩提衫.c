#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("菩提衫", ({"puti cloth", "cloth"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一件丝绸大长袍，质地和裁剪都不错．\n");
                set("material", "cloth");
                set("unit", "件");
                set("value", 2000);
                set("armor_prop/armor", 4);
                set("armor_prop/personality", 1);
        }
        setup();
}
