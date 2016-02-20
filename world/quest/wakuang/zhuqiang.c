#include <ansi.h>
inherit ROOM;
int do_zhuqiang(string arg);

 void create()
{
        set("short", WHT"��ǹ��"NOR);
        set("long", @LONG
����һ����ƽ����ͨ����ǹ�������ܶ������߰����ͭƤ���飬����
�Ѽ����Ŀ�ʯ����������Ժ�����ɸ�����ǹ��
LONG
        );

        set("exits", ([
                "west" : __DIR__"zhubang",
                "east" : __DIR__"zhucha",
                "north" : __DIR__"zhujian",
        ]));
        set("no_fight",1);
        set("no_beg",1);
        set("no_steal",1);
        setup();
}
void init()
{
        add_action("do_zhuqiang","zhuqiang"); 
        add_action("do_quit","quit");
        add_action("do_quit","exit");
        add_action("do_quit","exercise");
        add_action("do_quit","dazuo");
        add_action("do_quit","exert");
        add_action("do_quit","learn"); 
        add_action("do_quit","yun");
        add_action("do_quit","xue");
        add_action("do_quit","respirate");
        add_action("do_quit","tuna"); 
        add_action("do_quit","fight");
        add_action("do_quit","hit");
        add_action("do_quit","kill");
        add_action("do_quit","perform");
        add_action("do_quit","persuade");
        add_action("do_quit","quanjia");
        add_action("do_quit","practice");
        add_action("do_quit","lian"); 
        add_action("do_quit","study");
        add_action("do_quit","du");
        add_action("do_quit","teach");
        add_action("do_quit","jiao");
}

