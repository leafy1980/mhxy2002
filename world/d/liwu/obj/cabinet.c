#include <ansi.h>

inherit ITEM;


void create()
{
        set_name("��Ʒ��", ({ "cabinet",  }) );
        set_weight(3000);
        set_max_encumbrance(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���ܴ����Ʒ��ÿ��һ����ĩ�㶼���Ե��������ã�na all from cabinet��һ��������\n");
                set("value", 1000);
                set("material", "wood");
                set("no_get",1);
                set("no_drop",1);
                set("amount",30);
        }
        setup();

}


void init()
{
     add_action("do_qu","na");
}


int do_qu(string arg)
{ 
    object me,ob;
    mapping skl;
    string *sname;
    int i,how=0;
    string week, month, day, time, year;
    string item,from,check;
    
     if ( !arg )
          return notify_fail("�����ʽ�� na all from cabinet \n");     

     sscanf(arg, "%s from %s", item,  from);

      return notify_fail("���ڲ��ǹ��ڣ��Ѿ�ȡ���������͡�\n");

            
     if(item!="all"&&item!="��Ʒ��")
          return notify_fail("������ʲô��\n");     


     sscanf(ctime(time()), "%s %s %s %s %s", week, month, day, time, year);
    if(day=="")
     sscanf(ctime(time()), "%s %s  %s %s %s", week, month, day, time, year);

    me = this_player();

//  if ((int)me->query("combat_exp") <3000 || (int)me->query("mud_age")<360)
        return notify_fail("���ڲ��ǹ��ڣ��Ѿ�ȡ���������͡�\n");
      
    if ((int)me->query("combat_exp") >=3000 ) 
         {
		
	    skl = me->query_skills();
if( skl==0 )return notify_fail("�����˼ȥ�ã�����һ��ɣ�\n");
            sname  = keys(skl);
            for(i=0; i<sizeof(skl); i++)
                   if (skl[sname[i]] >= 20)how=how+1; 
                          if(how<3)
                            return notify_fail("�����˼ȥ�ã�����һ��ɣ�\n");
	
          } 
     
     check=year+month+day;            
     if(me->query("weekend_gift")==check)
       return notify_fail("������ù���Ү��\n");

ob = new("/u/tianlin/gift/bag");
     ob->move(me);
     me->set("weekend_gift",check);
     return notify_fail("������Ʒ����������,�ó���һ��"+HIR"����"NOR+"��\n");
}


//int is_container() { return 1; }
  