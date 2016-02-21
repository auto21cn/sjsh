#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "桃花迷阵");
        set("long",@LONG
这是一片桃花的海洋。四周一望无际，全是盛开的桃花。微风拂过，
落英缤纷。周围静悄悄的。远处偶尔传来一声鸟叫。往北是一片桃
花林，往南远远看见几只猴子。
LONG );
       set("exits", ([
           "south" : "/d/dntg/hgs/houshan3",
           "north" : __DIR__"tao0",
       ]));
	   set("objects",([
		__DIR__"npc/xiang" : 1,
	]));

       set("outdoors","taohua");
//       set("no_clean_up", 0);
       setup();
       replace_program(ROOM);
}
void init()
{
        object ob;
        mapping myfam;
	ob = this_player() ;
        if(query("exits/south")) 
			 myfam = (mapping)ob->query("family");
			if(myfam && myfam["family_name"] == "盘丝洞")
        {
        delete("exits/south");
        set("exits/south", "/d/dntg/hgs/houshan3");
	return ;
        }       
        if ((int)ob->query_skill("spells",1) >= 100 )
        {
        delete("exits/south");
        set("exits/south", __DIR__"tao0");
	return ;
        }

             
	delete("exits/south");
        set("exits/south", __DIR__"/d/dntg/hgs/houshan4");
}
