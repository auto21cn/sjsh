// changan lingtai
// room1.c

inherit ROOM;

void create()
{
  set ("short", "卧室");
  set ("long", @LONG

武圣门帝子休息的地方，独人单间，看来武圣门弟子休息的地方
也很讲究。高床软枕，香炉旁伴，衣柜、书桌、书柜、脸盘、浴
盘……都很齐全，而且还有一个大屏风分割房子，十分实用。
LONG);
set("exits", ([ /* sizeof() == 4 */
"west": __DIR__"room1",
]));
//set("objects", ([
//               "/clone/money/thousand-cash": 3]));

        set("no_clean_up", 0);
        set("sleep_room",1);
        set("if_bed",1);

        setup();
        replace_program(ROOM);
}

