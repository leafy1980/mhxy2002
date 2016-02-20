// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: some place in 西牛贺洲
// inside2.c

inherit ROOM;

void create()
{
  set ("short", "[0;33m练功场[m");
  set ("long", @LONG

一个小小的练功场．场内一个中年道士在教一些小道们武功。周
围兵器架上放着一些兵器。
LONG);
set("exits", ([ /* sizeof() == 4 */
"west": __DIR__"gate1",
"east": __DIR__"inside7",
"north": __DIR__"inside8",
"south": __DIR__"sleep",
]));
set("objects", ([
                __DIR__"npc/xiao": 3, 
                __DIR__"npc/zhangmen": 1,
     __DIR__"obj/rack": 1,
]) );
        set("no_clean_up", 0);
   set("outdoors", 1);
        setup();
}

void init()
{
object *inv;
int i;

 inv = all_inventory();
  for(i=sizeof(inv)-1; i>=0; i--)
{
if(!interactive(inv[i]))
if (!living(inv[i])) destruct(inv[i]);
}

        add_action("do_none","get");
        add_action("do_none","ji");
        add_action("do_none","steal");
    add_action("do_none","put");
    add_action("do_none","drop");
}

int do_none()
{
        object zm=present("zhang men");
        if( zm )
        {
        message_vision("$N对$n摇了摇头。\n",zm,this_player());
        return 1;
        }
        return 1;
}
int valid_leave(object me, string dir)
{
        if (dir == "south" ) {
        if (objectp(present("zhang men", environment(me)))) {
        if((string)me->query("family/family_name")=="方寸山三星洞") {
        return ::valid_leave(me, dir);
        }
        return notify_fail("掌门大弟子嚷到：那不是你该去的地方！\n");
        }
        }
        return ::valid_leave(me, dir);
}


