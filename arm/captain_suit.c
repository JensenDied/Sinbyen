#include <interval.h>
#include <item.h>
#include <Sinbyen.h>

inherit "/std/item";

void configure() {
    ::configure();
    add_description(([
            Description_Type        : Description_Type_Generic,
            Description_Order       : Description_Order_Very_Early,
    ]));
    add_description(([
            Description_Type        : Description_Type_Subject_Description,
            Description_Index       : Sinbyen_Definition("subject_crimson_craftmark_guard"),
            Description_Order       : Description_Order_Very_Slightly_Early,
    ]));
    add_proportion(([
        Element_Type                : Material_Adamantium,
        Element_Proportion          : 0.5,
        Element_Color               : "white",
    ]));
    add_proportion(([
        Element_Type                : Material_Gold,
        Element_Proportion          : 0.01,
        Element_Part                : Part_Inlay,
    ]));
    add_proportion(([
        Element_Type                : Material_Uru,
        Element_Proportion          : 3.0,
        Element_Flags               : Element_Flag_Suppress_Material_Name | Element_Flag_Blend,
    ]));
    add_proportion(([
        Element_Type                : Material_Leather,
        Element_Proportion          : 0.15,
        Element_Part                : Part_Underlayer,
    ]));
    add_proportion(([
        Element_Type                : Material_Kedusham,
        Element_Proportion          : 0.01,
        Element_Part                : Part_Aura,
        Element_Flags               : Element_Flag_Suppress_Material_Name | Element_Flag_Blend,
    ]));
    add_property(Prop_Holy);
    set_craft(Craft_Exquisite);
    armour()->set_autonomon_adapt(True);
    armour()->set_armour_type(Armour_Type_Full_Suit);
    armour()->set_armour_style(Armour_Style_Articulated);
    armour()->set_race("tuatha");
}

