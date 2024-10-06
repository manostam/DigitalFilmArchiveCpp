#include "flowmaster.h"
#include "graphics.h"
#include "config.h"
#include "button.h"
#include "window.h"


FlowMaster* FlowMaster::m_instance = nullptr; // initialization

// returns the unique instance of FlowMaster class or creates it if it has not been created
FlowMaster* FlowMaster::getInstance()
{
	if (!m_instance)
		m_instance = new FlowMaster();
	return m_instance;
}



void FlowMaster::updateStartScreen()
{
	//Press enter or click anywhere to enter the gallery
	if (graphics::getKeyState(graphics::SCANCODE_RETURN))
	{
		FlowMaster::getInstance()->status = GALLERY;
	}

	graphics::MouseState ms;
	graphics::getMouseState(ms);
	if (ms.button_left_pressed)
	{
		FlowMaster::getInstance()->status = GALLERY;
	}

}

void FlowMaster::updateGalleryScreen()
{	
	// ---------------------------------------- SEARCH BUTTON ----------------------------------------
	// button creation	
	button = new Button();

	// update button
	if (button)
		button->update();

	// Set button location and size
	button->setWidth(25);
	button->setHeight(25);
	button->setPosX(CANVAS_WIDTH / 2);
	button->setPosY(30);

	graphics::MouseState ms;
	graphics::getMouseState(ms);

	// converting the window coordinates to canvas coordinates
	float mx = graphics::windowToCanvasX(ms.cur_pos_x);
	float my = graphics::windowToCanvasY(ms.cur_pos_y);

	// Click the button to enter the search screen
	if (button->contains(mx, my) && ms.button_left_pressed)
	{
		FlowMaster::getInstance()->status = SEARCH;
	}

	// ---------------------------------------- MOVIE LINKERS ----------------------------------------
	// Movie linker buttons (that appear after searching). If you click on a movie image it takes you to its description page.
	if (kb1)	// if the Kill Bill 1 has been found during the search and thus its bool "kb1" turned true -> a linker should be made to take us to its info
	{
		buttonkb1 = new Button();

		buttonkb1->setWidth(85);
		buttonkb1->setHeight(85);
		buttonkb1->setPosX(CANVAS_WIDTH * 10 / 100);
		buttonkb1->setPosY(CANVAS_HEIGHT * 80 / 100);

		if (buttonkb1->contains(mx, my) && ms.button_left_pressed)
		{
			FlowMaster::getInstance()->status = KB1;
		}

		delete buttonkb1;		// not needed anymore, releasing memory
	}
	if (kb2)
	{
		buttonkb2 = new Button();

		buttonkb2->setWidth(85);
		buttonkb2->setHeight(85);
		buttonkb2->setPosX(CANVAS_WIDTH * 20 / 100);
		buttonkb2->setPosY(CANVAS_HEIGHT * 80 / 100);

		if (buttonkb2->contains(mx, my) && ms.button_left_pressed)
		{
			FlowMaster::getInstance()->status = KB2;
		}

		delete buttonkb2;
	}
	if (pf)
	{
		buttonpf = new Button();

		buttonpf->setWidth(85);
		buttonpf->setHeight(85);
		buttonpf->setPosX(CANVAS_WIDTH * 30 / 100);
		buttonpf->setPosY(CANVAS_HEIGHT * 80 / 100);

		if (buttonpf->contains(mx, my) && ms.button_left_pressed)
		{
			FlowMaster::getInstance()->status = PF;
		}

		delete buttonpf;
	}
	if (rd)
	{
		buttonrd = new Button();

		buttonrd->setWidth(85);
		buttonrd->setHeight(85);
		buttonrd->setPosX(CANVAS_WIDTH * 40 / 100);
		buttonrd->setPosY(CANVAS_HEIGHT * 80 / 100);

		if (buttonrd->contains(mx, my) && ms.button_left_pressed)
		{
			FlowMaster::getInstance()->status = RD;
		}

		delete buttonrd;
	}
	if (du)
	{
		buttondu = new Button();

		buttondu->setWidth(85);
		buttondu->setHeight(85);
		buttondu->setPosX(CANVAS_WIDTH * 50 / 100);
		buttondu->setPosY(CANVAS_HEIGHT * 80 / 100);

		if (buttondu->contains(mx, my) && ms.button_left_pressed)
		{
			FlowMaster::getInstance()->status = DU;
		}

		delete buttondu;
	}
	if (jb)
	{
		buttonjb = new Button();

		buttonjb->setWidth(85);
		buttonjb->setHeight(85);
		buttonjb->setPosX(CANVAS_WIDTH * 60 / 100);
		buttonjb->setPosY(CANVAS_HEIGHT * 80 / 100);

		if (buttonjb->contains(mx, my) && ms.button_left_pressed)
		{
			FlowMaster::getInstance()->status = JB;
		}

		delete buttonjb;
	}
	if (ib)
	{
		buttonib = new Button();

		buttonib->setWidth(85);
		buttonib->setHeight(85);
		buttonib->setPosX(CANVAS_WIDTH * 70 / 100);
		buttonib->setPosY(CANVAS_HEIGHT * 80 / 100);

		if (buttonib->contains(mx, my) && ms.button_left_pressed)
		{
			FlowMaster::getInstance()->status = IB;
		}

		delete buttonib;
	}
	if (ouatih)
	{
		buttonouatih = new Button();

		buttonouatih->setWidth(85);
		buttonouatih->setHeight(85);
		buttonouatih->setPosX(CANVAS_WIDTH * 80 / 100);
		buttonouatih->setPosY(CANVAS_HEIGHT * 80 / 100);

		if (buttonouatih->contains(mx, my) && ms.button_left_pressed)
		{
			FlowMaster::getInstance()->status = OUATIH;
		}

		delete buttonouatih;
	}
	if (the)
	{
		buttonthe = new Button();

		buttonthe->setWidth(85);
		buttonthe->setHeight(85);
		buttonthe->setPosX(CANVAS_WIDTH * 90 / 100);
		buttonthe->setPosY(CANVAS_HEIGHT * 80 / 100);

		if (buttonthe->contains(mx, my) && ms.button_left_pressed)
		{
			FlowMaster::getInstance()->status = THE;
		}

		delete buttonthe;
	}
}

