// Room: /d/mojie/neidian
inherit ROOM;

void create()
{
  set ("short", "内殿");
  set ("long", @LONG
这里是无天休息的地方，殿内一片烟雾缭绕。殿两边有两根巨大石
柱。石柱子上刻满了黑莲。殿台上有一座黑莲法台。无天正坐在上
面冥思练功。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"dadian",
]));
  set("objects",([
   __DIR__"npc/wutian" : 1,
]));
  setup();
  replace_program(ROOM);
}
