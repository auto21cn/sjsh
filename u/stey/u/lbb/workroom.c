inherit ROOM;

void create ()
{
  set ("short", "广场");
  set ("long", @LONG

谁也想不到冷冰冰的家居然会是在一个广场上，你不由得开始怀疑这是冷冰冰
的金蝉脱壳之计，肯定是想借着这里人多趁机甩掉你，于是，
你加快了脚步。
LONG);

    set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"workroom.c",
  "west" : __DIR__"workroom.c",
  "south" : __DIR__"workroom.c",
  "north" : __DIR__"gate.c",
]));

  setup();
}
