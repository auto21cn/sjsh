inherit NPC;
int ask_yue();
void create()
{
set_name("月奖励使者", ({"shi","shizhe"}));
set ("long", @LONG
他是在这里负责给大家发月奖励(yue)的，
大家赶快向他要（ask）吧。
LONG);
set("inquiry", ([
"yue": (: ask_yue :),
        ]));
setup();
}
int ask_yue()
{
object me=this_player();
int yyy;
   if (this_player()->query("yyy")){
message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
         command("say 月奖励已经给你了，不要妨碍其他人！！\n");
 return 1;
}
me->add("daoxing",50000);
me->set("yyy",1);
message_vision("$N对着$n说道恭喜你得到了奖励。\n",this_object(),this_player());
return 1;
}
