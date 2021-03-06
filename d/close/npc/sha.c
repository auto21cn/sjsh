//沙悟净
//by Calvin and Leox 共同开发
//版权所有,未经许可!不得翻录

inherit NPC;
#include <ansi.h>

void create()
{
          set_name(HIC"沙悟净"NOR, ({"sha wujing","sha","wujing","heshang"}));
        set("title", HIY"金身罗汉"NOR);
          set("long","他本是卷帘大将，因蟠桃会失手打破玻璃盏，被贬到下界。\n");
        set("class", "tianpeng");
        create_family("天蓬元帅府", 2, "弟子");
          set("gender", "男性");
          set("age", 50);
          set("per",30);        
          set("combat_exp", 1800000);
          set("daoxing",1800000);
          set("per", 30);
          set("str", 30);
          set("max_kee", 2000);
          set("kee",2000);
          set("force_factor",100);
          set("max_sen", 2000);
          set("sen",2000);
          set("force", 5000);
          set("max_force", 2500);
          set("max_mana", 2500);
          set("mana", 5000);
          set_skill("unarmed", 220);
          set_skill("dodge", 220);
          set_skill("force", 220);
          set_skill("parry", 220);
          set_skill("staff", 220);
          set_skill("spells", 220);
//          map_skill("spells", "buddhism");

         setup();
        carry_object("/d/qujing/liusha/obj/staff")->wield();
}

void attempt_apprentice(object ob)
{

        if( (string)ob->query("family/family_name")=="天蓬元帅府" ){
                if( (int)ob->query("family/generation") < 2  ){
                        command("say 哇,你逗我这个老和尚啊!我该拜" + RANK_D->query_respect(ob) + "您为师才是。\n");
                }
                else if( (int)ob->query("family/generation") ==2  ){
                        command("say 你这个" + RANK_D->query_rude(ob) + "别来消遣本山人了！\n");
                }
                else if( (int)ob->query("family/generation") ==4  ){
                        command("blush ");
                        command("say 你这个" + RANK_D->query_rude(ob) + "，这是你自愿的,到时别赖我头上...\n");
                        command("recruit " + ob->query("id") );
                }
                else {
                        if( (int)ob->query("daoxing")+(int)ob->query("combat_exp") >= 800000 ){
                                command(":) ");
                                command("say 好，" + RANK_D->query_respect(ob) + "既然到我门下就得给我争气，可不许偷懒！\n");
                                command("recruit " + ob->query("id") );
                        }
                        else {
                                command("say 你还是先找其他弟子练着吧。\n");
                        }
                }
        }

        else{
                command("hmm");
                command("say 这位" + RANK_D->query_respect(ob) + "，你还是找其他弟子先练练吧。\n");
        }

        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "tianpeng");
}
