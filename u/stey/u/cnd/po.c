//cnd
inherit NPC;

void read_txt(object who,string num);

void create()
{
	set_name("风婆",({"feng po","feng shen","po"}));
	set("gender", "女性");
	set("age", 35);
	set("long", "    \n天宫中负责起风的天神，想要刮风下雨时，没有她\n的帮助是不行的。\n");

	set("attitude", "heroism");
	set("class", "xian");

	set("combat_exp", 60000);
	set("daoxing", 100000);

	setup();

	carry_object("/obj/loginload/skirt.c")->wear();
	carry_object("/obj/loginload/shoes.c")->wear();
	add_money("silver", 10);

}


void init()
{
  	add_action("do_read", "read");
}


void do_read(string arg,string num)
{
	if (num == "age")
	{
	write("     ≡≡≡≡≡≡≡≡≡≡≡≡仙侣情缘连线通知≡≡≡≡≡≡≡≡≡≡≡≡\n");
        write("     "+read_file("/topten/age.txt"));
        write("     ≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡\n");
	}
	if (num == "dx")
	{
		write("     ≡≡≡≡≡≡≡≡≡≡≡≡仙侣情缘连线通知≡≡≡≡≡≡≡≡≡≡≡≡\n");
        	write("     "+read_file("/topten/age.txt"));
        	write("     ≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡\n");
        }
        return ;

}