void FlowMaster::updateMovieScreen()
{	
	// Return from a movie description page to the gallery with enter or left mouse click
	if (graphics::getKeyState(graphics::SCANCODE_RETURN))
	{
		FlowMaster::getInstance()->status = GALLERY;
	}

	graphics::MouseState ms;
	graphics::getMouseState(ms);
	if (ms.button_left_pressed)
	{
		FlowMaster::getInstance()->status = GALLERY;
	}
}

void FlowMaster::updateSearchScreen()
{	
	
	//Minimum Year "plus" button
	button2 = new Button;
	button2->setWidth(10);
	button2->setHeight(10);
	button2->setPosX(CANVAS_WIDTH * 50 / 100);
	button2->setPosY(CANVAS_HEIGHT * 20 / 100);

	//Minimum Year "minus" button
	button3 = new Button;
	button3->setWidth(10);
	button3->setHeight(10);
	button3->setPosX(CANVAS_WIDTH * 50 / 100 - 12);
	button3->setPosY(CANVAS_HEIGHT * 20 / 100);

	//Maximum Year "plus" button
	button4 = new Button;
	button4->setWidth(10);
	button4->setHeight(10);
	button4->setPosX(CANVAS_WIDTH * 50 / 100 + 122);
	button4->setPosY(CANVAS_HEIGHT * 20 / 100);

	//Maximum Year "minus" button
	button5 = new Button;
	button5->setWidth(10);
	button5->setHeight(10);
	button5->setPosX(CANVAS_WIDTH * 50 / 100 + 110);
	button5->setPosY(CANVAS_HEIGHT * 20 / 100);

	//A button to search by genre
	genreSearch = new Button;
	genreSearch->setWidth(14);
	genreSearch->setHeight(12);
	genreSearch->setPosX(CANVAS_WIDTH * 50 / 100);
	genreSearch->setPosY(CANVAS_HEIGHT * 30 / 100);

	//Button to start searching
	confirmButton = new Button;
	confirmButton->setWidth(14);
	confirmButton->setHeight(14);
	confirmButton->setPosX(CANVAS_WIDTH * 80 / 100);
	confirmButton->setPosY(CANVAS_HEIGHT * 30 / 100);

	graphics::MouseState ms;
	graphics::getMouseState(ms);
	float mx = graphics::windowToCanvasX(ms.cur_pos_x);
	float my = graphics::windowToCanvasY(ms.cur_pos_y);

	//Functionality for search buttons
	if (button2->contains(mx, my) && ms.button_left_pressed && minYear < YEAR_MAX)
	{
		minYear++;
	}
	delete button2;

	if (button3->contains(mx, my) && ms.button_left_pressed && minYear > YEAR_MIN)
	{
		minYear--;
	}
	delete button3;

	if (button4->contains(mx, my) && ms.button_left_pressed && maxYear < YEAR_MAX)
	{
		maxYear++;
	}
	delete button4;

	if (button5->contains(mx, my) && ms.button_left_pressed && maxYear > YEAR_MIN)
	{
		maxYear--;
	}
	delete button5;

	if (genreSearch->contains(mx, my) && ms.button_left_pressed && i < 4)
	{
		i++;
		genre = genres[i];
	}
	else if (genreSearch->contains(mx, my) && ms.button_left_pressed)
	{
		i = 0;
		genre = genres[i];
	}
	delete genreSearch;

	//Return from search screen to gallery
	if (graphics::getKeyState(graphics::SCANCODE_RETURN))
	{
		FlowMaster::getInstance()->status = GALLERY;		// if no search has happened it returns to plain gallery, after the first search serves as an another method of confirming the search by the chosen criteria
	}

	if (confirmButton->contains(mx, my) && ms.button_left_pressed)
	{
		FlowMaster::getInstance()->status = GALLERY;
		drawMovies = 1;
	}
	delete confirmButton;
}

