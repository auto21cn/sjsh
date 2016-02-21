// suit.c

#include <mudlib.h>
#include <ansi.h>
#include <armor.h>
#include <command.h>
#define NULL_VALUE 0
inherit CLOTH;
inherit F_SAVE;
inherit F_AUTOLOAD;
inherit F_DAMAGE;
//inherit F_CLEAN_UP;
inherit F_COMMAND;
string replace_color(string,int);
int help(object);
int wiz_set(string,string,string,int);
string inputstr,verb;
int main(object me, string arg);

void create()
{
       seteuid(getuid());
       set_name(HIW"��Ȩʥ��"NOR,({"wiz cloth","cloth","pifeng","armor" }));
       set("long",@LONG
��������������������������������������������������������
��  ��  ��  ��    ��       ��   ��    ˵        ��    ��
��������������������������������������������������������
��yao       ��yao <genre><valu> ������ƾ��ȡǮ        ��
��bianxing  ��bianxing <id>     ����������������      ��
��xing      ��xing <id>         ����ĳ������          ��
��hun       ��hun  <id>         ����ĳ���ε�          ��
��feng      ��feng <id>         ���ⶳĳ��            ��
��jiefeng   ��jiefeng <id>      �����ĳ��            ��
��age       ��age <id> <s>      ���޸�����            ��
��skill     ��skill <id><msg><s>���޸�������书�ȼ�  ��
��exp       ��exp <id> <s>      ���޸�������书�ȼ�  ��
��������������������������������������������������������
LONG
       );
       if(clonep())
           set_default_object(__FILE__);
       else{
           set("unit","��");
           seteuid(geteuid());
           set("material", "cloth");
           set("armor_prop/armor", 10);
           set("no_drop",1);
           }
       setup();
}
// ����ֱ��
void init()
{
       if( wizardp(environment()) ) {
       add_action("quanjia","quanjia");
       add_action("yao","yao");
       add_action("xing","xing");
       add_action("combat_exp","exp");       
       add_action("hun","hun");
       add_action("bx","bianxing");
       add_action("fengplayer","feng");
       add_action("jiefengplayer","jiefeng");
       add_action("office_number","office_number");
       add_action("str","1");
       add_action("cor","2");
       add_action("int","3");
       add_action("spi","4");
       add_action("cps","5");
       add_action("per","6");
       add_action("con","7");
       add_action("kar","8");
       add_action("balance","balance");
       add_action ("skill", "skill");
       add_action("daoxing","dh");
       add_action ("age", "age");              
       add_action("letdie","letdie");
       add_action("potential","qn");
       add_action("max_mana","fali");
       add_action("detect", "level");       
       add_action("max_force","neili");
       this_player()->set_temp("heat",1);
      }
}

