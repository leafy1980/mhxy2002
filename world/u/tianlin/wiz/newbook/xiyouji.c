#include <ansi.h>
inherit ITEM;
void create()
{
 set_name(HIY"���μ�"NOR, ({ "xiyouji", "book"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long","�Ĵ�����֮һ��\n");
 set("value", 600000);
                set("material", "paper");
                set("skill",
                ([
                        "name": "literate",
                        "exp_required": 10,
                        "jing_cost":    10,
                        "difficulty":   15,
                        "max_skill":    80,
                        "min_skill":    49,
                ]) );
        }
}
