// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// create by snowcat jan 21 1998
#include <ansi.h>;
inherit ROOM;

void create ()
{
    set ("short", "������");
  set ("long", @LONG

�����ĳ�������ڿ�����ڶ��������죬��·������ʯ���̳ɣ�����
���������де���ľ������ԶԶ�ɼ����⸮�ĳ��ţ�������һ���ߴ�
���������ϱ���һ������

LONG);

  set("exits", ([
        "west" : __DIR__"chen1",
        "east" : __DIR__"tieta",
        "south" : __DIR__"machang",
      ]));

  set("outdoors", __DIR__);

  setup();
}

