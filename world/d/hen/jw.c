// by happ@YSZZ
inherit ROOM;
#include <hen.h>

void create ()
{
  set ("short", "郊外");
  set ("long", @LONG

       这里已经是郊外了，显得很空旷，你可以尽情的玩耍了。（[1;35menjoy[m）
       西面有一块草地。

[m
LONG);
  set("exits", ([ /* sizeof() == 4 */
        "north": __DIR__"road7",
        "south":__DIR__"gate",
        "west": __DIR__"grass",
]));

        setup();
}

void init()
{
        add_action("do_enjoy","enjoy");
}

int do_enjoy()
{
        object ob = this_player();
        int i = 150 + random(50);

        if( ob->query("hen/money") < i )
                return notify_fail("你的钱不够用拉。\n");

        ob->add("hen/weight",1);
        ob->add("hen/dirty",5);
        ob->add("hen/happy",12);
        ob->add("hen/satisfy",12);
        ob->command_function("cls");
        ob->command_function("shape");
        ob->add("hen/affection",1);
        cat(KITE);
        write("放风筝真好玩啦...\n");
        return 1;
}
