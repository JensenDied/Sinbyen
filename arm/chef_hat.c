#include <Sinbyen.h>
#include <item.h>

inherit "/std/item";

void configure() {
    ::configure();
    alter_identity(([
        Identity_Code               : "chef's hat",
        Identity_Known_Adjectives   : ({({ "chef", 0, Seeable_Order_Late })}),
        Identity_Adjectives         : ({({ "wrinkled", 0, Seeable_Order_Middle })}),
    ]));
    add_description(({
        ({ 'v', 0 }), ({ "are", 0 }), "a {{white}white cotton chef's hat}",
    }));
    add_description(({
        "It is old and wrinkled with use",
    }));
    set_craft(Craft_Good);
    armour()->set_armour_type(Armour_Type_Hat);
    armour()->set_race("human");
    armour()->set_autonomon_adapt(True);
    add_proportion(([
        Element_Type       : Material_Cotton,
        Element_Proportion : 4.0,
        Element_Color      : "white",
    ]));
    set_global_rarity(Rarity_Very_Common);
}

