// 神话世界·西游记之（世纪）
 
// create by jing 2000.7.13
 
inherit ROOM;

void create ()
{
  set ("short", "街道");
  set ("long", @LONG

一条平直碎石路，路面虽然不是很宽，但是人来人往的也是一片繁荣的景
象。西面是水母娘娘的府邸，向东走不远就可以到蠙城的市中心，北面是
滨城的兵营，营内隐约可听见战马嘶鸣。
LONG);

  set("exits", ([
        "east"   : __DIR__"jiedao1",
        "west"   : __DIR__"jiedao3",
      ]));
  set("objects", ([
//        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}

