#include <armor.h>
inherit ARMOR;
void create()
{
        set_name("校官制服", ({"junfu", "armor"}));
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "套");
                set("long", "一套崭新的校官级昵制服，肩上的两杠两星能看出这是一位中校．\n");
                set("material", "steel");
                set("value", 10000);
                set("armor_prop/armor", 600);
                set("armor_prop/dodge", -5);
        }
        setup();
}

