// created 17-06-2001 ����Ʈ(piao)

inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "ʯ�ﾡͷ");
  set ("long", @LONG
ʯ��ľ�ͷ��һ�¸�ǽ��ǽ����һ��խ�š�ǽ����һ����
��һ����ϡϡ��С�ӹ��ӹ�����������ʱ����ʱ�ģ�һ������
��Ѫˮ�ı����ӹ�����������
LONG
           );

  set("objects", ([ /* sizeof() == 1 */

__DIR__"obj/blood.c" : 1,
]));
  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"baiyun",
  "north" : __DIR__"sroom",

]));

  create_door("north", "խ��", "south", DOOR_CLOSED);
set("valid_startroom", 1);
setup();
}
