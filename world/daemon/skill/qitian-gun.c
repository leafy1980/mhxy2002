// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

inherit SKILL;
#include <ansi.h>;

string* skill_head =({
        "[31m只见$N身体一歪，一招[m",
        "[32m$N一声长哮，一招[m",
        "[33m$N一提气，使出一招[m",
        "[34m$N一声断喝，一式[m",
        "[35m$N使出[m",
        "[36m$N提气发力，大吼一声，使出[m",
});

string* skill_tail =({
        "[31m，手中$w向$n的$l攻来！[m",
        "[32m，随手一棒向$n当头砸下[m",
        "[33m，只见$w朝$n急速飞去。[m",
        "[34m，手中$w缓缓的落向$n，但这其中蕴藏无限杀机。[m",
        "[35m，手中$w似轻实重，真奔$w。[m",
        "[36m，手中$w光芒暴涨，直罩$n。[m",
});

mapping *action = ({
        ([      "name":                 "一棍定乾坤",
                "action":
"只见$N身体一歪，手中的$w直奔$n的脑门，$n大吃一惊.",
                "dodge":                5,
               "parry":   -10,
                "damage":               60,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "棒打玉帝",
                "action":
"$N一声长哮，一招[1;32m「棒打玉帝」[m，$w向$n全身要害攻来！",
                "dodge":                0,
     "parry":     0,
                "damage":               55,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "横扫天宫",
                "action":
"$N站定身型，手中$w向天一指，一个大圆直对$n落下",
                "dodge":                10,
     "parry":   -20,
                "damage":               45,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "齐天又一棍",
                "action":
"$N一声巨喝，好一个"+HIW"「齐天又一棍」"NOR+"！\n就在$n一愣之间，$N手中$w已是呼啸而至，扫向$n的$l",
                "dodge":               10,
     "parry":   -15,
                "damage":               55,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "无声胜有声",
                "action":
"$N一招[1;33m「无声胜有声」[m缓缓的落向$n，但这其中蕴藏无限杀机。",
                "dodge":                -5,
     "parry":     -5,
                "damage":               40,
                "damage_type":  "砸伤"
        ]),   
        ([      "name":                 "流星赶月",
                "action":
     "$N一提气，使出一招[1;37m「流星赶月」[m只见$w朝$n急速飞去。",
                "dodge":                5,
     "parry":   -10,
                "damage":               35,
                "damage_type":  "砸伤"
        ]),   
   ([   "name":        "圣棍一击",
     "action": 
    "$N使出了最后的绝招[1;35m「圣棍一击」[m，$n还没弄清怎么回事，$N手中的$w已经落在自己的头上！",
     "parry":   -40,
     "dodge":   -100,
     "damage":   250,
     "damage_type":  "砸伤"
   ]),
});


int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 150 )
                return notify_fail("你的内力不够，没有办法练齐天棍法，多练些内力再来吧。\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "stick" )
                return notify_fail("你必须先找一根棒子才能练棒法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="stick"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
     mapping* m_actions;
     m_actions=me->query("skill_qitian-gun");
     if(me->query("skill_qitian-gun")==0 )
     return action[random(sizeof(action))];
     if( random(4) == 1 )
     return m_actions[random(sizeof(m_actions))];
     else
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 50
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的内力或气不够，没有办法练习齐天棍法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -10);
        write("你按着所学练了一遍齐天棍法。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}
string perform_action_file(string action)
{
return CLASS_D("houyao") + "/qitian-gun/" + action;
}

void skill_improved(object me)
{
   int m_skill=me->query_skill("qitian-gun",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"你对齐天棍的领悟加深了，你的齐天棍进入了一个新的境界！\n"NOR);
     if(random(me->query("kar"))<20){
        tell_object(me,HIW"然而你的心中居然产生了一种失落感！\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"然而你的心中升起一种惆怅的感觉，仿佛有一丝重要的东西没有抓住。\n"NOR);
       return;
     }
     tell_object(me,HIW"你突然福至心灵，对齐天棍领悟出了一招新的用法！\n"NOR);
     tell_object(me,"请为这招取一个名字：");
     input_to( (: call_other, __FILE__, "name_skill", me:));
   }
   return;
}

void name_skill(object me, string arg)
{
   mapping* m_actions;
   mapping m_act=([]);
   int content;
   string msg;

   m_actions=me->query("skill_qitian-gun");
   if(!pointerp(m_actions))m_actions=({});

   content=me->query("str")+2*me->query_skill("unarmed",1)/10;
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=me->query("con")+me->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"砸伤"]);

   if(!arg||arg==" ")arg="齐天棍绝技"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+"「"+arg+"」"
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_qitian-gun",m_actions);
}
