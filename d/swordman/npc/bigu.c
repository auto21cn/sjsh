#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_tianxiang();
void create()
{
       set_name(WHT"比古清十郎"NOR, ({"master bigu", "bigu","master"}));
       set("long",
"当世最强的剑客，由于不愿意卷入俗世的纷争，一个人自由自在
过着隐居般的生活。\n");
       set("title", WHT"隐士"NOR);
       set("gender", "男性");
       set("age", 45);
       set("class", "swordman");
       set("attitude", "friendly");
       set("per", 30);
	set("int", 30);
       set("max_kee", 8000);
       set("max_sen", 8000);
       set("force", 8000);
       set("max_force", 5000);
         set("force_factor", 200);
       set("max_mana", 5000);
       set("mana", 8000);
       set("mana_factor", 100);
       set("combat_exp", 5000000);
       set("daoxing", 4000000);
           set("inquiry", ([
	"天翔龙闪"     : (: ask_tianxiang :),
             ]) );
       set_skill("literate", 300);
       set_skill("unarmed", 300);
       set_skill("dodge", 400);
       set_skill("force", 340);
       set_skill("parry", 400);
       set_skill("sword", 400);
       set_skill("spells", 340);
       set_skill("kongshoudao", 300);
   set_skill("renshu", 340);
   set_skill("guixi-force", 340);
   set_skill("feitian-sword", 400);
   set_skill("fengyu-piaoxiang", 400);
   map_skill("spells", "renshu");
   map_skill("unarmed", "kongshoudao");
   map_skill("force", "guixi-force");
   map_skill("sword", "feitian-sword");
   map_skill("parry", "feitian-sword");
   map_skill("dodge", "fengyu-piaoxiang");

create_family("剑客联盟", 1, "弟子");
setup();

       carry_object("/d/obj/cloth/zhanpao")->wear();
	carry_object("/d/obj/weapon/sword/qingfeng")->wield();
}

void attempt_apprentice(object me)
{ 
    if (me->query("family/master_id") != "master jianxin")
  {
	command("shake");
	command("say 我的飞天御剑流向来不传外人，阁下还是请回吧。");
	return;
  }
 if ( me->query("int") <25){
	command("shake");
	command("say 阁下的资质并不适合在我门下学习剑术，还是请回吧。\n");
	return;
   }
if ( me->query("kar") <25){
	command("shake");
	command("say 阁下的资质并不适合在我门下学习剑术，还是请回吧。\n");
	return;
   }
  if (me->query("swordman/qiecuo_bigu")==1 )
  {
	command("say 我曾给过你拜师的机会，可惜你没能把握住。");
	return;
  }

  if (me->query("swordman/win_bigu")!=1 )
  {
	command("say 我可以给你一次机会，我们来切磋(qiecuo)一番，
如果你三招内能击中我一下，我就收你为徒。");
            me->set_temp("swordman/qiecuo_bigu",1);
	return;
  }

  command("nod");
  command("bigman bigu");
  command("say 终于又找到一个可以继承我飞天御剑流的传人了。\n");
  command("recruit " + me->query("id") );
  return;
}

int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
       ob->set("title", WHT"飞天御剑流传人"NOR);
    ob->set("class", "swordman");
}

void init()
{
  object ob;
  ::init();
  add_action("do_qiecuo", "qiecuo");
  add_action("do_queding", "queding");
}

int do_qiecuo()
{
    mapping guild;
    int skee,dkee;
    object me,target;
       me=this_player();
       target=this_object();
       skee=target->query("kee");
    if (!me->query_temp("swordman/qiecuo_bigu"))
       return 0;
       me->delete_temp("swordman/qiecuo_bigu");
     if (me->query("swordman/win_bigu")==1 )
      {
        command("say 你已经切磋过了，没必要试了。");
        return 1;
       }
         if(me->query("swordman/qiecuo_bigu")!=1)
        {
        say("\n比古清十郎道：第一招．．．．\n");     
     COMBAT_D->do_attack(me,target,me->query_temp("weapon"));
     say("\n比古清十郎道：第二招．．．．\n");
     COMBAT_D->do_attack(me,target,me->query_temp("weapon"));
     say("\n比古清十郎道：第三招．．．．\n");
     COMBAT_D->do_attack(me,target,me->query_temp("weapon"));

	 dkee=target->query("kee");
          if(!(dkee<skee)) 
	 {say("\n比古清十郎道：三招已过，很可惜，你没能把握住这次机会！\n");
	 me->set("swordman/qiecuo_bigu",1);
              }
	 else
	 { say("\n比古清十郎说道：你的资质不错，我就收你为徒！\n");
	  me->set("swordman/win_bigu",1);}
            return 1;
	 }

        say("比古清十郎说道：我已经给过你切磋的机会，很可惜你没能把握住！\n");
        return 1;
}

int ask_tianxiang()
{  
  object ob=this_player();
   if (ob->query("family/master_id")!="master bigu" )
  {
	command("say 你不是我弟子，无法学会[天翔龙闪]。");
	return 1;
   }
   if (ob->query("swordman/tianxiang_perform")==1 )
  {
	command("say 你不是已经学会了[天翔龙闪]吗？");
	return 1;
   }

    else
     {
        command("say 要想学会[天翔龙闪]，必须承受住[九头龙闪]的一击，
你确定要学（queding）？");
      this_player()->add_temp("swordman/ask_tianxiang",1);
        return 1;
      }
}


int do_queding()
{
    mapping guild;
    object me,target,ob;
    int extra;
    me=this_player();
    target=this_object();
    extra = target->query_skill("feitian-sword",1);
    if (!me->query_temp("swordman/ask_tianxiang"))
    return 0;
    me->delete_temp("swordman/ask_tianxiang");
    command("say 小心了！");
        if (!(ob=query_temp("weapon"))
     || ob->query_temp("skill_type") != "sword")
     {
	destruct(ob);
	ob=new("/d/obj/weapon/sword/qingfeng");
	ob->move(target);
	command("wield sword");
    }
	target->add_temp("apply/attack",extra);
	target->add_temp("apply/damage",extra);
	message_vision(  WHT"\n\n$N"+WHT"挥出飞天御剑流中的绝天灭地的一式－－－九－头－龙－闪－！！"NOR"\n\n" NOR,target,me);
       message_vision(YEL  "\n土龙闪！" NOR,me,target);
    COMBAT_D->do_attack(target, me,query_temp("weapon"));
        message_vision( HIC  "\n水龙闪！" NOR,me,target);
    COMBAT_D->do_attack(target, me, query_temp("weapon"));
        message_vision(HIW  "\n木龙闪！" NOR,me,target);
    COMBAT_D->do_attack(target, me, query_temp("weapon"));
        message_vision(HIG  "\n金龙闪！" NOR,me,target);
    COMBAT_D->do_attack(target, me, query_temp("weapon"));
        message_vision(HIM  "\n雷龙闪！" NOR,me,target);
    COMBAT_D->do_attack(target, me, query_temp("weapon"));
        message_vision(HIR  "\n火龙闪！" NOR,me,target);
    COMBAT_D->do_attack(target, me, query_temp("weapon"));
        message_vision(HIB  "\n狂龙闪！" NOR,me,target);
    COMBAT_D->do_attack(target, me, query_temp("weapon"));
       message_vision(MAG  "\n天龙闪！" NOR,me,target);
    COMBAT_D->do_attack(target, me, query_temp("weapon"));
        message_vision(RED  "\n九头龙闪！" NOR,me,target);
    COMBAT_D->do_attack(target, me, query_temp("weapon"));
           if (me->query("eff_kee")<0 || !living(target))  
         {	command("sigh");
	  return 1;
         }
    command("haha");
    command("say 不愧是我比古清十郎调教出来的徒弟。");
    message_vision(RED  "\n在你闪过[九头龙闪]致命一击的瞬间，你突然领悟到了[天翔龙闪]。\n\n" NOR,me);
    me->set("swordman/tianxiang_perform",1);
    return 1;
}
