// dan.c ������

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIY"��Ԫ������"NOR, ({ "dan" }) );
        set("long",
HIY"��ׯ�������ϳ˵��鵤��ҩ��\n"NOR);
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
        ob->set_skill("force",50);
        ob->set_skill("spells",50);
        ob->set_skill("sword",50);
        ob->set_skill("parry",50);
        ob->set_skill("dodge",50);
        ob->set_skill("blade",50);
        ob->set_skill("staff",50);
        ob->set_skill("unarmed",50);
        ob->set_skill("literate",50);
        ob->set_skill("baguazhen",50);
        ob->set_skill("fumo-zhang",50);
        ob->set_skill("hammer",50);
        ob->set_skill("kaishan-chui",50);
        ob->set_skill("sanqing-jian",50);
        ob->set_skill("taiyi",50);
        ob->set_skill("wuxing-quan",50);
        ob->set_skill("yange-blade",50);
        ob->set_skill("zhenyuan-force",50);
write(HIY+"����һ����Ԫ��������ֻ����һ�����������������!��ʱ�����ׯ�۵��书��������\n"NOR);

        message("vision", HIY + ob->name() + 
"����һ����Ԫ��������ֻ����һ������������������!��ʱ������ׯ�۵��书��������\n"NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}