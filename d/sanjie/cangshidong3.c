// sanjie cangshidong3.c

inherit ROOM;
void create()
{
        set("short", "��ʬ��");
        set("long", @LONG
        
һ���Źֵ�ɽ��������������Χ���˶��ţ����Ҷ��ڳ���Ѭ
�죬���Ǹ��õ���ζ��
LONG );
        set("outdoors", 0);
        set("exits", ([
              "north" : __DIR__"cangshidong4",
              "south" : __DIR__"cangshilang3",
        ]));
        set("objects", ([
                __DIR__"npc/guipotian": 1 ]) );
        setup();
}