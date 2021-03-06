#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <ctime>

void draw_ship() {
	int x = 40;
	int y = 50;
	int r = 255;
	int g = 0;
	int b = 0;
	// Change triangles color
	for(int i = 0; i < 3; i++) {
		if(i == 1) {
			g = 255;
		}
		else if(i == 2) {
			g = 255;
			b = 255;
		}
		// Spaceship turbines
		al_draw_filled_rectangle(x, y - 9, x + 10, y - 7, al_map_rgb(255, 0, 0));
		al_draw_filled_rectangle(x, y + 9, x + 10, y + 7, al_map_rgb(255, 0, 0));
		// Spaceship body
		al_draw_filled_triangle(x - 12, y - 17, x + 12, y, x - 12, y + 17, al_map_rgb(r, g, b));
		al_draw_filled_rectangle(x - 12, y - 2, x + 15, y + 2, al_map_rgb(0, 200, 0));
		al_flip_display();
		y += 230;
	}
}
// Draw stars in the space
void draw_stars(int display_width, int display_heigh) {
	srand(time(NULL));
	// Generate random x and y coordenates and draw a pixel with it.
	for(int i = 0; i < 500; i++) {
		int star_width = rand() % display_width;
		int star_height = rand() % display_heigh;
		al_draw_pixel(star_width, star_height, al_map_rgb(255, 255, 255));
	}
}

void draw_squares(int display_height, int display_width) {
	int y1 = 10;
	int y2 = 30;
	while(y2 <= display_height) {
		al_draw_filled_rectangle(100, y1, 120, y2, al_map_rgb(255, 255, 255));
		al_draw_filled_rectangle(display_width - 120, y1, display_width - 100, y2, al_map_rgb(255, 255, 255));
		y1 += 50;
		y2 += 50;
	}
}

int main() {
	int display_width = 800;
	int display_heigth = 600;

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_COLOR color_bg = al_map_rgb(0, 0, 0);
	al_init();
	al_init_primitives_addon();

	display = al_create_display(display_width, display_heigth);
	al_set_window_position(display, 300, 50);
	al_set_window_title(display, "*** Spaceship Game ***");
	al_clear_to_color(color_bg);
	//draw_squares();
	for(int x = 0; x < 3; x++) {
		draw_squares(display_heigth, display_width);
		draw_ship();
		draw_stars(display_width, display_heigth);
		al_flip_display();
	}

	al_flip_display();
	al_rest(5.0);
	al_destroy_display(display);
}
