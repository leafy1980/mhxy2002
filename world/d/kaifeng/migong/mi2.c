// Room: /shulin/lin2.c
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������ǹ�ս������ַ�ˣ���˵�����й����û���㻹�����ߣ��ѵ��뱻����Ե�ô��
LONG );
        set("exits", ([
                "north" : __DIR__"mi3",
                "south" : "/d/kaifeng/xiaozhen",
                "east" : __FILE__,
                "north" : __FILE__,
                "southeast" : __FILE__,
                "northeast" : __FILE__,
        ]));
         set("objects", ([
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
