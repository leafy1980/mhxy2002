//[4;53m[1;31mBy tianlin@mhxy for 2001.9.27[2;37;0m
// 部分从新编写

#include <ansi.h>
inherit ROOM;

string look_shibei();

void create()
{
      set("short",YEL"松林小路"NOR);
      set("long",@LONG
这是山脚松林中的小路，两边长满参天的红松树，只能看见一线天空。
路旁有道士在奋力砍树。东边可回大道。
    路边有个石碑[1;32m([4;53m[1;31mshibei[2;37;0m[1;32m)[2;37;0m，很多游客在围那里。原来西边上去就是名镇
天下的解剑岩了，
LONG);
      set("outdoors", "wudang");
      set("item_desc", ([
          "shibei" : (: look_shibei :),
      ]));
      set("exits",([ /* sizeof() == 1 */
          "westup" : __DIR__"jiejianyan",
          "east"   : __DIR__"slxl1",
          "south"  : __DIR__"songlin1",
          "north"  : __DIR__"songlin2",
      ]));
      set("no_clean_up", 0);
      set_temp("wayao1",1);
      setup();
}

string look_shibei()
{
        return
        HIM"※※※※※※※※※※※※※※※※※※※※※※※※※\n"
        HIM"※※※※　        　　　　　　　　　　　　※※※※\n"
        HIM"※※※※　        　"NOR+HIW"[4;53m武当派通告"NOR+HIM"    　　　　※※※※\n"
        HIM"※※※※　                            　　※※※※\n"
        HIM"※※※※　    "NOR+HIY"往前就是武当山解剑岩。所有"NOR+HIM"　※※※※\n"
        HIM"※※※※　"NOR+HIY"外来人客请自觉解剑。邪魔外道到"NOR+HIM"　※※※※\n"
        HIM"※※※※　"NOR+HIY"此止步。"NOR+HIM"                　　　　※※※※\n"
        HIM"※※※※　　　　　                　　　　※※※※\n"
        HIM"※※※※※※※※※※※※※※※※※※※※※※※※※\n"NOR;
}
