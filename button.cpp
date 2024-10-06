#include "button.h"
#include "graphics.h"
#include "flowmaster.h"
#include "config.h"

void Button::update()
{
}

// Draws the main button for searching
void Button::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	br.texture = std::string(ASSET_PATH) + "search.png";	
	graphics::drawRect(pos[0],pos[1],size[0],size[1],br);
	
}

void Button::draw(float posx, float posy, float width, float height, std::string backgroundTexture)
{
	// Draw for any other button
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	br.texture = std::string(ASSET_PATH) + std::string(backgroundTexture);
	graphics::drawRect(posx, posy, width, height, br);

}

void Button::init()
{
}

// Checks if an action happens inside the body of a button, if yes returns True
bool Button::contains(float x, float y)
{
	return distance(x, y, pos[0], pos[1]) < size[0]*0.6f;
}