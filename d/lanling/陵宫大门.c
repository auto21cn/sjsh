//shulin 兰陵

inherit ROOM;

void create ()
{
        set ("short", "陵宫大门");
        set ("long", @LONG

这里是通往兰陵皇宫的的大门,大门两边站着许多士兵
威严的陵宫大门好不威风,这座大门也是兰陵人的骄傲
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 8
                "north" : "/u/calvin/兰陵/地区/皇陵大道2",
                "south" : "/u/calvin/兰陵/地区/陵宫大门1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
      "/d/huanggong/npc/weishi" : 4,
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
