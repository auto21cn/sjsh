//shulin 兰陵

inherit ROOM;

void create ()
{
        set ("short", "紫冥宫");
        set ("long", @LONG

这里是皇宫众多妃子嬉戏取闹的地方,这里有无数的水果
遍地的鲜花,中央的小水池里金鱼游来游去,花丛中的蝴蝶
多色而又美丽,把整个紫冥宫装点的格外美丽 ... ...
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 8
                "north" : "/u/calvin/兰陵/地区/坤宫",
                "south" : "/u/calvin/兰陵/地区/钦陵宫",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
