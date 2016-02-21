/* <������V2.0�汾ר�ñ�ʯϵͳ> */
//�߼���ʯ by koker 2001

#include <ansi.h>
inherit ITEM;

string *names = ({
  ""BLINK""YEL"����"NOR"",
  ""BLINK""GRN"���"NOR"",
  ""BLINK""MAG"��ˮ��"NOR"",
  ""BLINK""HIW"��ʯ"NOR"",
  ""BLINK""RED"�챦ʯ"NOR"",
  ""BLINK""BLU"����ʯ"NOR"",
  ""BLINK""GRN"�̱�ʯ"NOR"",
});

string *ids = ({
    "topaz",
    "emerald",
    "amethyst",
    "diamonds",
    "ruby",
    "sapphire",
    "lv baoshi",
});

void create()
{
        int i = random(sizeof(names));
        set_name(names[i], ({ids[i],"baoshi"}));
	set_weight(500);
	if( clonep() )
    		set_default_object(__FILE__);
  	else {
	      //set("no_sell",1);
		set("unit","��");
                set("color","g");  //��
                set("value", 40000);
		set("long",HIG"һ����������ı�ʯ����˵�����ϱ������������������\n"NOR);
	}
	setup();
}

void init()
{
    
    add_action("do_enchase", "enchase");
    add_action("do_enchase", "inset");
}

int do_enchase(string arg)
{
   object in_obj;
   string item;
   string mats;
   string weapon_type;
   int rd,inset_num ;
   object me = this_player();
   object ob = this_object();
   
   if(!arg) return notify_fail("��Ҫ��ʲô��\n");
   if(sscanf(arg, "%s", item)!=1) return notify_fail("��Ҫ�ѱ�ʯ��Ƕ��ʲô�ϣ�\n");
   if(!objectp(in_obj = present(item, me))) return notify_fail("������û������������\n");
   if( in_obj->query("equipped") )
      return notify_fail("����������������������Ƕ��ʯ��\n");
   if( in_obj->query("no_zm")||in_obj->query_unique())
      return notify_fail("���װ��������Ƕ��ʯ��\n");

  
   mats = in_obj->query("material");       //װ��������
   inset_num = in_obj->query("inset_num");  // Ƕ�˼�����
   if(!inset_num) inset_num = 1;
   else inset_num = inset_num + 1;
   if(inset_num > 5) return notify_fail(in_obj->query("name")+"���Ѿ���Ƕ��̫��ı�ʯ��!\n");
   
   if(!in_obj->query("weapon_prop/damage"))   //����
  {
       message_vision(CYN"$N��$n"+CYN"��Ƕ��"+in_obj->query("name")+CYN"�� \n"NOR,me,ob);
       tell_room(environment(me),HIG"ֻ��"+ob->name()+HIG"����һ��ҫ�۵Ľ��,������"+in_obj->query("name")+HIG"����Χ \n"NOR);
       in_obj->add("armor_prop/spells",1 + random(10));
       message_vision(CYN""+in_obj->query("name")+CYN"�ƺ���ø��ӳ��������ˣ�\n"NOR,me);
     //me->add("bellicosity",1000);  
    
       in_obj->set_weight(in_obj->query_weight()+1000);
     //in_obj->set("no_sell",1);       
       in_obj->set("inset_num",inset_num);
       in_obj->add("inset_g",inset_num);  //װ��g
       in_obj->set("name",HIG+in_obj->query("name")+NOR);
       if(!in_obj->query("old_long")) in_obj->set("old_long",in_obj->query("long"));
       in_obj->set("long",in_obj->query("old_long")+"����Ƕ����"HIW+chinese_number(inset_num)+"�ű�ʯ\n"NOR);
       in_obj->save();
       destruct(ob);
       return 1;
}else{  //����
       message_vision(CYN"$N��$n"+CYN"��Ƕ��"+in_obj->query("name")+CYN"�� \n"NOR,me,ob);
       tell_room(environment(me),HIG"ֻ��"+ob->name()+HIG"����һ��ҫ�۵Ľ���,������"+in_obj->query("name")+HIG"����Χ \n"NOR);
       
       message_vision(CYN""+in_obj->query("name")+CYN"�ƺ���ø��ӷ����ˣ�\n"NOR,me);
       weapon_type = in_obj->query("skill_type");
       in_obj->add("weapon_prop/damage",10+random(20));
       in_obj->add("weapon_prop/strength",15+random(10));
       in_obj->add("rigidity",1+random(20));       
     
       in_obj->set_weight(in_obj->query_weight()+1000);
     //in_obj->set("no_sell",1);       
       in_obj->set("inset_num",inset_num);
       in_obj->add("inset_g",inset_num);  //װ��g
       in_obj->set("name",HIG+in_obj->query("name")+NOR);
       if(!in_obj->query("old_long")) in_obj->set("old_long",in_obj->query("long"));
       in_obj->set("long",in_obj->query("old_long")+"����Ƕ����"HIW+chinese_number(inset_num)+"�ű�ʯ\n"NOR);
       in_obj->save();
       destruct(ob);
       return 1;
}


 
  return notify_fail("����Ƕ��ʯʧ���ˣ�\n");
}