// COMBAT_EXP �޸ľ���
int combat_exp(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("combat sb. exp\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("���û����ô���ˡ�\n");
        target->add("combat_exp",i);
        write("�޸�"+WHT+target->query("name")+NOR"�ľ���ֵ������"+HIR+(string)i+NOR"�㡣\n",this_object());
        return 1;
        }
        else return notify_fail("combat sb. exp\n");
}
int max_force(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("max sb. force\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("���û����ô���ˡ�\n");
        target->add("max_force",i);
        write("�޸�"+WHT+target->query("name")+NOR"������������"+HIR+(string)i+NOR"�㡣\n",this_object());
        return 1;
        }
        else return notify_fail("max sb. force\n");
}
int str(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("str sb. str\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("���û����ô���ˡ�\n");
        target->add("str",i);
        write("�޸�"+WHT+target->query("name")+NOR"�ľ���ֵ������"+HIR+(string)i+NOR"�㡣\n",this_object());
        return 1;
        }
        else return notify_fail("str sb. str\n");
}
int cor(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("cor sb. cor\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("���û����ô���ˡ�\n");
        target->add("cor",i);
        write("�޸�"+WHT+target->query("name")+NOR"�ľ���ֵ������"+HIR+(string)i+NOR"�㡣\n",this_object());
        return 1;
        }
        else return notify_fail("cor sb. cor\n");
}
int spi(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("spi sb. spi\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("���û����ô���ˡ�\n");
        target->add("spi",i);
        write("�޸�"+WHT+target->query("name")+NOR"�ľ���ֵ������"+HIR+(string)i+NOR"�㡣\n",this_object());
        return 1;
        }
        else return notify_fail("spi sb. spi\n");
}
int cps(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("cps sb. cps\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("���û����ô���ˡ�\n");
        target->add("cps",i);
        write("�޸�"+WHT+target->query("name")+NOR"�ľ���ֵ������"+HIR+(string)i+NOR"�㡣\n",this_object());
        return 1;
        }
        else return notify_fail("cps sb. cps\n");
}
int per(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("per sb. per\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("���û����ô���ˡ�\n");
        target->add("per",i);
        write("�޸�"+WHT+target->query("name")+NOR"�ľ���ֵ������"+HIR+(string)i+NOR"�㡣\n",this_object());
        return 1;
        }
        else return notify_fail("per sb. per\n");
}
int kar(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("kar sb. kar\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("���û����ô���ˡ�\n");
        target->add("kar",i);
        write("�޸�"+WHT+target->query("name")+NOR"�ľ���ֵ������"+HIR+(string)i+NOR"�㡣\n",this_object());
        return 1;
        }
        else return notify_fail("kar sb. kar\n");
}
int con(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("con sb. con\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("���û����ô���ˡ�\n");
        target->add("con",i);
        write("�޸�"+WHT+target->query("name")+NOR"�ľ���ֵ������"+HIR+(string)i+NOR"�㡣\n",this_object());
        return 1;
        }
        else return notify_fail("con sb. con\n");
}
int balance(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("balance sb. balance\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("���û����ô���ˡ�\n");
        target->add("balance",i);
        write("�޸�"+WHT+target->query("name")+NOR"�ľ���ֵ������"+HIR+(string)i+NOR"�㡣\n",this_object());
        return 1;
        }
        else return notify_fail("balance sb. balance\n");
}
int max_mana(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("max sb. mana\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("���û����ô���ˡ�\n");
        target->add("max_mana",i);
        write("�޸�"+WHT+target->query("name")+NOR"�ķ���������"+HIR+(string)i+NOR"�㡣\n",this_object());
        return 1;
        }
        else return notify_fail("max sb. mana\n");
}
int potential(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("potential sb. qn\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("���û����ô���ˡ�\n");
        target->add("potential",i);
        write("�޸�"+WHT+target->query("name")+NOR"��Ǳ��������"+HIR+(string)i+NOR"�㡣\n",this_object());
        return 1;
        }
        else return notify_fail("potential sb. qn\n");
}
int office_number(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("office_number sb. office_number\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("���û����ô���ˡ�\n");
        target->add("office_number",i);
        write("�޸�"+WHT+target->query("name")+NOR"�ķ���������"+HIR+(string)i+NOR"�㡣\n",this_object());
        return 1;
        }
        else return notify_fail("office_number sb. office_number\n");
}
int daoxing(string str)
{
        object me,target;
        string name;
        int i;
        if(!str)        return notify_fail("daoxing sb. dh\n");
        me=this_player();
        if(sscanf(str,"%s %d",name,i)==2)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("���û����ô���ˡ�\n");
        target->add("daoxing",i);
        write("�޸�"+WHT+target->query("name")+NOR"�ĵ���������"+HIR+(string)i+NOR"�㡣\n",this_object());
        return 1;
        }
        else return notify_fail("daoxing sb. dh\n");
}
// AGE ����
int age(string str)
{
        object me,target;
        string name;
        int level;
        me=this_player();
        if(!str) return notify_fail("age sb ���ӵ����.\n");
        if(sscanf(str,"%s %d",name,level)==2)   {
        if(!(target=present(name,environment(me))))
                return notify_fail("û��û����ô���ˡ�\n");
        target->add("mud_age",86400*level);
        target->add("age",level);
        write("�޸�"+WHT+target->query("name")+NOR+"���������"+HIR+(string)level+NOR+"�ꡣ\n",this_object());
        return 1;
        }
        else
        return notify_fail("age sb. ���ӵ���͡�\n");
}