int do_zhuqiang(object ob)
{
        object me,ob1;
        int b1;
        me=this_player();
        b1 = this_player()->query("work/zhuqiang");
        
        if (!(ob = present("tong kuang", this_player())) &&
             !(ob = present("tie kuang", this_player())) &&
             !(ob = present("ying kuang", this_player())) &&
             !(ob = present("jing kuang", this_player())) &&
             !(ob = present("xuantie kuang", this_player())) &&
             !(ob = present("han tie", this_player())) )
                return notify_fail("������û�п�ʯ�������ǹ��\n");
                 
        if ( (int)me->query("sen")<250)
                return notify_fail("��ľ������㣬�޷���ǹ��\n");
        if( me->is_busy() )
                return notify_fail("�����ں�æ��������ǹ��\n");

        if ( (int)me->query("kee")<250)
                return notify_fail("����������㣬�޷���ǹ��\n");

        if ( (int)me->query("force")<300)
                return notify_fail("����������㣬�޷���ǹ��\n");

        message_vision(HIY"$N�Ƚ���ʯ�Ž�¯�������ɿ�״״��\n"NOR,me); 
        message_vision(HIY"����$N���ó�һ���󴸿�ʼ��ǹ��\n"NOR,me); 
        message_vision(HIY"��һ�����һ���Ϻõ���ǹ������$N����ǰ��\n"NOR,me); 
//        me->add("combat_exp",50+random(50));
//        me->add("potential",50+random(50));
//        me->add("daoxing",50+random(50));
        me->add("sen",-150);
        me->add("kee",-150);
        me->add("force",-200);
        me->start_busy(3); 

        if ( ob->query("name") ==YEL"ͭ��ʯ"NOR )
        {
        destruct(ob);             
        ob1=new(__DIR__"weapon/qiang/qiang1");
        ob1->set("value", 250);
        ob1->move(me);
        me->add("work/zhuqiang", 7);       
        return 1;
        }
        if ( ob->query("name") ==CYN"����ʯ"NOR )
        {
        destruct(ob);             
        if ( b1 < 100 ) 
        {
        me->add("work/zhuqiang",6);
        return notify_fail("��������ǹ֮��̫�ͣ�ǹ���������ã�\n");
        }
        ob1=new(__DIR__"weapon/qiang/qiang2");
        ob1->set("value", 0);
        ob1->set("no_get", 1);
        ob1->set("no_sell", 1);
        ob1->set("no_put", 1);
        ob1->set("no_give", 1);
        ob1->set("no_drop", 1);
        ob1->move(me);
        me->add("work/zhuqiang", 3);       
        return 1;
        }
        if ( ob->query("name") ==HIW"����ʯ"NOR )
        {
        destruct(ob);             
        if ( b1 < 300 )
        {
        me->add("work/zhuqiang",5);
        return notify_fail("����������֮��̫�ͣ������������ã�\n");
        }
        ob1=new(__DIR__"weapon/qiang/qiang3");
        ob1->set("value", 0);
        ob1->set("no_get", 1);
        ob1->set("no_sell", 1);
        ob1->set("no_put", 1);
        ob1->set("no_give", 1);
        ob1->set("no_drop", 1);
        ob1->move(me);
        me->add("work/zhuqiang", 3);       
        return 1;
        }
        if ( ob->query("name") ==HIY"���ʯ"NOR )
        {
        destruct(ob);             
        if ( b1 < 500 )
        {
        me->add("work/zhuqiang",4);
        return notify_fail("����������֮��̫�ͣ������������ã�\n");
        }
        ob1=new(__DIR__"weapon/qiang/qiang4");
        ob1->set("value", 0);
        ob1->set("no_get", 1);
        ob1->set("no_sell", 1);
        ob1->set("no_put", 1);
        ob1->set("no_give", 1);
        ob1->set("no_drop", 1);
        ob1->move(me);
        me->add("work/zhuqiang", 2);       
        return 1;
        }
        if ( ob->query("name") ==WHT"������ʯ"NOR )
        {
        destruct(ob);             
        if ( b1 < 700 )
        {
        me->add("work/zhuqiang",3);
        return notify_fail("����������֮��̫�ͣ������������ã�\n");
        }
        ob1=new(__DIR__"weapon/qiang/qiang5");
        ob1->set("value", 0);
        ob1->set("no_get", 1);
        ob1->set("no_sell", 1);
        ob1->set("no_put", 1);
        ob1->set("no_give", 1);
        ob1->set("no_drop", 1);
        ob1->move(me);
        me->add("work/zhuqiang", 2);       
        return 1;
        }
        else
        if ( ob->query("name") ==HIG"������ʯ"NOR )
        {
        destruct(ob);             
        if ( b1 < 1000 )
        {
        me->add("work/zhuqiang",2);
        return notify_fail("����������֮��̫�ͣ������������ã�\n");
        }
        ob1=new(__DIR__"weapon/qiang/qiang6");
        ob1->set("value", 0);
        ob1->set("no_get", 1);
        ob1->set("no_sell", 1);
        ob1->set("no_put", 1);
        ob1->set("no_give", 1);
        ob1->set("no_drop", 1);
        ob1->move(me);
        me->add("work/zhuqiang", 1);       
        return 1;
        }
        else
        if ( ob->query("name") ==HIR"ǧ�꺮��"NOR )
        {
        destruct(ob);             
        if ( b1 < 3000 )
        {
        me->add("work/zhuqiang",1);
        return notify_fail("����������֮��̫�ͣ������������ã�\n");
        }
        ob1=new(__DIR__"weapon/qiang/qiang7");
        if ( b1 > 5000 )
        {
        ob1=new(__DIR__"weapon/qiang/qiang8");
        }
        ob1->set("value", 0);
        ob1->set("no_get", 1);
        ob1->set("no_sell", 1);
        ob1->set("no_put", 1);
        ob1->set("no_give", 1);
        ob1->set("no_drop", 1);
        ob1->move(me);
        me->add("work/zhuqiang", random(2));       
        return 1;
        }
} 

int do_quit(string arg)
{
        write(this_player()->query("name")+"�����ĵ������ɣ�\n");
        return 1;
}