#include <Sinbyen.h>
#include <room.h>

inherit Sinbyen_Room("Map_Base");

void configure() {
	Map_Base::configure();
	set_short("Amstaar's House");
	add_exit(Direction_North);
	add_exit(Direction_West);
}
