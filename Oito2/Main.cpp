#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

int main()
{
	int width_screen = 640;
	int height_screen = 480;

	al_init();
	al_init_primitives_addon();
	ALLEGRO_COLOR  cor_ponto = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR  cor_fundo = al_map_rgb(0, 255, 0);

	al_set_new_display_flags(ALLEGRO_WINDOWED);
	al_set_new_display_flags(ALLEGRO_RESIZABLE);
	ALLEGRO_DISPLAY *display = al_create_display(width_screen, height_screen);
	al_set_window_position(display, 200, 100);
	al_set_window_title(display, "Alexandre Evolution");
	al_clear_to_color(cor_fundo);

	int X = 10;
	int Y = 10;
	int pixel = 9;
	for(int i = 0; i < pixel; i++)
	{
		al_draw_pixel(X, 10, cor_ponto);
		al_rest(0.4);
		al_flip_display();
		al_draw_pixel(10, Y, cor_ponto);
		al_rest(0.4);
		al_flip_display();
		X += 10;
		Y += 10;
	}

	al_rest(5);
	al_destroy_display(display);
}
