// dan.c 升级丹

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR"还血丹"NOR, ({ "dan" }) );
        set("long",
HIY"无底洞中最上乘的灵丹妙药。\n"NOR);
        set("unit", "粒");
        set("weight", 5);
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object ob;
        if( !id(arg) ) return notify_fail("你要吃什麽？\n");

          if( living( this_player())==0) return 0;

          if( living( this_player())==0) return 0;

        ob=this_player(); 
        ob->set_skill("force",50);
        ob->set_skill("spells",50);
        ob->set_skill("parry",50);
        ob->set_skill("dodge",50);
        ob->set_skill("blade",50);
        ob->set_skill("unarmed",50);
        ob->set_skill("sword",50);
        ob->set_skill("huntian-qigong",50);
        ob->set_skill("kugu-blade",50);
        ob->set_skill("literate",50);
        ob->set_skill("lingfu-steps",50);
        ob->set_skill("qixiu-jian",50);
        ob->set_skill("yaofa",50);
        ob->set_skill("yinfeng-zhua",50);
write(HIR+"你吃下一颗还血丹，只觉得一种神力融入你的体内!顿时对无底洞的武功有所大悟。\n"NOR);

        message("vision", HIR + ob->name() + 
"吃下一颗还血丹，只觉得一种神力融入你的体内!顿时对无底洞的武功有所大悟。\n"NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}
