// by the creators: AUANASIOS KOLVNIAS, AM: 3130096, p3130096@aueb.gr and 
// EMMANOUIL STAMATAKIS, AM: 3200300, p3200300@aueb.gr
#include "graphics.h"
#include "config.h"
#include <string>
#include "flowmaster.h"

void resize(int w, int h)
{
	FlowMaster * myFlowMaster = FlowMaster::getInstance();
	myFlowMaster->setWindowDimensions((unsigned int)w, (unsigned int)h); // for the updating of the window size during the operation of the FlowMaster instance we will be using
}



void draw()
{
	FlowMaster * myFlowMaster = FlowMaster::getInstance();	
	myFlowMaster->draw();

	
	
}

void update(float ms)
{
	FlowMaster* myFlowMaster = FlowMaster::getInstance();
	myFlowMaster->update();

}


int main(int argc, char** argv)
{
	FlowMaster * flowMaster = FlowMaster::getInstance();   // creation of an instance of the FlowMaster
	
	// designing the basic window and canvas of the Digital Film Archive
	graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Digital Film Archive");
	graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);
	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

	// Specifies a user-defined function to be called each time the window is to be redisplayed.
	graphics::setDrawFunction(draw);

	// Specifies a user-defined function to be called each time the state of the application needs to be updated.
	graphics::setUpdateFunction(update);

	// the font with which we will be writing
	graphics::setFont(std::string(ASSET_PATH) + "bitstream.ttf");

	// playing background music
	flowMaster->backgroundMusic();
	
	// Starts the message pump loop of the application window, processes all window and user interface events, calls the draw callback and invokes the update (when  mouse state change or keyboard key press occurs or at regularly timed intervals
	graphics::startMessageLoop();

	delete flowMaster; // alternatively, we could write a "releaseInstance" if the application does not terminate here and might need again the getInstance

	return 0;
}