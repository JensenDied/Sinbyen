#include <item.h>
#include <interval.h>
#include <energy.h>
#include <Sinbyen.h>

inherit "/std/item";

internal int skill_mod_amount;
internal descriptor skill_mod;

void cloak_synchornize_mods(object who) {
    who ||= query_user();
    int amount = scale_conversion(round(who->query_energy_amount(Energy_Agonistic)), 0, 200, 5, 40);
    if(amount != skill_mod_amount)
        skill_mod_amount = amount;
    if(!amount)
        return who->remove_skill_modifier(&skill_mod);
    descriptor dxr = (([
        Modifier_Index          : ({
            Skill_Courage,
            Skill_Leadership,
            Skill_Massive_Blow,
        }),
        Modifier_Amount         : amount,
        Modifier_Add_Display    : ([
            Message_Content     : ({
                0, ({ "feel", 0 }), "that", ({ 'r', 0, "anger" }), "can now assist you in combat",
            }),
            Message_Senses      : Message_Sense_Spiritual,
        ]),
        Modifier_Remove_Display : ([
            Message_Content     : ({
                0, ({ "feel", 0 }), "that", ({ 'r', 0, "anger" }), "can no longer assist you in combat",
            }),
        Message_Senses      : Message_Sense_Spiritual,
        ]),
    ]));
    if(skill_mod) {
        who->remove_skill_modifier(skill_mod, Modifier_Event_Flag_Silent | Modifier_Event_Flag_Suspend_Calculations);
    }
    skill_mod = who->add_skill_modifier(dxr, skill_mod?Modifier_Event_Flag_Silent:0);
}

void cloak_do_equip(mapping args) {
    object who = args["who"];
    Interval_Set(#'cloak_synchornize_mods, 15);
    cloak_synchornize_mods(who);
}

void cloak_do_unequip(mapping args) {
    object who = args["who"];
    who->remove_skill_modifier(&skill_mod);
    Interval_Remove(#'cloak_synchornize_mods);
}

void configure() {
    ::configure();
    alter_identity(([
        Identity_Nouns  : ({ "crimson cloak", "cloak" }),
        Identity_Color  : "white-and-dark red-and-white",
    ]));
    add_description(Description_Type_Generic);
    add_description(([
        Description_Type    : Description_Type_Subject_Description,
        Description_Index   : Sinbyen_Definition("subject_crimson_craftmark_guard"),
        Description_Order   : Description_Order_Very_Slightly_Early,
    ]));
    add_description(({
        'v', ({ "recognize", 'v' }), ({ 'v', 0 }), "as a symbol of leadership amongst the crimson guard",
    }));
    set_craft(Craft_Exquisite);
    armour()->set_autonomon_adapt(True);
    armour()->set_armour_type(Armour_Type_Cloak);
    armour()->set_race("orc");
    add_hook(Do_Equip_Item, #'cloak_do_equip);
    add_hook(Do_Unequip_Item, #'cloak_do_unequip);
    add_proportion(([
        Element_Type               : Material_Cotton,
        Element_Proportion         : 1.0,
        Element_Color              : "red",
    ]));
}

