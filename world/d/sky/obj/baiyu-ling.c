// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// dagger.c : an example weapon

#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
   set_name(HIW"������"NOR, ({"baiyu-ling"}));
   set_weight(10);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "֧");
     set("long", "�������,ͨ��ѩ��,���ּ���,�ഫ��ƾ�˵�����������.\n");
     set("value", 50);
     set("material", "gold");
     set("no_drop",1);
     set("no_sell",1);
     set("no_put",1);
     set("no_get",1);
   }
   init_dagger(4);

// These properties are optional, if you don't set them, it will use the
// default values.

   set("wield_msg", "$N�ӻ�������һ��$n�������С�\n");
   set("unwield_msg", "$N�����е�$n���뻳�С�\n");

// The setup() is required.

   setup();
}