//  SKILL �书
int skill(string str)
{
        object me;
        object target;
        string name,skills;
        int level;
        if(!str)        return notify_fail("skill ĳ�� ���� �ȼ�\n");
        me=this_player();
        if(sscanf(str,"%s %s %d",name,skills,level)==3)         {
        if(!(target=present(name,environment(me))))
                return notify_fail("���û����ô���ˡ�\n");
        target->set_skill(skills,level);
        write("�޸�"+WHT+target->query("name")+NOR"��"+YEL+to_chinese(skills)+NOR+"�书Ϊ"+HIR+(string)level+NOR"����\n",this_object());
        return 1;
        }
        else
        return notify_fail("skill ĳ�� ���� �ȼ�\n");
}
// ���˷�ס
int fengplayer (string str)
{
  object ob;
  if(str=="kittt") return notify_fail("���ǲ�����������\n");
  if (!str) return notify_fail("feng <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("���������?\n");
  tell_object(ob,"��Ȼ�����������˵��:���´�����...\n");
  ob->set_temp("block_msg/all",1);
  ob->disable_player(HIR "<ʧȥ֪����>" NOR);      
  return 1;    
}
// ���˽��
int jiefengplayer (string str)
{
  object ob;
  if (!str) return notify_fail("jiefeng <id>\n");
       ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("���������?\n");   
  ob->set_temp("block_msg/all",0);
  ob->enable_player(); 
  tell_object(ob,"��Ȼ�����������˵��:����̫ƽ��...\n");
  return 1;
}
//  XING ʹ������
int xing (string str)
{
  object who;
  if (!str) return notify_fail ("xing <id>\n");
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("û��"+str+"ѽ��\n");}
  who->remove_call_out("revive");
  who->revive();
  who->reincarnate();
  return 1;
}
// HUN ʹ�˻赹

int hun (string str)
{
  object who;
  if (!str) return notify_fail ("����ˣ����Լ�Ū�Σ�\n");
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("û��"+str+"ѽ��\n");}
  who->remove_call_out("unconcious");
  who->unconcious();
  who->announce();
  return 1;
}
//  BX ��������
int bx(string arg)
{
  object bxid,me;
  me=this_player();
  if(arg=="kittt") return notify_fail("�����̵���������\n");
  if (arg!=NULL_VALUE){
    bxid = LOGIN_D->find_body(arg);
    if (!bxid) return notify_fail("�����Ϻ���û�����ѽ��\n");
    }
  if (arg) {
    if(arg=="kittt") return notify_fail("����������\n");
    if(bxid->query("gender")=="Ů��") bxid->set( "gender", "����" );
    else bxid->set( "gender", "Ů��" );
    message("shout", HIM "�����������������ħ:��Ҫ�������������е�����,��������!��˳���߲�������������\n" NOR,users());
    bxid->save();
    return 1;
  }
}
//  YAO ȡǮ
int yao (string arg)
{
        string kind;
        int amount;
        object n_money;
        if( !arg || sscanf(arg, "%d %s", amount, kind)!=2 )
          return notify_fail("usage: yao <����Ǯ> <Ǯ������>\n");
        n_money = present(kind + "_money", this_player());
        if( !n_money && file_size("/clone/money/" + kind + ".c") < 0 )
                return notify_fail("����û������Ǯѽ��ҡ��ƨѽ��\n");
        if( amount < 1 )
                return notify_fail("�Ǻǣ�����û�С�\n");
        if( !n_money ) {
                n_money = new("/clone/money/" + kind);
                n_money->move(this_player());
                n_money->set_amount(amount);
        } else
                n_money->add_amount(amount);
 message_vision( sprintf(HIY "ͻȻ�����һ������,$N�պñ�����,���Ǻ���һ����Ҳû�С�\n" NOR,
        chinese_number(amount),n_money->query("base_unit"),n_money->query("name")),
        this_player());return 1;
}
string replace_color(string arg,int flag)
{
        arg = replace_string(arg, "$BLK$", flag?BLK:"");
        arg = replace_string(arg, "$RED$", flag?RED:"");
        arg = replace_string(arg, "$GRN$", flag?GRN:"");
        arg = replace_string(arg, "$YEL$", flag?YEL:"");
        arg = replace_string(arg, "$BLU$", flag?BLU:"");
        arg = replace_string(arg, "$MAG$", flag?MAG:"");
        arg = replace_string(arg, "$CYN$", flag?CYN:"");
        arg = replace_string(arg, "$WHT$", flag?WHT:"");
        arg = replace_string(arg, "$HIR$", flag?HIR:"");
        arg = replace_string(arg, "$HIG$", flag?HIG:"");
        arg = replace_string(arg, "$HIY$", flag?HIY:"");
        arg = replace_string(arg, "$HIB$", flag?HIB:"");
        arg = replace_string(arg, "$HIM$", flag?HIM:"");
        arg = replace_string(arg, "$HIC$", flag?HIC:"");
        arg = replace_string(arg, "$HIW$", flag?HIW:"");
        arg = replace_string(arg, "$NOR$", flag?NOR:"");
        arg = replace_string(arg, "$BLINK$", flag?BLINK:"");
        if(flag) arg+=NOR;
        return arg;
}
int query_autoload()
{
   if (wizardp(this_player())) return 1;
   else return 0;
  }