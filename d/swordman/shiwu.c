// Room: /d/qujing/wudidong/south
inherit ROOM;

void create()
{
  set ("short", "石屋");
  set ("long", @LONG

一间小小的石屋。小石屋的石门（shimen)禁闭着，看来不推
石门开是无法进入屋内的。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "northdown" : __DIR__"xiaolu4",
]));
  setup();
}
void init()
{
  add_action("do_push", "push");
}
int do_push(string arg)
{
  object me=this_player();
  int myeffstr=me->query("str")+me->query_skill("unarmed", 1)/10-2;
  int mykar=me->query_kar(), diff=40-mykar, percentage;
  int mymaxkee=me->query("max_kee"), mymaxsen=me->query("max_sen");
  if ((arg != "shimen" && arg != "石门") || !arg)
    return notify_fail("你要推什么？\n");
  if (me->is_busy()) return notify_fail("你忙着呢！\n");
  if (me->query_temp("no_move")) return notify_fail("你被定住了，什么也干不了。\n");
  if (me->query_str()<40||myeffstr<20)
    {
      message_vision("$N憋足了力气往石门推去，但费尽九牛二虎之力，也动不得分毫。\n", me);
      return 1;
    }
  if(random(diff)>4)
    {
      message_vision("$N憋足了力气往石门推去，反而被石门震得双手发麻。\n", me);
      percentage=diff*2;
      me->receive_wound("kee", mymaxkee*percentage/100);
      return 1;
    }
  message_vision("$N用力推动石门，只听一阵“轧轧”声过后，石门缓缓地打开了。\n", me);
  message_vision("$N赶快闪进门内，石门随即又合上了。\n", me);
  me->move(__DIR__"wunei");
  return 1;
}
