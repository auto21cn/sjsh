// 药材 路径 shanxia by Calvin

inherit ROOM;
void create()
{
  set ("short", "山下");
  set ("long", @LONG

这里一眼往上看,实在是看不到顶,高高的悬崖,有点让人望而生畏。

LONG);

  set("exits", ([ 
  ]));

  set("outdoors", __DIR__"");
  setup();
}

void init ()
{
  add_action ("do_climb","climb");
}

int do_climb (string arg)
{
  object who = this_player();

  message_vision ("$N奋力向上爬去。\n",who);
  if (who->query("combat_exp") < 5000 ||
      who->query("kee") < 100)

  {
    message_vision ("$N手一松连人带石哗啦一声滑了下来。\n",who);
    who->unconcious();
    return 1;
  }
  who->add("kee",-100);
  who->move(__DIR__"shanpo");
  return 1;
}