void FlowMaster::drawStartScreen()
{
	//Draws the background of the start screen
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	br.texture = std::string(ASSET_PATH) + "startscreen.png";
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

	SETCOLOR(br.fill_color, 0.8f, 0.8f, 0.8f);
	char info[40];
	sprintf_s(info, "Welcome, please press enter");
	graphics::drawText(CANVAS_WIDTH * 35 / 100, CANVAS_HEIGHT * 50 / 100, 20, info, br);

	// appearance of the mouse, getting the mouse movement and painting its corresponding as a disk in the gallery window
	graphics::MouseState ms;
	graphics::getMouseState(ms); // getting the instance of the mouse (state) so that we can use its coordinates for the drawing
	graphics::Brush br2;
	SETCOLOR(br2.fill_color, 0.8f, 0.8f, 0.8f);
	graphics::drawDisk(window2canvasX(ms.cur_pos_x), window2canvasY(ms.cur_pos_y), 3, br2); // window2canvas turns the window dimensions to canvas appropriate dimensions


}

// initial gallery screen at which appear the movie results after the search
void FlowMaster::drawGalleryScreen()
{
	graphics::setFont(std::string(ASSET_PATH) + "bitstream-simple.ttf");
	graphics::Brush br1;
	SETCOLOR(br1.fill_color, 0.8f, 0.6f, 0.6f);
	char info1[80];
	sprintf_s(info1, "Search by date of production and/or genre");
	graphics::drawText(CANVAS_WIDTH * 35 / 100, CANVAS_HEIGHT * 12 / 100, 15, info1, br1);

	// drawing the movies that appear after we confirm the search
	if (drawMovies) {
		

		graphics::Brush br;
		br.outline_opacity = 0.0f;

		// show only the movies that satisfy the chosen criteria
		if ( (minYear <= 2003 && maxYear >= 2003) && (genre == genres[0] || genre == genres[1] || genre == genres[2] || genre == genres[4])) {
			br.texture = std::string(ASSET_PATH) + "killbill1.png";
			graphics::drawRect(CANVAS_WIDTH * 10 / 100, CANVAS_HEIGHT * 80 / 100, 85, 128, br);
			kb1 = 1; 
		}
		else { kb1 = 0; }
		
		if ( (minYear <= 2004 && maxYear >= 2004) && (genre == genres[1] || genre == genres[2] || genre == genres[3] || genre == genres[4]) ) {
			br.texture = std::string(ASSET_PATH) + "killbill2.png";
			graphics::drawRect(CANVAS_WIDTH * 20 / 100, CANVAS_HEIGHT * 80 / 100, 85, 128, br);
			kb2 = 1;
		}
		else { kb2 = 0; }
		
		if ( (minYear <= 1994 && maxYear >= 1994) && (genre == genres[0] || genre == genres[2] || genre == genres[4]) ) {
			br.texture = std::string(ASSET_PATH) + "pulp.png";
			graphics::drawRect(CANVAS_WIDTH * 30 / 100, CANVAS_HEIGHT * 80 / 100, 85, 128, br);
			pf = 1;
		}
		else { pf = 0; }
		
		if ( (minYear <= 1992 && maxYear >= 1992) && (genre == genres[2] || genre == genres[3] || genre == genres[4]) ) {
			br.texture = std::string(ASSET_PATH) + "reservoirdogs.png";
			graphics::drawRect(CANVAS_WIDTH * 40 / 100, CANVAS_HEIGHT * 80 / 100, 85, 128, br);
			rd = 1;
		}
		else { rd = 0; }
		
		if ( (minYear <= 2012 && maxYear >= 2012) && (genre == genres[0] || genre == genres[4]) ) {
			br.texture = std::string(ASSET_PATH) + "django.png";
			graphics::drawRect(CANVAS_WIDTH * 50 / 100, CANVAS_HEIGHT * 80 / 100, 85, 128, br);
			du = 1;
		}
		else { du = 0; }
		
		if ( (minYear <= 1997 && maxYear >= 1997) && (genre == genres[0] || genre == genres[2] || genre == genres[3] || genre == genres[4]) ) {
			br.texture = std::string(ASSET_PATH) + "jackiebrown.png";
			graphics::drawRect(CANVAS_WIDTH * 60 / 100, CANVAS_HEIGHT * 80 / 100, 85, 128, br);
			jb = 1;
		}
		else { jb = 0; }
		
		if ( (minYear <= 2009 && maxYear >= 2009) && (genre == genres[0] || genre == genres[4]) ) {
			br.texture = std::string(ASSET_PATH) + "inglourious.png";
			graphics::drawRect(CANVAS_WIDTH * 70 / 100, CANVAS_HEIGHT * 80 / 100, 85, 128, br);
			ib = 1;
		}
		else { ib = 0; }
		
		if ( (minYear <= 2019 && maxYear >= 2019) && (genre == genres[0] || genre == genres[4]) ) {
			br.texture = std::string(ASSET_PATH) + "onceupon.png";
			graphics::drawRect(CANVAS_WIDTH * 80 / 100, CANVAS_HEIGHT * 80 / 100, 85, 128, br);
			ouatih = 1;
		}
		else { ouatih = 0; }
		
		if ( (minYear <= 2015 && maxYear >= 2015) && (genre == genres[0] || genre == genres[2] || genre == genres[4]) ) {
			br.texture = std::string(ASSET_PATH) + "hateful.png";
			graphics::drawRect(CANVAS_WIDTH * 90 / 100, CANVAS_HEIGHT * 80 / 100, 85, 128, br);
			the = 1;
		}
		else { the = 0; }
	}

	// draws the button for searching by date and genre
	if (button)
		button->draw();


	// appearance of the mouse, getting the mouse movement and painting its corresponding as a disk in the gallery window
	graphics::MouseState ms;
	graphics::getMouseState(ms); // getting the instance of the mouse (state) so that we can use its coordinates for the drawing
	graphics::Brush br2;
	SETCOLOR(br2.fill_color, 0.8f, 0.8f, 0.8f);
	graphics::drawDisk(window2canvasX(ms.cur_pos_x), window2canvasY(ms.cur_pos_y), 3, br2); // window2canvas turns the window dimensions to canvas appropriate dimensions

}

