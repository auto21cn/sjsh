inherit F_VENDOR_SALE;

void create()
{
    reload("boss");
        set_name("兵器铺老板", ({"lao ban", "boss"}));
        
        set("gender", "男性");
        set("age", 50);

        set("combat_exp", 70000);
        set_skill("sword", 50);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set("force", 200);
        set("max_force", 200);
        set("force_factor", 5);

        set("vendor_goods", ([
                "sword": "/d/obj/weapon/sword/changjian",
                "blade": "/d/obj/weapon/blade/blade",
        ]) );

        setup();
        carry_object("/d/obj/cloth/linen")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();

}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting",1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say( name()+"打了个盹,不屑的看了看。\n");
                        break;
        }
}
int accept_fight(object me)
{
        command("say 哼，老子的地盘上也敢撒野！\n");
        return 1;
}


