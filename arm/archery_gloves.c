#include <interval.h>
#include <item.h>
#include <Sinbyen.h>

inherit "/std/item";

void configure() {
	::configure();
	add_description(Description_Type_Generic);
	set_craft(Craft_Exquisite);
	armour()->set_autonomon_adapt(True);
	armour()->set_armour_type(Armour_Type_Pair_of_Fingerless_Gloves);
	armour()->set_armour_style(Armour_Style_Simple);
	add_proportion(([
		Element_Type              : Material_Leather,
		Element_Proportion        : 0.85,
	]));
	add_proportion(([
		Element_Type              : Material_Fur,
		Element_Proportion        : 0.15,
		Element_Part              : Part_Underlayer,
	]));
}

