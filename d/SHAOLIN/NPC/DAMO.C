#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
       set_name(HIC"��Ħ��ʦ"NOR, ({"master damo","damo", "master"}));
       set("long", "����һλ�����������������ɮ������һϮ���ݽ�˿������ġ�
�����������ɿ�ɽ���桢�������ֵ�������ɮ��Ħ��ʦ�� \n");
       set("title",HIW"���ֿ�ɽ��ʦ"NOR);
       set("gender", "����");
       set("age", 80);
   set("class", "taoist");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "��ʦ��");
       set("per", 26);
   set("looking", "�����⣬Ŀ�̴�Ц���������飬һ�ɵõ���ɮ���ơ�");
   set("int", 30);
       set("max_kee", 6000);
       set("max_sen", 6000);
       set("sen", 6000);
       set("kee", 6000);
       set("max_mana", 5000);
       set("max_force", 5000);
       set("force", 5000);
       set("mana", 5000);
       set("daoxing", 8500000);
       set("combat_exp", 6500000);
       set("max_gin", 1000);
       set("force_factor", 220);
       set("mana_factor", 100);
       set_skill("unarmed", 400);
       set_skill("dodge", 400);
       set_skill("parry", 400);
     set_skill("sword",400);
      set_skill("stick", 400);
   set_skill("spells", 400);
   set_skill("chanzong", 400);
   set_skill("banruo-zhang", 400);
   set_skill("jingang-leg", 400);
   set_skill("yijinjing", 400);
   set_skill("force", 400);
   set_skill("zui-gun", 400);
   set_skill("shaolin-sword", 400);
   set_skill("shaolin-shenfa", 400);
   map_skill("spells", "chanzong");
   map_skill("unarmed", "banruo-zhang");
   map_skill("force", "yijinjing");
   map_skill("stick", "zui-gun");
   map_skill("parry", "jingang-leg");
   map_skill("dodge", "shaolin-shenfa");
   map_skill("sword", "shaolin-sword");
   create_family("������", 1, "��ʦ");
setup();

        carry_object("/d/lingtai/obj/pao")->wear();
        carry_object("/d/lingtai/obj/shoe")->wear();
        carry_object("/d/shaolin/obj/damobang")->wield();
}

void attempt_apprentice(object ob)
{   ob=this_player();
   if( (string)ob->query("family/family_name")=="������") {
   if ((int)ob->query("daoxing") < 1500000 ) {
     command("say ��������֮����ע�ص��У�" + RANK_D->query_respect(ob) + "������Ŭ�������޳�������\n");
   return;
   }
   if ((int)ob->query_int() < 25) {
   command("say ���¶���һ��Ե�֡�");
   command("say " + RANK_D->query_respect(ob) + "�����Ե��������ذɡ�");
   command("sigh");
   return;
   }
   if( (int)ob->query_skill("yijinjing", 1) < 280 ) {
   command("say ��λ" + RANK_D->query_respect(ob) + "���ҷ����׽����ỹ����������ھ�������Ҳ̫���˵�� !\n");
   command("sigh");
   return;
   }
        command("smile");
        command("say �ܺã�" + RANK_D->query_respect(ob) + "��ϲ������Ϊ�����¶��ֱ����� !�����ֵ�һ����֮�ţ����Ǵ��ϻ� !");
        command("recruit " + ob->query("id") );
        message("system", HIY"�������ֶ���һλ����  "+this_player()->name()+HIW"
                �����µ�������ǿ�ˡ�\n"NOR,users());
        
   return;
   }
        command("shake");
        command("say ��֪�˻��Ӻ�̸��" + RANK_D->query_respect(ob) + "�뱾������������������ذɡ�\n");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "bonze");
                ob->set("title", HIG"��Ħ��ʦ���ڵ���"NOR); 
}

int accept_fight(object me, object ob)
{   ob=this_player();
   command("say " + RANK_D->query_rude(ob) + "ɱ��̫�أ��ֻ������ѣ�\n");
   return 0;
}
void die()
{

        if( environment() ) {
        message("sound", "\n\n��Ħ��ʦ˫Ŀ΢�գ�˵������������,���سɷ���������������\n\n",
 environment());
        command("sigh");
        message("sound", "\n��Ħ��ʦ������ȥ����ΧһƬ��⡣����\n\n", environment());
        }

        destruct(this_object());
}
