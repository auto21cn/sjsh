//示范程序
void die()
{
        object ob, me, corpse, obn;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        
        message_vision(WHT"$N大叫一声,妖王救我!!倒地而亡。\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
        message("vision", me->name() + "从妖怪身上发现了大量的银两。\n", me);
        obn=new("/obj/money/gold");
        obn->set_amount(random(50));
        obn->move(me);
        destruct(ob);
        return;
}
