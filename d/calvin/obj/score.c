//Calvin.2001.5

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(""HIY"������Ե���а�"NOR"", ({"score"}));
        set("long", "������Ե�ĸ���������������read������\n");
     set("no_get", "���ò���������������\n");
}

void init()
{
  add_action("do_read","read");
//  add_action("do_list","list");
}

//int do_list(string arg)
//{
//string type;
//  type="/adm/daemons/toptend"->query_type();
//  write(type);
//  return 1;
//}

int do_read(string type)
{
 write("/adm/daemons/toptend"->topten_query(type));
return 1;

}