//shulin 兰陵

inherit ROOM;

void create ()
{
        set ("short", "小路");
        set ("long", @LONG

这是一条长满小草的小道,路人不算很多 ... ...

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "west" : "/u/calvin/兰陵/地区/小路1",
                "south" : "/u/calvin/兰陵/地区/小路3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
