// 干将 by Calvin

#include <ansi.h>
inherit NPC;
string get_ice(object me);
void do_drop(object ob);

void create()
{
        set_name(HIC"干将"NOR, ({"gan jiang", "gan","jiang", "tianshen"}));
        set("title", HIW"傲野双雄"NOR);
        set("gender", "男性" );
        set("age", 3000);
        set("per", 30);
set("long", @LONG
这位干将便是传说中的神剑的原身。
LONG );

        set("class", "yaomo");
        set("combat_exp", 1000000);
        set("daoxing", 1000000);
        set("attitude", "peaceful");
        create_family("大雪山", 1, "祖师");
        set_skill("unarmed", 350);
        set_skill("cuixin-zhang", 350);
        set_skill("dodge", 350);
        set_skill("xiaoyaoyou", 350);
        set_skill("parry", 350);
       set_skill("throwing", 350);
        set_skill("sword", 350);
       set_skill("bainiao-jian", 350);
        set_skill("force", 350);   
        set_skill("ningxie-force", 350);
        set_skill("literate", 350);
        set_skill("spells", 350);
        set_skill("dengxian-dafa", 350);
        map_skill("spells", "dengxian-dafa");
        map_skill("force", "ningxie-force");
        map_skill("unarmed", "cuixin-zhang");
        map_skill("sword", "bainiao-jian");
        map_skill("dodge", "xiaoyaoyou");

        set("max_kee", 5000);
        set("max_sen", 5000);
        set("force", 2400);
        set("max_force", 2400);
        set("mana", 2400);
        set("max_mana", 2400);  
        set("force_factor", 100);
        set("mana_factor", 100);
       set("chat_chance_combat", 50);
       set("chat_msg_combat", ({
            (: perform_action, "sword", "chaofeng" :),
                (: cast_spell, "juanbi" :),
                (: cast_spell, "tuntian" :),
                (: exert_function, "recover" :),
             }) );
            setup();
      carry_object("/d/zj/armor/jing1")->wear();
      carry_object("/d/zj/weapon/gangjiang")->wield();
}

void attempt_apprentice(object ob)
{
        if( (string)ob->query("family/family_name")=="大雪山" ){
                if( (int)ob->query("family/generation") < 1  ){
                        command("say 别拿我来开玩笑。我该拜" + RANK_D->query_respect(ob) + "您为师还差不多。\n");
                }
                else if( (int)ob->query("family/generation") ==1  ){
                        command("say 你这个" + RANK_D->query_rude(ob) + "别来消遣我了！\n");
                }
                else if( (int)ob->query("family/generation") ==2  ){
                        command("blush ");
                        command("say 你这个" + RANK_D->query_rude(ob) + "，真是没办法,好吧...\n");
                        command("recruit " + ob->query("id") );
                }
                else {
                        if( (int)ob->query("daoxing")+(int)ob->query("combat_exp") >= 1000000 ){
                                command(":) ");
                                command("say 好，" + RANK_D->query_respect(ob) + "既然到我门下就得给我争气，可不许偷懒！\n");
                                command("recruit " + ob->query("id") );
                        }
                        else {
                                command("say 这么差的鸟人还来找我?死远点去。\n");
                        }
                }
        }

        else{
                command("hmm");
                command("say 这位" + RANK_D->query_respect(ob) + "，你还是先找其他师傅们先练练吧。\n");
        }
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "yaomo");
}

int accept_object(object me, object ob)
{
object sword;
sword=new("/d/zj/weapon/rysj.c");
if((string)ob->query("id")=="moxie sword" )
{
message_vision(HIR"你既然能把莫邪剑得到交给我,那么我就把我这把干将剑和她合并,并给$N作为仰慕之礼吧!\n"+HIC"说着干将头顶冒出了一缕青烟,没一会儿干将便拿出了一把闪着奇辉的日月神剑给了$N!\n\n",me);
sword->move(me);
return 1;
}
else
{
command("say 不敢当不敢当．．．您太客气了。");
 return 1;
}
}
