#pragma once
#include "config.h"
#include "button.h"
#include "window.h"


class FlowMaster
{
	static FlowMaster * m_instance;  // static member of class Flowmaster, unique instance of this class that I want to exist, should be initialized in .cpp
	FlowMaster() {};				// closed up the class builder as non public, can't make an instance of this class, will create method to do so
	
	// the window width and height, in order to process them with suitable methods (at the public sector) and set them according to our canvas (so that our mouse movement is followed by its "shadow" on the canvas)
	unsigned int window_width = WINDOW_WIDTH;
	unsigned int window_height = WINDOW_HEIGHT;

	// the status which will be defining which window will be drawed next
	typedef enum { STATUS_START, GALLERY, SEARCH, KEYWORD_SEARCH, CHECKBOX_SEARCH, KB1, KB2, PF, RD, DU, JB, IB, OUATIH, THE } status_t; // KB1=KILL BILL 1, KB2=KILL BILL 2, PF=PULP FICTION, RD=RESERVOIR DOGS, DU=DJANGO UNCHAINED, JB=JACKIE BROWN, IB=INGLOURIOUS BASTERDS, OUATIH=ONCE UPON A TIME IN HOLLYWOOD, THE=THE HATEFUL EIGHT
	status_t status = STATUS_START;
	
	// date of production variables and initialization from 1980 to 2023
	int minYear = YEAR_MIN;
	int maxYear = YEAR_MAX;

	// the basic categories and initialization of the first one in the search bar as "drama"
	std::string genres[5] = { "Drama", "Action", "Crime", "Thriller", "All"};
	int i = 0;
	std::string genre = genres[i];
	// checks if we should draw
	bool drawMovies = 0;

	// the button linkers to the films (active or not active depending the search)
	bool kb1 = 0;
	bool kb2 = 0;
	bool pf = 0;
	bool rd = 0;
	bool du = 0;
	bool jb = 0;
	bool ib = 0;
	bool ouatih = 0;
	bool the = 0;

	// the window methods about drawing and updating
	void updateStartScreen();
	void updateGalleryScreen();
	void updateMovieScreen();
	void updateSearchScreen();
	void drawStartScreen();
	void drawGalleryScreen();
	void drawMovieScreen();
	void drawSearchScreen();


	// Widget inits. // we still need them because we delete the corresponding instances of Button we created, so we need a nullptr at least for some of their use
	Button* button = nullptr;
	Button* button2 = nullptr;
	Button* button3 = nullptr;
	Button* button4 = nullptr;
	Button* button5 = nullptr;
	Button* genreSearch = nullptr;
	Button* confirmButton = nullptr;

	// Movie linker buttons
	Button* buttonkb1 = nullptr;
	Button* buttonkb2 = nullptr;
	Button* buttonpf = nullptr;
	Button* buttonrd = nullptr;
	Button* buttondu = nullptr;
	Button* buttonjb = nullptr;
	Button* buttonib = nullptr;
	Button* buttonouatih = nullptr;
	Button* buttonthe = nullptr;
	


public:
	static FlowMaster * getInstance();
	void backgroundMusic();
	void update();
	void draw();
	void init();
	
	// adjusting the window width, height - synchronizing them with the canvas size
	unsigned int getWindowWidth() { return window_width; }
	unsigned int getWindowHeight() { return window_height; }
	void setWindowDimensions(unsigned int w, unsigned int h) { window_width = w; window_height = h; }
	float window2canvasX(float x);
	float window2canvasY(float y);	
	
};