void FlowMaster::drawMovieScreen()
{
	//Draws the movie description screens according to prior search
	if (FlowMaster::getInstance()->status == KB1)
	{
		Window w1;
		w1.draw("killbill1.png", "killbill1info.txt");
	}
	if (FlowMaster::getInstance()->status == KB2)
	{
		Window w2;
		w2.draw("killbill2.png", "killbill2.txt");
	}
	if (FlowMaster::getInstance()->status == PF)
	{
		Window w3;
		w3.draw("pulp.png", "pulp.txt");
	}
	if (FlowMaster::getInstance()->status == RD)
	{
		Window w4;
		w4.draw("reservoirdogs.png", "reservoirdogs.txt");
	}
	if (FlowMaster::getInstance()->status == DU)
	{
		Window w5;
		w5.draw("django.png", "django.txt");
	}
	if (FlowMaster::getInstance()->status == JB)
	{
		Window w6;
		w6.draw("jackiebrown.png", "jackiebrown.txt");
	}
	if (FlowMaster::getInstance()->status == IB)
	{
		Window w7;
		w7.draw("inglourious.png", "inglourious.txt");
	}
	if (FlowMaster::getInstance()->status == OUATIH)
	{
		Window w8;
		w8.draw("onceupon.png", "onceupon.txt");
	}
	if (FlowMaster::getInstance()->status == THE)
	{
		Window w9;
		w9.draw("hateful.png", "hateful.txt");
	}

	graphics::Brush brush;
	brush.outline_opacity = 0.0f;
	SETCOLOR(brush.fill_color, 0.8f, 0.2f, 0.2f);
	graphics::drawText(CANVAS_WIDTH * 50 / 100, CANVAS_HEIGHT * 18 / 100, 12, "(Click anywhere or press enter to return)", brush);

	// appearance of the mouse, getting the mouse movement and painting its corresponding as a disk in the gallery window
	graphics::MouseState ms;
	graphics::getMouseState(ms); // getting the instance of the mouse (state) so that we can use its coordinates for the drawing
	graphics::Brush br2;
	SETCOLOR(br2.fill_color, 0.8f, 0.8f, 0.8f);
	graphics::drawDisk(window2canvasX(ms.cur_pos_x), window2canvasY(ms.cur_pos_y), 3, br2); // window2canvas turns the window dimensions to canvas appropriate dimensions

}

