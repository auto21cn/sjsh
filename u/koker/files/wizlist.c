//modify by koker@sjsh.2002.01.4
#include <ansi.h>
inherit F_CLEAN_UP;
mapping wizhood=([
        "(admin)":      HIW" 天  神 "HIB,
        "(arch)":       HIM" 大  神 "HIB,
        "(wizard)":     HIY" 大巫师 "HIB,
        "(apprentice)": HIC" 天  使 "HIB,
        "(immortal)":   HIB" 精  灵 "HIB,
        "(elder)":      HIB" 荣誉玩家 "HIB,

]);

mapping wizlevel=([
        0:      "(admin)",
        1:      "(arch)",
        2:      "(wizard)",
        3:      "(apprentice)",
        4:      "(immortal)",
        5:      "(elder)",
]);

int main(object me, string arg)
{

        string *list, ch,job,area;
        int my_level,b, i, j, number,a,mark;
        object ob;

        number = 0;
        job="";
        list = sort_array(SECURITY_D->query_wizlist(), 1);
        write(HIR"★"+HIY+""+MUD_NAME +""HIR"★"HIG"巫师列表：\n"NOR);

        write(HIR"★"HIW"≡"HIB"──────────────────────────────"HIW"≡"HIR"★\n"NOR);
        write(HIB"  【"HIW"巫师等级"HIB"】   【"HIW"巫师ID"HIB"】【"HIW"状态"HIB"】【"HIW"负责区域"HIB"】【"HIW"  目 前 任 务  "HIB"】\n"NOR);

        write(HIR"★"HIW"≡"HIB"──────────────────────────────"HIW"≡"HIR"★"NOR);
        my_level=wiz_level(me);
        for (b=0;b<7;b++)
        {
        mark=0;
        for(i=0, j=0; i<sizeof(list); i++)
        if(SECURITY_D->get_status(list[i])==wizlevel[b]) mark=1;
        if(mark){
        printf(HIB"\n  【"+wizhood[wizlevel[b]]+"】  "NOR);
        for(i=0, j=0; i<sizeof(list); i++)
        if(SECURITY_D->get_status(list[i])==wizlevel[b])
        {

                ch = HIR"离线"NOR;
                a = 0;
//                 area=JOB_D->job_query(list[i]+"/area");
//                job=JOB_D->job_query(list[i]+"/job");
                if(!area) area="未知区域";
                if(!job) job="动向不明";
                if(ob=find_player(list[i]))

  //              if (!find_player(list[i])->query("env/invisibility")||( find_player(list[i])->query("env/invisibility") && wiz_level(find_player(list)
                {
                ch = HIG"在线"NOR ;
                a = 1;
                number = number + 1;
                };
                printf(HIY"  %-10s"" %s    "HIC"%-10s"HIW"  %s\n                ",list[i],ch,area,job," " ? "\n  " : " ");

        }
        }
        }
        write(HIR"\n★"HIW"≡"HIB"─────────────────────────"HIG"SJSH II"HIB"──"HIW"≡"HIR"★\n"NOR);
        printf(HIR"★"+HIY+MUD_NAME+HIG"目前一共有:"HIR" %s"NOR HIG"个巫师。\n"NOR,chinese_number(sizeof(list)) );
        printf(HIR"★"+HIY+MUD_NAME+HIG"的巫师守则请看:"+HIY"help wiz_rules "+NOR+"。\n");
        printf(HIR"★"+HIY+MUD_NAME+HIG"目前共有："BLINK HIR"%s"NOR HIG"位巫师在线上。"NOR,chinese_number(number));
        write("\n");
        return 1;
}

int help(object me)
{
  write(@HELP
指令格式：wizlist
指令说明：
           本指令用来查看目前总共有多少个巫师。
HELP
    );
    return 1;
}
