// 神话世界·西游记之（世纪）
 
// create by jing 2000.7.13

inherit ROOM;

void create ()
{
  set ("short", "大门");
  set ("long", @LONG

这里是水母娘娘府邸的宫门，虹光闪烁，一对巨大的汉白玉柱子上面雕刻
着各色各样的奇花异草，白玉柱上面是片金色的琉璃檐，檐上飞燕彩凤栩
栩如生。西面住着水母娘娘和她的几个小丫鬟。
LONG);

  set("exits", ([
        "east"   : __DIR__"jiedao3",
        "west"   : __DIR__"guifang",
      ]));
  set("objects", ([
//        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}

