#include "window.h"
#include "graphics.h"
#include "config.h"
#include "movie.h"



void Window::update()
{

}


void Window::draw()
{
	
}

// drawing up the background window
void Window::draw(std::string backgoundTexture)
{

	graphics::Brush br;
	br.outline_opacity = 0.0f;
	br.texture = ASSET_PATH + std::string(backgoundTexture);
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);
}

// drawing up the movie window
void Window::draw(std::string movieImageName, std::string movieInfoName)
{
	// drawing a plain filled black box to set the contrast for the info that will be written as below (on the right side)
	graphics::Brush brush;
	SETCOLOR(brush.fill_color, 0.1f, 0.1f, 0.1f);
	graphics::drawRect(CANVAS_WIDTH * 67 / 100, CANVAS_HEIGHT * 50 / 100, CANVAS_WIDTH * 65 / 100, CANVAS_HEIGHT * 80 / 100, brush);
	SETCOLOR(brush.fill_color, 0.8f, 0.2f, 0.2f);
	graphics::drawText(CANVAS_WIDTH * 55 / 100, CANVAS_HEIGHT * 15 / 100, 20, "Movie Details !!!", brush);
	graphics::drawText(CANVAS_WIDTH * 35 / 100, CANVAS_HEIGHT * 25 / 100, 20, "Title:", brush);
	graphics::drawText(CANVAS_WIDTH * 35 / 100, CANVAS_HEIGHT * 35 / 100, 20, "Director:", brush);
	graphics::drawText(CANVAS_WIDTH * 35 / 100, CANVAS_HEIGHT * 45 / 100, 20, "Date of production:", brush);
	graphics::drawText(CANVAS_WIDTH * 35 / 100, CANVAS_HEIGHT * 55 / 100, 20, "Starring actors:", brush);
	graphics::drawText(CANVAS_WIDTH * 35 / 100, CANVAS_HEIGHT * 65 / 100, 20, "Filme genres:", brush);
	graphics::drawText(CANVAS_WIDTH * 35 / 100, CANVAS_HEIGHT * 75 / 100, 20, "Short description:", brush);

	// drawing the movie image on the left side
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	br.texture = std::string(ASSET_PATH) + movieImageName;
	graphics::drawRect(CANVAS_WIDTH * 10 / 100, CANVAS_HEIGHT * 45 / 100, 1.5 * 85, 1.5 * 128, br);

	// movie details
	SETCOLOR(br.fill_color, 0.8f, 0.8f, 0.8f);
	graphics::setFont(std::string(ASSET_PATH) + "bitstream-simple.ttf");
	Movie m;
	std::string* movieInfo = m.getMovieInfo(movieInfoName);
	graphics::drawText(CANVAS_WIDTH * 55 / 100, CANVAS_HEIGHT * 25 / 100, 15, movieInfo[0], br);
	graphics::drawText(CANVAS_WIDTH * 55 / 100, CANVAS_HEIGHT * 35 / 100, 15, movieInfo[1], br);
	graphics::drawText(CANVAS_WIDTH * 55 / 100, CANVAS_HEIGHT * 45 / 100, 15, movieInfo[2], br);
	graphics::drawText(CANVAS_WIDTH * 55 / 100, CANVAS_HEIGHT * 55 / 100, 15, movieInfo[3], br);
	graphics::drawText(CANVAS_WIDTH * 55 / 100, CANVAS_HEIGHT * 65 / 100, 15, movieInfo[4], br);
	graphics::drawText(CANVAS_WIDTH * 55 / 100, CANVAS_HEIGHT * 75 / 100, 12, movieInfo[5], br);
	graphics::drawText(CANVAS_WIDTH * 55 / 100, CANVAS_HEIGHT * 78 / 100, 12, movieInfo[6], br);
	graphics::drawText(CANVAS_WIDTH * 55 / 100, CANVAS_HEIGHT * 81 / 100, 12, movieInfo[7], br);
	graphics::drawText(CANVAS_WIDTH * 55 / 100, CANVAS_HEIGHT * 84 / 100, 12, movieInfo[8], br);
}

void Window::init()
{
}