// Room: /d/shaolin/luohan5.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
        set("short", "�޺��ò�");
	set("long", @LONG
����һ�伫Ϊ��ª���������������ܣ����˼�������⣬��
�ڿյ����ر��������������İڷ��ż��������ҷ��ڵĻƲ�
���ţ���λ�뷢���׵���ɮ�������������Ŀ�붨�������Ǳ���
ʮ���޺��������еĵط������پ����书�����ڴ������һλС
ɳ����һ�ߴ���վ����
LONG );
	set("exits", ([
                "west" : __DIR__"wuchang",
                "south" : __DIR__"zoulang3.c",
                "north" : __DIR__"hsyuan1.c",
	]));
	set("objects",([
                                __DIR__"npc/xuan-ku" : 1
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
