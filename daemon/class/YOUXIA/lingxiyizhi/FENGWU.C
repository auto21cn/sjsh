// lingxiyizhi.c �������
// created 17-06-2001 piao
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit SSERVER;
 
int perform(object me, object target)
{
        string msg, str;
	int extra;
	object weapon,ob;
	if(me->is_busy())
                return notify_fail("������û�գ��޷�ʹ�á�"HIR"�������"NOR"����\n");
	extra = me->query_skill("lingxiyizhi",1);
        if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("��"HIR"�������"NOR"��ֻ����ս����ʹ�á�\n");

        if(me->query("family/family_name") != "��������" )
                return notify_fail("�����Ķ�͵ѧ�����书��Ҳ���á�"HIR"�������"NOR"��?\n");
 
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("��"HIR"�������"NOR"��ֻ�ܿ���ʹ�á�\n");             
       
	 if( (int)me->query("force") < 1000 )
                return notify_fail("�������������\n");

        if( (int)me->query_skill("lingxiyizhi",1) < 149 )
                return notify_fail("�����Ϭһָ��򲻹����޷�ʹ�á�"HIR"�������"NOR"����\n");
        if( (int)me->query_skill("unarmed",1) < 149 )
                return notify_fail("����˻��񶷻�򲻹����޷�����"HIR"�������"NOR"����\n");
        if( (int)me->query_skill("force",1) < 179 )
                return notify_fail("����ڹ���Ϊ�������޷�ʹ�á�"HIR"�������"NOR"����\n");
	me->add_temp("apply/attack",extra*2);
	me->add_temp("apply/damage",extra*2);
	weapon = me->query_temp("weapon");

        msg = HIW "$N��Ϭһָ����Ȼ֮��ʹ����"HIR"��������졹"HIW"��ʱ��ؼ�·����һֻ��˷���$n��
"HIR"��                                                                  ��
      ��                                                      ��
            ��                                          ��
                  ��                              ��\n" NOR;
	         message_vision(msg, me, target);                
        msg = HIY  "\n          ��\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "\n                   ��\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "\n                            ��\n" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB "\n                                     ��\n" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

                  if (target->query("eff_kee")<0 || !living(target))  
{str=""+target->name()+"��"+""HIW""+me->name()+""HIM""+"��½С��ľ�ѧ��"HIR"�������"HIM"��ɱ���ˣ���˵˲��ʬ��һ��Ϊ�ҽ���"NOR"";
        message("channel:rumor",HIM"��"HIW"��Ѩ����"HIM"��ĳ�ˣ�"+str+"\n"NOR,users());
	               }

        me->add_temp("apply/attack",-extra*2);
	 me->add_temp("apply/damage",-extra*2);
        me->receive_damage("kee", 100);
        me->receive_damage("sen", 200);
        me->add("force", -400);
    me->start_busy(2+random(2));;

        return 1;
}
