#include <ansi.h>
inherit ITEM;
#define DEBUG 0
mapping sldher;

void create ()
{
    set_name("水陆大会发奖器", ({ "fajiang qi","qi"}) );
    set ("long", @LONG

这是一个供巫师使用的水陆大会发奖器。当水陆大会完成后，负责
发奖的巫师可以使用这个物品为参加水陆大会及获奖冠军发奖。

指令格式：
        sure 玩家的ID 冠军否的标志。
        举例:sure id first (表示给冠军id发奖)
             sure id      (表示给普通玩家发鼓励奖)

所用发奖标准为2000年新定标准。

LONG);
    set("unit","个");
    set("type", "misc");
    setup();
}

void init ()
{
   add_action("do_sure","sure");
}

void announcing (string str)
{
  if (DEBUG)
  {
    object smile = find_player ("smile");

    if (wizardp(smile))
      tell_object (smile," @** "+str);
  }
  else
  {
    object wei = load_object ("/d/kaifeng/npc/wei");
    wei->command_function("sldh "+str);
  }
}

void announce (string str)
{
  string s = str;
  int i, j;
  
  while ((i = strlen(s)) > 0)
  {
    j = strsrch (s, "\n");
    if (j < 0)
    {
      announcing (s);
      return;
    }  
    announcing (s[0..j]);
    s = s[j+1..i];
  }
}

int do_sure(string arg)
{
  object who=this_player();
  object ob=this_object();
  object sldher;
 object gold,guo;
  string id,firsts="";
 int i=0,dx=0,first=0;
   
    if(!wizardp(who)) {
         tell_object(who,"你没有权限获得这个物体，没有权限使用这个命令。\n");
         tell_room(environment(who),ob->name()+"毁灭了。\n");
         destruct(ob);
          return 1;
        }

    if(!arg) 
         return notify_fail("你要设置谁得奖？\n");
    if(!sscanf(arg,"%s %s",id,firsts)) 
      if(!sscanf(arg,"%s",id))
         return notify_fail("你给的参数好象有点问题。\n");
    if(firsts=="first") first=1;
    sldher=find_player(id);
    if(!sldher)
         return notify_fail("这位玩家还没进入这个世界呢。\n");
    if(!environment(sldher))
         return notify_fail("这位玩家还没进入这个世界呢。\n");
   
  if(ob->query(id))
   {
    tell_object(who,sldher->name()+"已经拿过奖励了，可不能发第二次。\n");
    return 1;
   }
  else {
     dx=sldher->query("combat_exp");
    if(dx<1000) {
        tell_object(who,sldher->name()+"的道行不满一年，没有资格获得奖励。\n");
        return 1;}
    if(dx>0&&dx<=10000) i=0;
    if(dx>10000&&dx<=50000) i=1;
    if(dx>50000&&dx<=150000) i=2;
    if(dx>150000&&dx<=300000) i=3;
    if(dx>300000&&dx<=500000) i=5;
    if(dx>500000&&dx<=1000000) i=10;
    if(dx>1000000&&dx<=2000000) i=15;
    if(dx>2000000&&dx<=3000000) i=25;
    if(dx>3000000&&dx<=5000000) i=40;
    if(dx>5000000) i=50;
       ob->set(sldher->query("id"),1);
       tell_object(sldher,HIG"你现在获得本届水陆大会奖励如下：\n"NOR);
    tell_object(sldher,  "      "+chinese_number(1000*i)+"点潜能！\n");
    sldher->add("potential",500*i);
    sldher->add("sldh/qn",500*i);
    sldher->add("sldh/enter",1);
    if(first) {
       sldher->add("sldh/first",1);
    if(dx<=300000) {
     tell_object(sldher,"      三百两黄金。\n");
        gold=new("/u/pkl/300gold");
        gold->move(sldher);
       }
    if(dx>300000&&dx<=1000000) {
       tell_object(sldher,"      一个金潜能丹。\n");
        guo=new("/d/obj/drug/qnd");
        guo->move(sldher);
       }
    if(dx>1000000&&dx<=3000000) {
       tell_object(sldher,"      二个金潜能丹。\n");
       guo=new("/d/obj/drug/qnd");
       guo->move(sldher);
       guo=new("/d/obj/drug/qnd");
       guo->move(sldher);
       }
    if(dx>3000000&&dx<=5000000) {
       tell_object(sldher,"      三个潜能丹。\n");
       guo=new("/d/obj/drug/qnd");
       guo->move(sldher);
       guo=new("/d/obj/drug/qnd");
       guo->move(sldher);
       guo=new("/d/obj/drug/qnd");
       guo->move(sldher);
       }
    if(dx>5000000) {
       tell_object(sldher,"      四个潜能丹。\n");
       guo=new("/d/obj/drug/qnd");
       guo->move(sldher);
       guo=new("/d/obj/drug/qnd");
       guo->move(sldher);
       guo=new("/d/obj/drug/qnd");
       guo->move(sldher);
       guo=new("/d/obj/drug/qnd");
       guo->move(sldher);
      }
      }
           tell_object(who,first==1?"冠军":"普通玩家"+sldher->query("name")+"  获得奖励。\n");
           announce("本届水陆大会"+sldher->name()+"("+sldher->query("id")+")"+"  获得奖励。");
       }
    return 1;
       }


