#pragma once
#include "widget.h"
#include "config.h"
#include "graphics.h"


class Button : public Widget // inherits the Widget class
{
	//button center
	float pos[2] = { 0,0 };
	//button size (width-height)
	float size[2] = { 0,0 };
public:		
	void update() override;
	void draw() override;
	void draw(float posx, float posy, float width, float height, std::string backgoundTexture);
	void init() override;

	//getters-setters
	float getPosX() { return pos[0]; }
	float getPosY() { return pos[1]; }
	void setPosX(float x) { pos[0] = x; }
	void setPosY(float y) { pos[1] = y; }

	float getWidth() { return size[0]; }
	float getHeight() { return size[1]; }
	void setWidth(float x) { size[0] = x; }
	void setHeight(float y) { size[1] = y; }

	bool contains(float x, float y);	
};