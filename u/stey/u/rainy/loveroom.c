inherit ROOM;;
#include <ansi.h>
void create ()
{
set ("short",HIW"情  冢");
set ("long", @LONG

    白色而苍茫的世界，没有踮着脚尖跳舞的雪精灵，没有
月亮的柔美的光韵，没有生人的气息，甚至丝毫的风吹草动。
这是一间让人窒息的快要死掉的暗室，里面装满的唯有沉甸
甸，沾满灰尘的回忆，它的名字叫----过去。还有一个躲在
脚落里舔着伤口的伤心人，也许她已无心。
    黑夜里，窗外有几声厮哑刺耳的鸦叫，气氛让人毛骨悚
然，有个声音从她的心里传出来：
        我爱上让我奋不顾身的一个人，我以为这就是我
      追求的世界。然而横冲直撞，被误解被骗，直到被
      痛的遍体鳞伤。是否成人的世界背后终有残缺？我
      走在每天必须面对的那条岔路，我忽然迷失了整个
      世界....我怀念过去单纯美好的小幸福。爱总是让
      人哭，让人觉得不满足，天空很大却看不清楚，好
      孤独！

    一遍又一遍反复的痴唱着这几句，在岁月中蹉跎了整个
世纪。也许，爱情只是一个“冢”。唯美的爱情是“花冢”
，而她守着的只是一个“情冢”。然后，就这样红颜空待老
，接着孤独的死去，永世无法轮回....但她依旧不悔于此。

LONG);;;
set("exits",([
"south" : __DIR__"kiteroom",
"east" : __DIR__"tearoom",
"west" : __DIR__"smellroom",
"north" : __DIR__"babyroom",
]));
set("objects",([
"/u/rainy/npc/sure":1,
"/u/rainy/obj/bishou":1]));
setup();
}
