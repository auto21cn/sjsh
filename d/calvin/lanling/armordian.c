//兰陵

inherit ROOM;

void create ()
{
        set ("short", "千奇店");
        set ("long", @LONG

刚一进门就闻到一股异常芬芳的香气,这里是买卖千奇物品的商店
女老板是老英雄萧振远的二女儿，也是振远镖局大老板，巾帼不让
须眉。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
    "east" : "/d/calvin/lanling/jie6",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                 "/d/obj/其他/装备老板" : 1,
        ]));

//        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
