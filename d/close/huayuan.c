//tianpei 天篷
//by calvin and leox 共同开发
//版权所有,未经许可不得翻录

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "府邸花园");
        set ("long", @LONG
这里是天蓬元帅府的的一个小花园,这里四季长春,无数的奇花异草
把里装点的异常美丽.平时天蓬大元帅总是喜欢来这里修身养性,而其他
弟子也喜欢来这里赏欣这里的美丽风景.
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
           "east" :"/d/tianpeng/xiaolu1",
           "west" :"/d/tianpeng/hualu",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
