// changan lingtai
// room5.c

inherit ROOM;

void create()
{
  set ("short", "������");
  set ("long", @LONG

�����޺��Ĵ������޺��������ڴ�����У����Ƿ���ɽ����
һλ���ߡ�
LONG);
set("exits", ([ /* sizeof() == 4 */
"southwest": __DIR__"room1",
]));
set("objects", ([
        __DIR__"npc/fuhu": 1 ]) );
        set("no_clean_up", 0);
        set("outdoors", 1);
        setup();
}