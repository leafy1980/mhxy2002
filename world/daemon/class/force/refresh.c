//by tianlin 2001.8.6.������ɫ��Ҫ��̫���˿�����
//by tianlin 2002.3.11ȥ��ansi
#include <ansi.h>
inherit SSERVER;

int exert(object me, object target)
{
    int diff, neilineed;
    
	if( target != me ) return notify_fail("��ֻ�����ڹ��ա��Լ�������\n");

/*            if(environment(me)->query("no_fight")  ||
          environment(me)->query("no_magic") )
              return notify_fail("��ȫ���ڽ�ֹ�˶���\n");
*/
	if( (int)me->query("force") < 20 )
		return notify_fail("�������������\n");
	if( (int)me->query_skill("force") < 10 )
	    return notify_fail("����ڹ���Ϊ������\n");	
		
    diff = me->query("eff_sen") - me->query("sen");
    neilineed = diff * 50 / (int)me->query_skill("force");
    if(neilineed < 1)
	   return notify_fail("�����ھ�����������������\n");

    if(neilineed > me->query("force")) neilineed = me->query("force");
    diff = neilineed * (int)me->query_skill("force") / 50;
                                      		
	me->receive_heal("sen", diff);
	me->add("force", -neilineed);

	message_vision("$N"NOR"��һ�������˿����������������Ѷ��ˡ�\n", me);

	if( me->is_fighting() ) me->start_busy(1);

	return 1;
}