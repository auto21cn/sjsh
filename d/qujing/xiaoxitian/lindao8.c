// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "�ֵ�");
  set ("long", @LONG

����������������������֦�����������������ǿ�֦��Ҷ����
��ȥ֨֨���졣�ֵ���������������ɢ��������ˮ����������
���Ͽհ���Ʈɢϼ����������

LONG);

  set("exits", ([
        "northeast"   : __DIR__"lindao1",
        "west"   : __DIR__"lindao7",
      ]));
  set("outdoors", __DIR__);

  setup();
}


