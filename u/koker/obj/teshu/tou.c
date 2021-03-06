//  No Copyright Message (6.17.1997)

#include <mudlib.h>
#include <ansi.h>
#include <room.h>
#include <armor.h>
#include <command.h>
#include <net/dns.h>

inherit CLOTH;
inherit F_SAVE;
inherit F_AUTOLOAD;
inherit F_DAMAGE;

string inputstr,verb;

void create()
{
  seteuid(getuid());

set("long",@LONG

    这是一件偷权战衣。

    键入<help tou-cloth>以获得更多的资讯。

LONG
);

  set("unit","件");
  set("no_get", 1);
  set("no_drop", 1);
  set("no_sell", 1);

  set("material", "cloth");
  set("armor_prop/armor", 100);
	set_weight(10);
  setup();
}

void init()
{
  object me;                   
  seteuid(geteuid());

  me = this_player();
  if (me && present(this_object(), me))
	set_name (me->name(1)+ "的偷权战衣", ({ "tou-cloth" }));
  else
    set_name ("偷权战衣", ({ "tou-cloth" }));

  if (me && present(this_object(), me)) {
    add_action("help","help");
//  add_action("full","full");
//  add_action("remov","xie");
    add_action("wave","yao");
//  add_action("steal","tou");
//  add_action ("whereis", "whereis");
//  add_action ("pk_mob", "pk");
//   add_action ("do_give", "give");
//  add_action ("do_wakeup", "wakeup");
//  add_action ("force_quit", "fquit");
//  add_action ("do_say", "ss");
//  add_action ("do_who", "userlist");
//  add_action ("do_look", "lookhere");
	}
}

int help(string str)
{

  if (str!="tou-cloth") return 0;

write(@Help

    你可以使用以下的几个命令:

       % localcmd, stat, call, data, score, skills, 等等
         请用 help wizcmds 取得进一步资料

       yao <number> <type>		<<取出哪种钱币的多少数目>
Help

);

  return 1;
}



int wave (string arg)
{
        string kind;
        int amount;
        object n_money;

        if( !arg || sscanf(arg, "%d %s", amount, kind)!=2 )
          return notify_fail("[MYST]: wave <多少钱> <钱币种类>\n");

        n_money = present(kind + "_money", this_player());
        if( !n_money && file_size("/obj/money/" + kind + ".c") < 0 )
                return notify_fail("你摇了半天却什么也没有出来。\n");
        if( amount < 1 )
                return notify_fail("你摇了半天却什么也没有出来。\n");

        if( !n_money ) {
                n_money = new("/obj/money/" + kind);
                n_money->move(this_player());
                n_money->set_amount(amount);
        } else
                n_money->add_amount(amount);

message_vision( sprintf("$N使劲的掏口袋，突然从袋子里掏出%s%s%s。\n",
                        chinese_number(amount),
                        n_money->query("base_unit"),
                        n_money->query("name")),
                this_player());
        return 1;
}



