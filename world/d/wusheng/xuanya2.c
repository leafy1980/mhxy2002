// changan wusheng
// xuanya2.c

inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "火云断崖中");
  set ("long", @LONG

火云断崖风光秀丽，当真是好去处！前方一座高崖，崖上有祥
云绕绕，隐有红光。崖壁上多是青苔锈葛，看上去异常的滑手。
崖上有兽鸣阵阵，空山回音不绝。
LONG);
  set("exits", ([ /* sizeof() == 3 */
  "down" : __DIR__"xuanya1",
]));
	set("outdoors", 1);
  setup();
}

void init()
{
	add_action("do_climb", "climb");
}

int do_climb(string arg)
{
	object me=this_player();
	
	if( !arg || (arg!="xuanya" && arg!="悬崖") )
		return notify_fail("你要爬什么？\n");
	if(me->is_busy())
		return notify_fail("你很忙，爬什么呀！\n");

	message_vision("$N搓了搓手，扒着石头的缝隙向崖上爬去 ... \n", me);
	me->start_busy(3);

	if( (int)me->query("kee") < 500 || (int)me->query("sen") < 500) {
		call_out("faila", 3, me);
		return 1;
	}

//	if( (int)me->query_skill("dodge",1)+(int)me->query_skill("unarmed",1) <=200 ){
//		call_out("faila", 3, me);
//		return 1;
//	}

	call_out("success", 3, me);
	return 1;
}
int success(object me)
{
	message_vision("$N越爬越高，渐渐隐入了云中 ... \n", me);
	me->move("/d/wusheng/xuanya3");
	me->receive_damage("kee", 400);
	me->receive_damage("sen", 400);
	message_vision("$N慢慢的爬了上来。\n", me);
	return 1;
}
