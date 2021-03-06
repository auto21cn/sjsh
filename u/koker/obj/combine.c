// combine.c

#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

mapping combine_list = ([
        // 三个钻石碎片合并成为一个钻石
        ({ "/quest/obj/bssp_b-1",
           "/quest/obj/bssp_b-2",
           "/quest/obj/bssp_b-3" }) : "/quest/obj/风暴之完美绿宝石",

        // 三个钻石合并成为一个精美钻石
        ({ "/clone/gift/diamond-1",
           "/clone/gift/diamond-2",
           "/clone/gift/diamond-3" }) : "/clone/gift/fdiamond",

        // 三个精美钻石合并成为一个神之钻石
        ({ "/clone/gift/fdiamond-1",
           "/clone/gift/fdiamond-2",
           "/clone/gift/fdiamond-3" }) : "/clone/gift/mdiamond",

        // 三个玛瑙碎片合并成为一个玛瑙
        ({ "/clone/gift/cagate-1",
           "/clone/gift/cagate-2",
           "/clone/gift/cagate-3" }) : "/clone/gift/agate",

        // 三个玛瑙合并成为一个精美玛瑙
        ({ "/clone/gift/agate-1",
           "/clone/gift/agate-2",
           "/clone/gift/agate-3" }) : "/clone/gift/fagate",

        // 三个精美玛瑙合并成为一个神之玛瑙
        ({ "/clone/gift/fagate-1",
           "/clone/gift/fagate-2",
           "/clone/gift/fagate-3" }) : "/clone/gift/magate",

        // 三个水晶碎片合并成为一个水晶
        ({ "/clone/gift/ccrystal-1",
           "/clone/gift/ccrystal-2",
           "/clone/gift/ccrystal-3" }) : "/clone/gift/crystal",

        // 三个水晶合并成为一个精美水晶
        ({ "/clone/gift/crystal-1",
           "/clone/gift/crystal-2",
           "/clone/gift/crystal-3" }) : "/clone/gift/fcrystal",

        // 三个精美水晶合并成为一个神之水晶
        ({ "/clone/gift/fcrystal-1",
           "/clone/gift/fcrystal-2",
           "/clone/gift/fcrystal-3" }) : "/clone/gift/mcrystal",

        // 三个翡翠碎片合并成为一个翡翠
        ({ "/clone/gift/cjade-1",
           "/clone/gift/cjade-2",
           "/clone/gift/cjade-3" }) : "/clone/gift/jade",

        // 三个翡翠合并成为一个精美翡翠
        ({ "/clone/gift/jade-1",
           "/clone/gift/jade-2",
           "/clone/gift/jade-3" }) : "/clone/gift/fjade",

        // 三个精美翡翠合并成为一个神之翡翠
        ({ "/clone/gift/fjade-1",
           "/clone/gift/fjade-2",
           "/clone/gift/fjade-3" }) : "/clone/gift/mjade",
]);

int main(object me, string arg)
{
        mapping same;                   // 判断重复的物品的需要的mapping
	string *item_list, *name_list;  // 合并的物品ID表和匹配的基本名字表
        string bname;                   // 物品对应的文件的基本名字
        object *ob_list;                // 合并的所有物品
        string *per;                    // mapping中记录的可合并的基本名字表
	object obj;                     // 生成的物品
        int i;

	if (! arg)
                return notify_fail("你要合并什么物品？\n");

        if (me->is_busy())
                return notify_fail("先忙完了你的事情再做这件事情吧！\n");

        if (me->is_fighting())
                return notify_fail("你现在正在打架，没时间做这些事情。\n");

//        if (me->query("max_jingli") < 500)
//                return notify_fail("你现在的精力修为有限，无"
//                                   "法施展如此艰深的法力。\n");

//        if (me->query("jingli") < 300)
//                return notify_fail("你现在精力不济，无法施展法力。\n");

        item_list = explode(arg, "&");
        ob_list   = allocate(sizeof(item_list));
        name_list = allocate(sizeof(item_list));
        same = allocate_mapping(sizeof(item_list));
        for (i = 0; i < sizeof(item_list); i++)
        {
                bname = item_list[i];
                while (bname[0] == ' ') bname = bname[1..<0];
                while (bname[strlen(bname) - 1] == ' ') bname = bname[0..<2];
                ob_list[i] = present(bname, me);
                if (! objectp(ob_list[i]))
                        return notify_fail("你身上没有 " + bname +
                                           " 这种物品啊。\n");
                if (i > 0 && member_array(ob_list[i], ob_list[0..i - 1]) != -1)
                        return notify_fail("合并物品需要指明不同"
                                           "的物品，不要重复指明一件物品。\n");
                bname = base_name(ob_list[i]);
                if (undefinedp(same[bname]))
                        same[bname] = 1;
                else
                        same[bname]++;
                name_list[i] = bname + "-" + (string) same[bname];
        }

        message_vision(HIM "$N" HIM "将一些物品摆"
                       "在一起，默运神通使它们变化。\n" NOR, me);
        me->start_busy(1);

//        me->add("jingli", -200);
        foreach (per in keys(combine_list))
        {
                if (per - name_list == ({ }))
                {
                        // 找到了合适的组合
                        obj = new(combine_list[per]);
                        for (i = 0; i < sizeof(ob_list); i++)
                                destruct(ob_list[i]);

                        message_vision(HIW "数道光芒闪过，似乎发生了"
                                       "不同寻常的事情。\n" NOR, me);   
                        tell_object(me, HIC "你利用手头的物品创造了" + obj->name() +
                                        HIC "！\n" NOR);
 //                       me->add("magic_points", 1);
 //                       me->add("max_jingli", -100);
                        obj->move(me, 1);
                        return 1;
                }
        }
        message_vision(HIG "过了半天，似乎没有任何变化，$N"
                       HIG "一脸悻悻。\n", me);

        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : combinue <特殊物品> & <特殊物品> & ...

这个指令可以让你将某些特殊物品合并成一种新的物品，哪些才能合
并？这就要靠你去发掘了。每次合并都会损失一些精力的上限。如果
要合并的几个物品名字相同，则需要指明他们的序号，比如有三个钻
石碎片，如果要合一，则需要输入：

combine chipped diamond & chipped diamond 2 & chipped diamond 3

HELP
    );
    return 1;
}