void FlowMaster::drawSearchScreen()
{
	// black box on which we will design the search buttons
	graphics::Brush br;
	SETCOLOR(br.fill_color, 0.1f, 0.1f, 0.1f);
	graphics::drawRect(CANVAS_WIDTH * 67 / 100, CANVAS_HEIGHT * 25 / 100, CANVAS_WIDTH * 45 / 100, CANVAS_HEIGHT * 40 / 100, br);

	// get the min and max year (as strings) as set in flowmaster.h -> config.h
	std::string min = std::to_string(minYear);
	std::string max = std::to_string(maxYear);

	graphics::Brush brush;
	brush.outline_opacity = 0.0f;
	SETCOLOR(brush.fill_color, 0.8f, 0.2f, 0.2f);	
	graphics::setFont(std::string(ASSET_PATH) + "bitstream-simple.ttf");
	// Year texts
	graphics::drawText(CANVAS_WIDTH * 47 / 100, CANVAS_HEIGHT * 16.5 / 100, 14, "Please, select year range :", brush);
	graphics::drawText(CANVAS_WIDTH * 50 / 100 + 15, CANVAS_HEIGHT * 21.5 / 100, 18, min, brush);
	graphics::drawText(CANVAS_WIDTH * 50 / 100 + 60, CANVAS_HEIGHT * 21.5 / 100, 18, max, brush);
	
	//Genre texts and one of the genres ( "genre" )
	graphics::drawText(CANVAS_WIDTH * 47 / 100, CANVAS_HEIGHT * 26.5 / 100, 14, "Please, select genre :", brush);
	graphics::drawText(CANVAS_WIDTH * 50 / 100 + 20, CANVAS_HEIGHT * 31.5 / 100, 18, genre, brush);

	// get the mouse coordinates (to canvas coordinates) to check if the "Confirm Seach?" should appear
	graphics::MouseState ms;
	graphics::getMouseState(ms);
	float mx = graphics::windowToCanvasX(ms.cur_pos_x);
	float my = graphics::windowToCanvasY(ms.cur_pos_y);

	//Draws the search screen buttons
	// draws the question for the confirmation of search
	if (confirmButton && confirmButton->contains(mx, my)) {
		graphics::drawText(CANVAS_WIDTH * 74 / 100, CANVAS_HEIGHT * 26.5 / 100, 16, "Confirm Search?", brush);
	}

	// draw + -
	if (button2) {
		button2->draw(button2->getPosX(), button2->getPosY(), button2->getWidth(), button2->getHeight(), "plus.png");
	}
	if (button3) {
		button3->draw(button3->getPosX(), button3->getPosY(), button3->getWidth(), button3->getHeight(), "minus.png");
	}
	if (button4) {
		button4->draw(button4->getPosX(), button4->getPosY(), button4->getWidth(), button4->getHeight(), "plus.png");
	}
	if (button5) {
		button5->draw(button5->getPosX(), button5->getPosY(), button5->getWidth(), button5->getHeight(), "minus.png");
	}

	// draw ->
	if (genreSearch) {
		genreSearch->draw(genreSearch->getPosX(), genreSearch->getPosY(), genreSearch->getWidth(), genreSearch->getHeight(), "point.png");
	}

	// draw (tick) for confirm
	if (confirmButton) {
		confirmButton->draw(confirmButton->getPosX(), confirmButton->getPosY(), confirmButton->getWidth(), confirmButton->getHeight(), "confirm.png");
	}

	// appearance of the mouse, getting the mouse movement and painting its corresponding as a disk in the gallery window
	graphics::MouseState ms1;
	graphics::getMouseState(ms1); // getting the instance of the mouse (state) so that we can use its coordinates for the drawing
	graphics::Brush br2;
	SETCOLOR(br2.fill_color, 0.8f, 0.8f, 0.8f);
	graphics::drawDisk(window2canvasX(ms1.cur_pos_x), window2canvasY(ms1.cur_pos_y), 3, br2); // window2canvas turns the window dimensions to canvas appropriate dimensions

}


