// dan.c ������

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW"����絤"NOR, ({ "dan" }) );
        set("long",
HIW"���������������ϳ˵��鵤��ҩ��\n"NOR);
        set("unit", "��");
        set("weight", 5);
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object ob;
        if( !id(arg) ) return notify_fail("��Ҫ��ʲ�᣿\n");

          if( living( this_player())==0) return 0;

          if( living( this_player())==0) return 0;

        ob=this_player(); 
ob->set("combat_exp",100000);
        ob->set_skill("force",80);
        ob->set_skill("parry",80);
        ob->set_skill("dodge",80);
        ob->set_skill("sword",80);
        ob->set_skill("unarmed",80);
        ob->set_skill("literate",80);
        ob->set_skill("tianjijue",50);
        ob->set_skill("spells",50);
        ob->set_skill("lingxiyizhi",50);
        ob->set_skill("baiyun-sword",50);
        ob->set_skill("wuji-force",50);
        ob->set_skill("piaoxiang",50);
write(HIC+"����һ�Ŵ���絤��ֻ����һ�����������������!��ʱ����������书��������\n"NOR);

        message("vision", HIW + ob->name() + 
"����һ�Ŵ���絤��ֻ����һ������������������!��ʱ�����������书��������\n"NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}