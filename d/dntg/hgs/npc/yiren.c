inherit NPC;

void create()
{
        set_name("��������", ({"yiren"}));
        set("age", 22);
        set("gender", "����");
        set("long",
"һ�����ʽ���յģ����ڳ���������\n");
        set("attitude", "peaceful");

        set("combat_exp", 10000);
        set("shen_type", 1);

set_skill("wuhu-blade",40);
        set_skill("unarmed", 40);
        set_skill("dodge", 20);
        set_skill("parry", 40);
        set_skill("blade", 40);
        set_skill("force", 40);
        set("chat_chance", 8);
        set("chat_msg", ({
"���˺�������λ�������ף����³����󱦵أ����ָ�̣�\n",
"������ͭ�������ã���������λ��Ǯ������Ǯ����ûǮ�������˳���\n",
"�������˸��������������˵������廢���ŵ���\n",
"����ָ�����˵����û��һ�����������ģ�\n",
}) );
        setup();
	add_money("silver", 1+random(3));
        carry_object("/d/obj/weapon/blade/blade")->wield();
        carry_object("/d/obj/cloth/linen")->wear();
}
