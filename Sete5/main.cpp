#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>


int main(void)
{
	int largura_t = 400;
	int altura_t = 550;

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

	al_draw_bitmap(foto, 40, 40, NULL); // Desenhar images
	al_draw_text(font, al_map_rgb(0, 0, 255), 40, 10, NULL, "Alexandre Cardoso");
	al_flip_display();
	al_rest(2.0);
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_draw_bitmap(foto, 40, 40, NULL); // Desenhar images
	al_draw_text(font, al_map_rgb(0, 255, 0), 40, image_height + 65, NULL, "Alexandre Cardoso");
	al_flip_display();
	al_rest(2.0);
	

	al_destroy_bitmap(foto);
	al_destroy_display(tela);
	al_destroy_font(font);
}

