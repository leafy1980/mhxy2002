// powerup.c ⨺��ڹ�����
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
   int skill;
   if( target != me )
   return notify_fail("��ֻ����⨺��ڹ��������Լ���ս������\n");
   if( (int)me->query("force") < 300  )
   return notify_fail("�������������\n");
   if( (int)me->query_temp("powerup") )
   return notify_fail("���Ѿ����˹����ˡ�\n");
   skill = me->query_skill("mihou-force",1);
   me->add("force", -200);
   message_vision(
   HIY "$N΢һ��������⨺��ڹ���ȫ�����������������޷����裬ë�����������������ˡ�\n" NOR,me);
//   me->add_temp("apply/attack", skill/5)
//   me->add_temp("apply/attack", skill/5);
   me->add_temp("apply/dodge", skill/5);
   me->set_temp("powerup", 1);
   me->start_call_out((:call_other, __FILE__, "remove_effect", me, skill/5:), skill);
   if( me->is_fighting() ) me->start_busy(3);
   return 1;
}
void remove_effect(object me, int amount)
{
//   me->add_temp("apply/attack", - amount);
   me->add_temp("apply/dodge", - amount);
   me->delete_temp("powerup");
   tell_object(me, "���⨺��ڹ�������ϣ��������ջص��\n");
}