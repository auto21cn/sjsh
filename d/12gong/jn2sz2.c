// by HAPP@YSZZ

inherit ROOM;

void create ()
{
        set ("short", "山路");
        set ("long", @LONG

这是走向黄道酉宫的路上，只见前面可以看到美丽的黄道酉宫耸立在佛陀峰！
云雾中隐隐约约还可以看见山下的黄道戍宫。
LONG);


        set("exits", ([
        "eastup"    :       __DIR__"shuangzi",
            "southdown"  :       __DIR__"jn2sz1",
        ]));

        set("outdoors", "12gong");
        setup();
}
