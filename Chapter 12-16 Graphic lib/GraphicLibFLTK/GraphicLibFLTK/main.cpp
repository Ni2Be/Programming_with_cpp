#define _USE_MATH_DEFINES
#include <cmath>
#include <stdio.h>
#include <time.h>
#include <chrono>

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>

#define WIN_W 400       // window width
#define WIN_H 400       // window height
#define FPS (1.0/24.0)  // frames per second playback
#define BG_COLOR 45		// grey
#define FG_COLOR 0		// Black

class Crane : public Fl_Box
{
private:
	int R_color_key = 0;
	int G_color_key = 0;
	int B_color_key = 0;
	bool go_back = false;
	void draw() override
	{
		// COMPUTE NEW COORDS OF BALL
		using namespace std::chrono;
		milliseconds ms = duration_cast< milliseconds >(
			system_clock::now().time_since_epoch()
			);
		static long start = ms.count();
		long tick = (ms.count() - start) % 3700;
		int x1 = (int)(tick / 10),
			y1 = (int)(tick / 10),
			x2 = (int)(tick / 10),
			y2 = (int)(tick / 10);

		Fl_Box::draw();
		// DRAW 'SECOND HAND' OVER WIDGET'S BACKGROUND
		fl_color(R_color_key, G_color_key, B_color_key);
		if (R_color_key >= G_color_key && !go_back)
		{
			if (R_color_key == 254)
			{
				if (B_color_key == 254)
				{
					if (G_color_key != 254)
						G_color_key++;
				}
				else
					B_color_key++;
			}
			else
				R_color_key++;
		}
		if (R_color_key <= G_color_key && go_back)
		{
			if (R_color_key == 0)
			{
				if (B_color_key == 0)
				{
					if (G_color_key != 0)
						G_color_key--;
				}
				else
					B_color_key--;
			}
			else
				R_color_key--;
		}
		if ((R_color_key == 254 && G_color_key == 254 && B_color_key == 254)
			|| (R_color_key == 0 && G_color_key == 0 && B_color_key == 0))
			go_back = go_back ^ 1;

		fl_pie(x2 - 10, y2 - 10, y2 / 2, x2 / 2, 0.0, 360.0);


		// DRAW DEBUG
		fl_color(FG_COLOR);
		fl_font(FL_HELVETICA, 16);
		char debug[80]; 
		sprintf(debug, "%02ld:%02ld:%02ld:%02ld:%02ld", tick / 10, R_color_key, G_color_key, B_color_key, go_back);
		fl_draw(debug, x() + 4, y() + h() - 4);
	}
	static void Timer_CB(void *userdata)
	{
		Crane *o = (Crane*)userdata;
		o->redraw();
		Fl::repeat_timeout(FPS, Timer_CB, userdata);
	}
public:
	Crane(int X, int Y, int W, int H, const char*L = 0) : Fl_Box(X, Y, W, H, L)
	{
		box(FL_FLAT_BOX);
		color(BG_COLOR);
		Fl::add_timeout(FPS, Timer_CB, (void*)this);
	}
};


int main()
{
	Fl_Double_Window win(WIN_W, WIN_H);
	Crane crane(10, 10, WIN_W - 20, WIN_H - 20);
	win.show();
	return Fl::run();
}

