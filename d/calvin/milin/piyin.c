// /d/changan/playerhomes/stdbed.c
// this  is a standard bed for married couples.
// wiz should modify /d/changan/playerhomes/h_playername  to 
// connect here.
// IMPORTANT: should copy this to bed_playername, otherwise...  

inherit ROOM;

void create()
{
        set("short", "庇荫宅");
        set("long", @LONG

也不知道这是谁盖起来的,炎热的夏天人们喜欢在
这里庇荫,纳凉.有些人干脆在这里铺上新鲜的苇
叶,悍然大睡.
LONG
        );

        set("exits", ([
                "north" : "/d/calvin/milin/milin3",
            ]));

  set("objects", ([
        "/d/obj/其他/seat" : 2,
        "/d/obj/其他/table" : 1
  ]));

        set("sleep_room",1);
        set("if_bed",1);                             

        setup();
}