void FlowMaster::backgroundMusic()
{
	// adding some music to the background
	graphics::playMusic(std::string(ASSET_PATH) + "retro.mp3", 0.05f, true, 1000);
}

void FlowMaster::init()
{
	
}

// returns the unit x of window (the window width) to the corresponding canvas width
float FlowMaster::window2canvasX(float x)
{
	return x * CANVAS_WIDTH / (float)window_width;
}

// returns the unit y of window (the window height) to the corresponding canvas height
float FlowMaster::window2canvasY(float y)
{
	return y * CANVAS_HEIGHT / (float)window_height;
}



void FlowMaster::update()
{
	//Update control	
	if (FlowMaster::getInstance()->status == STATUS_START)
	{
		updateStartScreen();
	}
	else if (FlowMaster::getInstance()->status == GALLERY)
	{
		updateGalleryScreen();
	}
	else if (FlowMaster::getInstance()->status == SEARCH)
	{
		updateSearchScreen();
	}
	else
	{
		updateMovieScreen();
	}

}



void FlowMaster::draw()
{
	// setting up the background
	Window w;
	w.draw("background.png");
	
	// Draw control
	if (FlowMaster::getInstance()->status == STATUS_START)
	{
		
		drawStartScreen();
	}
	else if (FlowMaster::getInstance()->status == GALLERY)
	{
		drawGalleryScreen();
	}
	else if (FlowMaster::getInstance()->status == SEARCH)
	{
		drawSearchScreen();
	}
	else
	{
		drawMovieScreen();
	}
}