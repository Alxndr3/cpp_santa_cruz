#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>


int main(void)
{
	int largura_t = 800;
	int altura_t = 600;

	al_init();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_DISPLAY *tela = al_create_display(largura_t, altura_t);
	ALLEGRO_BITMAP *foto = al_load_bitmap("images/1.jpg");
	ALLEGRO_FONT *font = al_load_font("fonts/orbitron-black.ttf", 30, NULL);
	ALLEGRO_COLOR cor_fundo = al_map_rgb(0, 0, 0);

	al_clear_to_color(cor_fundo);

	float image_height = al_get_bitmap_height(foto);
	float image_width = al_get_bitmap_width(foto);

	al_draw_bitmap(foto, 10, 75, NULL); // Desenhar images
	al_draw_bitmap(foto, 10 + image_width  + 10 , 75, NULL);
	al_draw_bitmap(foto, 10 + image_width + image_width + 10 + 10, 75, NULL);

	al_draw_text(font, al_map_rgb(0, 0, 255), 10, 40, NULL, "IMAGENS");
	al_draw_text(font, al_map_rgb(0, 255, 0), 10, image_height + 75 + 10, NULL, "foto 1");
	al_draw_text(font, al_map_rgb(0, 255, 255), 10 + image_width + 10, image_height + 75 + 10, NULL, "foto 2");
	al_draw_text(font, al_map_rgb(255, 0, 255), 10 + image_width + 10 + image_width + 10, image_height + 75 + 10, NULL, "foto 3");
	
	al_flip_display();
	al_rest(5.0);

	al_destroy_bitmap(foto);
	al_destroy_display(tela);
	al_destroy_font(font);


}










