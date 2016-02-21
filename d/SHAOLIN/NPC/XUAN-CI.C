//xuan-ci.c �����·���
//wirted by piao 2001-10-04
#include <ansi.h>

string ask_for_leave();
string ask_mieyao(object me);
string ask_cancel();

inherit NPC;
inherit F_MASTER;
void create()
{

        set_name("���ȴ�ʦ", ({
                "xuanci dashi",
                "xuanci",
		"dashi",
	}));
        set("gender", "����" );
        create_family("������", 2, "����");
        set("title",HIW"��ɽ�����·��ɴ�ʦ"NOR );
        set("age", 70);
set("long",
		"����һλ�����ü����ɮ������һϮ��˿������ġ�\n"
		"�������������ͣ���ȴ�����⣬Ŀ�̴�Ц���Ե��������㡣\n"
	);
	set("class", "bonze");
	set("attitude", "heroism");

        set("force", 3500);
        set("max_force", 3500);
        set("force_factor", 50);
        set("mana", 2500);
        set("max_mana", 3500);
        set("mana_factor", 20);
        set("combat_exp", 2500000);
        set("daoxing", 3000000);

        set_skill("banruo-zhang", 280);
        set_skill("jingang-leg", 280);
        set_skill("yijinjing", 300);
        set_skill("chanzong", 300);
        set_skill("literate", 300);
        set_skill("spells", 300);
        set_skill("unarmed", 280);
        set_skill("dodge", 280);
        set_skill("shaolin-shenfa", 280);
        set_skill("parry", 280);
        map_skill("unarmed", "banruo-zhang");
        map_skill("parry", "jingang-leg");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("force", "yijinjing");
        map_skill("spells", "chanzong");

        set("max_kee", 1300);
        set("inquiry", ([
    "����": (: ask_mieyao :),
		"��ɽ" : (: ask_for_leave :),
                "leave" : (: ask_for_leave :),
      "cancel": (: ask_cancel :),
      ]) );
	set("max_sen", 1300);
	setup();
        carry_object("/d/shaolin/obj/changjian")->wield();
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();


}
void attempt_apprentice(object ob)
{
	object me; 
	mapping ob_fam, my_fam;
	string name, new_name;

	me = this_object();
	my_fam  = me->query("family");
	name = ob->query("name");

        if( (string)ob->query("gender") != "����" )
	{
		command ("say �����ӷ�Ůʩ��ѽ��ƶɮ�ɲ��ҿ������Ц����");
		return;
        }

          if( (int)ob->query_skill("yijinjing",1) < 180)
        {
	command("say " + RANK_D->query_respect(ob) + "�����׽��Ϊ����������Խ����ʦ��");
                return;
        }

        if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������")
	{
		command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}

        if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "������") 
	{
		command("say " + RANK_D->query_respect(ob) + "���׼ҵ��ӣ�����������ѧ�ա�");
		return;
	}

	command("say �����ӷ����գ����գ�");
        command("recruit " + ob->query("id"));
        ob->set("title", HIY"��ɽ�������޺��ô����"NOR);
}
string ask_for_leave()
{
	object me=this_player();
	if (me->query("family/family_name") == "������" ) {
		command("say �����ִ����ɽ��ƶɮȴ�м��仰˵��");
		me->set_temp("betray", 1);
		return ("����ʦ��Ҫ��Ҫ��һ���ͷ������Ը��(agree)?\n");
       }
	return ("ƶɮ��֪��\n");
}

int do_agree(string arg)
{	if (this_player()->query("family/family_name") == "������" )
{
	if(this_player()->query_temp("betray")) {
		message_vision("$N���������Ը�⡣\n\n", this_player());
		this_player()->add("betray/shaolin", 1);
		this_player()->add("betray/count", 1);
		command("say �������������Ե�������ɽȥ�ɣ�\n");
		this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
		this_player()->set("daoxing", this_player()->query("daoxing")*80/100);
		this_player()->delete("family");
		this_player()->delete("class");
                this_player()->delete_skill("yijinjing");
                this_player()->set("title","��ͨ����");
		this_player()->set_temp("betray", 0);
		command("say �����粨���ƶ����Σ�����Ϊ֮������\n");
		this_player()->save();
		return 1;
	}
}
	else return notify_fail("ʲô��\n");
}

void init()
{
        add_action("do_kneel", "kneel");
        add_action("do_agree", "agree");
}

string ask_mieyao(object me)
{
    object who=this_player();
    if((string)who->query("family/family_name")=="������") {
      command("say ������ħ�����ҷ�������֮���֡�");
      return "/d/obj/mieyao"->query_yao(who);
    }
    return ("��������,�ι�����?\n");
}

int do_kneel()
{
    object who = this_player();
    if((string)who->query("family/family_name")!="������")
     return notify_fail(this_object()->query("name")+"˵�����ֲ������ֵ��ӣ����Ҹ�ʲô��\n");
    if("/d/obj/mieyao"->delete_mieyao(who)){
        command("say ��Ȼ��ˣ������˰ɣ�������û��������񣬵���Щ�ͷ���\n");
        who->add("faith",-5);
        message_vision("$N���ҳ϶��½��ˣ�\n",who);
     }
     return 1;
}
string ask_cancel()
{
    object me=this_player();
if((int)me->query_temp("m_mieyao"))
{
      me->add("daoxing",-2000);
      me->delete_temp("m_mieyao");
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
     return ("û�õĶ�����");
}
else
{
     return ("���������𣿣�");
}
}
