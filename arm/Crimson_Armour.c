#include <interval.h>
#include <item.h>
#include <Sinbyen.h>

inherit "/std/item";

void configure() {
    ::configure();
    add_description(([
        Description_Type    : Description_Type_Generic,
        Description_Order   : Description_Order_Very_Early,
    ]));
    add_description(([
        Description_Type    : Description_Type_Subject_Description,
        Description_Index   : Sinbyen_Definition("subject_crimson_craftmark_guard"),
        Description_Order   : Description_Order_Very_Slightly_Early,
    ]));
    set_craft(Craft_Exquisite);
    add_proportion(([
        Element_Type              : Material_Uru,
        Element_Proportion        : 1.0,
        Element_Flags              : Element_Flag_Suppress_Material_Name | Element_Flag_Blend,
    ]));
    add_proportion(([
        Element_Type              : Material_Leather,
        Element_Proportion        : 0.15,
        Element_Part              : Part_Underlayer,
    ]));
}

