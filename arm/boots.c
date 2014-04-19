#include <Sinbyen.h>
#include <item.h>

inherit "/std/item";

private descriptor attr_mod;

void boots_do_equip(mapping args) {
	attr_mod = args["who"]->add_attribute_modifier(([
		Modifier_Index  : Attr_Wil,
		Modifier_Amount : 20,
	]));
	args["who"]->message(({
        "as", 0 ,({ "pull", 0 }), ({ 'r', 0, this_object() }),
		"on, they slowly shape themselves to blend with", ({ 'r', 0, "legs" }),
		"and enhance", ({ 'r', 0, "natural beauty" }),
    }));
}

void boots_do_unequip(mapping args) {
	args["who"]->remove_attribute_modifier(&attr_mod);
}

void configure() {
	::configure();
	armour()->set_race("kielleth");
	add_description(({
        "The glossy",
		Description(([
            Description_Type                        : Description_Type_Element_Name,
            Description_Index                       : Element(([
                Element_Type                        : Material_Leather,
                Element_Color                       : "black",
            ])),
		])),
        "thigh boots appear to be comfortable and stylish.",
    }));
    add_description(({
        "Covering the feet and legs from toe to thigh, the boots magically adjust to",
        "fit the wearer.  For additional protection,",
		Description(([
            Description_Type                        : Description_Type_Element_Name,
            Description_Index                       : Element(([
                Element_Type                        : Material_Adamantite,
                Element_Color                       : "black",
            ])),
		])),
        "plates have been inserted between the lining and the leather.",
	}));
	armour()->set_armour_type(Armour_Type_Pair_of_Thigh_Boots);
	armour()->set_armour_style(Armour_Style_Simple);
	set_craft(Craft_Exquisite);
	add_proportion(([
		Element_Type       : Material_Leather,
		Element_Proportion : 0.7,
		Element_Color      : "black",
	]));
	add_proportion(([
		Element_Type       : Material_Adamantite,
		Element_Proportion : 0.2,
		Element_Part       : Part_Embedment,
		Element_Form       : Form_Plates,
	]));
	add_proportion(([
		Element_Type       : Material_Dweomer,
		Element_Proportion : 0.1,
	]));
	add_property(Prop_Slippery);
	add_hook(Do_Equip_Item, #'boots_do_equip);
	add_hook(Do_Unequip_Item, #'boots_do_unequip);
}

