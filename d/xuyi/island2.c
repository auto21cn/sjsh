// 神话世界·西游记·版本（世纪）
/* <SecCrypt CPL V3R05> */

inherit ROOM;

void create ()
{
  set ("short", "南赡部洲海岸");
  set ("long", @LONG

这里就是南赡部洲的海岸，金色的沙滩在阳光下闪闪发光，白浪如雪，碧
波如玉，海水蓝得象一块宝石。信天翁在海风中盘旋，发出“欧欧”的叫
声。
LONG);

  set("objects", ([ /* sizeof() == 1 */

]));
  set("outdoors", 1);
  
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"island",
]));

  setup();
}


