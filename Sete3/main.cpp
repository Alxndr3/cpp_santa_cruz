#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

int main(void)
{
	ALLEGRO_DISPLAY *tela = NULL;	
	al_init();
	ALLEGRO_COLOR cor_fundo = al_map_rgb(255, 255, 255);
	tela = al_create_display(830, 620);
	al_clear_to_color(cor_fundo);
	al_init_image_addon();
	ALLEGRO_BITMAP *foto = al_load_bitmap("1.jpg");
	al_draw_bitmap(foto, 10, 10, NULL);
	al_flip_display();
	al_rest(6.0);
	al_destroy_bitmap(foto);
	al_destroy_display(tela);
	return 0;
}
