inherit ROOM;

void create()
{
  set ("short", "石屋内");
  set ("long", @LONG

石屋内的摆设虽然简单，但是却整理得十分干净。一个身材高大
的男子正在专心地制作陶器。
LONG);
        set("objects", ([
                __DIR__"npc/bigu": 1, 

                                                
]));
        set("exits", ([ /* sizeof() == 2 */
        "out" : __DIR__"shiwu",
]));
  setup();
}

