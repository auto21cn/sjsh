// Room: /d/shaolin/guangchang4.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "精进场");
	set("long", @LONG
这是后殿前的精进场，广场青砖铺地，因为多年的踩踏而凹
凸不平。前后各是两堵高墙，把整个广场夹在中间，形成一个窄
窄的长方形。西边开了扇小门，一股香气袅袅地飘了过来。北面
是个大门，几位僧人在此把守。
LONG );
	set("exits", ([
		"south" : __DIR__"guangchang3",
		"northup" : __DIR__"houdian",
	]));
	set("outdoors", "shaolin");
//	set("no_clean_up", 0);
	set("objects",([
                __DIR__"npc/sengbing" : 2,
                __DIR__"npc/huikong" : 1,
	]));
	setup();
}


