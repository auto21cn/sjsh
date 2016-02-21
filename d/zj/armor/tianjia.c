// tianjia.c 四重天甲
#include <armor.h>
#include <ansi.h>

inherit ARMOR;

void create()
{
        set_name(HIM"四重天甲"NOR, ({"sichong armor","tianjia", "jia", "armor"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这是四重天神专用的站甲．\n");
                set("material", "steel");
                set("value", 0);
                set("armor_prop/armor", 130);
                set("armor_prop/dodge", 20);
        }
        setup();
}
