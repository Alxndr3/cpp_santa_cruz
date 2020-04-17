#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

//int draw_line(int x, int y, int p)
//{
//	ALLEGRO_COLOR color_dot_black = al_map_rgb(0, 0, 0);
//	int coord_x = x;
//	int coord_y = y;
//	int pixel = p;
//	for(int i = 0; i < pixel; i++)
//	{
//		al_draw_pixel(coord_x, 670, color_dot_black);
//		al_rest(0.4);
//		al_flip_display();
//		x += 5;
//		//y += 5;
//		return 0;
//	}
//}

int main()
{
	int screen_width = 900;
	int screen_height = 680;
	
	al_init();
	al_init_primitives_addon();

	ALLEGRO_COLOR color_dot_red = al_map_rgb(255, 0, 0);
	ALLEGRO_COLOR color_dot_blue = al_map_rgb(0, 0, 255);
	ALLEGRO_COLOR color_dot_black = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR color_background = al_map_rgb(255, 255, 255);

	al_set_new_display_flags(ALLEGRO_WINDOWED);
	al_set_new_display_flags(ALLEGRO_RESIZABLE);
	ALLEGRO_DISPLAY *display = al_create_display(screen_width, screen_height);
	al_set_window_position(display, 130, 100);
	al_set_window_title(display, "Alexandre Evolution");
	al_clear_to_color(color_background);
	
	// Do Walls
	int coord_x = 200;
	int coord_y = 670;
	int pixel_times = 41;
	for(int i = 0; i < pixel_times; i++)
	{
		al_draw_pixel(coord_x, 670, color_dot_black);
		al_rest(0.02);
		al_flip_display();
		al_draw_pixel(200, coord_y, color_dot_black);
		al_rest(0.02);
		al_flip_display();
		al_draw_pixel(600, coord_y, color_dot_black);
		al_rest(0.02);
		al_flip_display();
		coord_x += 10;
		coord_y -= 10;
	}

	// Do window
	coord_x = 400;
	coord_y = 600;
	pixel_times = 12;
	for(int i = 0; i < pixel_times; i++)
	{
		al_draw_pixel(coord_x, 467, color_dot_blue);
		al_rest(0.02);
		al_flip_display();
		al_draw_pixel(coord_x, 595, color_dot_blue);
		al_rest(0.02);
		al_flip_display();
		al_draw_pixel(510, coord_y - 15, color_dot_blue);
		al_rest(0.02);
		al_flip_display();
		al_draw_pixel(400, coord_y - 15, color_dot_blue);
		al_rest(0.02);
		al_flip_display();
		coord_x += 10;
		coord_y -= 10;
	}

	// Draw door
	coord_x = 200;
	coord_y = 670;
	pixel_times = 20;
	for(int i = 0; i < pixel_times; i++)
	{
		al_draw_pixel(215, coord_y, color_dot_red);
		al_rest(0.02);
		al_flip_display();
		al_draw_pixel(350, coord_y, color_dot_red);
		al_rest(0.02);
		al_flip_display();
		coord_x += 10;
		coord_y -= 10;
		if(i <= 13)
		{
			al_draw_pixel(coord_x + 10, 467, color_dot_red);
			al_rest(0.02);
			al_flip_display();
		}
	}

	// Draw ceiling
	int i = 0;
	coord_x = 165;
	while(i < 50) {
		al_draw_pixel(coord_x, 270, color_dot_black);
		al_rest(0.02);
		al_flip_display();
		coord_x += 10;
		i++;
	}

	// Draw rooftop left
	coord_x = 165;
	coord_y = 270;
	for(int i = 0; i < 25; i++)
	{
		al_draw_pixel(coord_x, coord_y, color_dot_black);
		al_rest(0.02);
		al_flip_display();
		coord_x += 10;
		coord_y -= 10;
	}

	// Draw rooftop right
	coord_x = 165;
	coord_y = 270;
	for(int i = 0; i < 26; i++)
	{
		al_draw_pixel(coord_x + 500, coord_y, color_dot_black);
		al_rest(0.02);
		al_flip_display();
		coord_x -= 10;
		coord_y -= 10;
	}

	al_draw_circle(80, 80, 60, color_dot_black, 0.4);
	al_flip_display();

	al_rest(5);

	al_destroy_display(display);
}
