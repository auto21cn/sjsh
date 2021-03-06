inherit NPC;
inherit F_MASTER;
inherit SSERVER;

void create()
{
  set_name("唐僧", ({ "tang seng", "tangseng", "tang", "seng" }));
  set("gender", "男性");
  set("attitude", "peaceful");
  set("str", 10);
  set("per", 30);
  set("combat_exp", 10000);
  set("daoxing", 10000000);

  set("max_kee", 8000);
  set("max_sen", 8000);
   set("max_mana", 10000);
   set("mana", 10000);
  set("mana_factor", 300);
  set_skill("spells", 200);
  set_skill("fofa", 200);
  set_skill("literate",200);
  map_skill("spells", "fofa");
  set("chat_chance_combat", 80);
  set("chat_msg_combat", ({
     (: cast_spell, "onlyu" :),
                           }) );
    set("chat_chance",10);
    set("chat_msg",({
    "唐僧东张西望了一番，大叫到：打雷了下雨了，大家收衣服了！\n",
    "唐僧叹了口气：这样东西是宝物，不能乱扔，乱扔会污染环境的。\n",
    "唐僧对着你很耐心的劝道：你想要就说吗，你不说我怎么知道你想要呢？\n",
    "唐僧幽幽叹道：你总有一天会醒悟，来找我唱这首歌的。\n",
    "唐僧轻轻的哼着：Only-you- Can伴我取西经~~~\n",
    "唐僧一脸正气的说到：那些妖怪想吃我，只是一个构想，还没变成事实，等它们吃了我，你们才能报仇。\n",
    "唐僧面上毫无表情的说到：GO！——天竺。\n",
  }));

        create_family("天蓬元帅府", 1, "师傅");
  setup();
  //carry_object("/d/obj/drug/tangsengrou");
}

void attempt_apprentice(object ob)
{
    if( (int)ob->query_skill("fofa",1) > 99 ) {
        command("smile");
        command("say 你妈贵姓呀？\n");
     if (random(2)) ob->recieve_wound("sen",random(100));
        command("say 人是人他妈生的。\n");
     if (random(2)) ob->recieve_wound("sen",random(100));
     command("say 妖是妖他妈生的\n");
     if (random(2)) ob->recieve_wound("sen",random(100));
     command("say 其实只要有一颗做人的心\n");
     if (random(2)) ob->recieve_wound("sen",random(100));
     command("say 那你就可以不做妖\n");
     if (random(2)) ob->recieve_wound("sen",random(100));
     command("say 那就是人妖\n");
     if (random(2)) ob->recieve_wound("sen",random(100));
     command("say 我其它几个徒弟都听明白了\n");
     if (random(2)) ob->recieve_wound("sen",random(100));
     command("say 你听明白了吗？\n");
     if (random(2)) ob->recieve_wound("sen",random(100));
     command("recruit " + ob->query("id") );
        return;
            }
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "tianpeng");
                ob->set("title", "西天取经人");
        }
}
