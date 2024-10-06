#pragma once
#include "widget.h"
#include "graphics.h"

class Window : public Widget // inherits the Widget class
{
	

public:
	void update() override;
	void draw() override;
	void draw(std::string backgoundTexture); // a simple canvas drawing method with the wishing (.png) texture as given argument
	void draw(std::string movieImagePath, std::string movieInfoPath); // drawing of a movie window with its details
	void init() override;

};