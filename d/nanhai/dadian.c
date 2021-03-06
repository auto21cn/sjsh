inherit ROOM;
int do_open(string arg);
int do_close(string arg);

void create()
{
        set("short", "大圣禅寺宝殿");
        set("long",@LONG 

    这是一座宽广的大殿，正面有一座高约二十余尺的佛祖宝像，通体
金光耀眼。座下香烟缭绕，大殿两旁树立两根檀木大柱，南面是一道红
杉大门(gate)。　
LONG );
        set("exits", ([
  "north" : __DIR__"taijie",
  "east" : __DIR__"zoulang3",
        ])); 
set("valid_startroom", 1);
    set("item_desc",([ 
        "gate" : "一道三丈来高的朱红杉木包铜大门。\n"
    ]));
        set("objects",([
         "/d/nanhai/npc/shami" : 1,
     __DIR__"npc/heshang" : 2,
        ]));
//        set("no_clean_up", 0);
        setup();
//        replace_program(ROOM);
}
 
void init()
{
        add_action("do_open", "open");
        add_action("do_close", "close");
}
void close_gate()
{
        object room;

        if(!( room = find_object("/d/nanhai/frontgate")) )
                room = load_object("/d/nanhai/frontgate");
        if(objectp(room))
        {
                delete("exits/south");
                        message("vision", "小沙弥上前把大门关了起来。\n", this_object());
                room->delete("exits/north");
                message("vision", "乒地一声，里面有人把大门关上了。\n", room);
        }
} 

int do_close(string arg)
{
        if (!query("exits/south"))
                return notify_fail("大门已经是关着的了。\n");

        if (!arg || (arg != "gate" && arg != "south"))
                return notify_fail("你要关什么？\n");

        message_vision("$N朝小沙弥点了点头。\n", this_player());

        remove_call_out("close_gate");
        call_out("close_gate", 2);

        return 1;
} 

int do_open(string arg)
{
        object room;

        if (query("exits/south"))
                return notify_fail("大门已经是开着了。\n");

        if (!arg || (arg != "gate" && arg != "south"))
                return notify_fail("你要开什么？\n");

        if(!( room = find_object("/d/nanhai/frontgate")) )
                room = load_object("/d/nanhai/frontgate");
        if(objectp(room))
        {
                set("exits/south", "/d/nanhai/frontgate");
                message_vision("$N使劲把大门打了开来。\n", this_player());
                room->set("exits/north", __FILE__);
                message("vision", "吱地一声，里面有人把大门打开了。\n", room);
                remove_call_out("close_gate");
                call_out("close_gate", 10);
        }

        return 1;
}

