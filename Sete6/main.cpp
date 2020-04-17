#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>


int main(void)
{
	int largura_t = 680;
	int altura_t = 700;

	al_init();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_DISPLAY *tela = al_create_display(largura_t, altura_t); 
	ALLEGRO_BITMAP *foto = al_load_bitmap("images/1.jpg");
	ALLEGRO_FONT *font = al_load_font("fonts/orbitron-black.ttf", 15, NULL);
	ALLEGRO_COLOR cor_fundo = al_map_rgb(0, 0, 0);

	al_clear_to_color(cor_fundo);
	al_set_window_title(tela, "Imagens com legenda");
	al_set_window_position(tela, 0, 0);
	//al_set_display_flag(tela, ALLEGRO_FULLSCREEN_WINDOW, 1);


	float image_height = al_get_bitmap_height(foto);
	float image_width = al_get_bitmap_width(foto);
	float new_image_height = image_height - 140;
	float new_image_width = image_width - 120;

	al_draw_scaled_bitmap(foto, 10, 0, image_width, image_height, 10, 0, new_image_width, new_image_height, NULL);
	al_flip_display();
	al_rest(1.0);

	al_draw_text(font, al_map_rgb(0, 0, 255), 20, new_image_height + 10, NULL, "Alexandre Cardoso");
	al_flip_display();
	al_rest(1.0);

	al_draw_scaled_bitmap(foto, 10, 0, image_width, image_height, image_width - 90, 0, new_image_width, new_image_height, NULL);
	al_flip_display();
	al_rest(1.0);

	al_draw_text(font, al_map_rgb(0, 255, 0), new_image_width + 35, new_image_height + 10, NULL, "Alexandre Cardoso");
	al_flip_display();
	al_rest(1.0);

	al_draw_scaled_bitmap(foto, 10, 0, image_width, image_height, image_width  + 130, 0, new_image_width, new_image_height, NULL);
	al_flip_display();
	al_rest(1.0);

	al_draw_text(font, al_map_rgb(250, 255, 0), (new_image_width * 2) + 70, new_image_height + 10, NULL, "Alexandre Cardoso");
	al_flip_display();
	al_rest(1.0);
	
	al_draw_scaled_bitmap(foto, 10, 0, image_width, image_height, 10, new_image_height + 30, new_image_width, new_image_height, NULL);
	al_flip_display();
	al_rest(1.0);

	al_draw_text(font, al_map_rgb(255, 0, 255), 20, (new_image_height * 2) + 40, NULL, "Alexandre Cardoso");
	al_flip_display();
	al_rest(1.0);

	al_draw_scaled_bitmap(foto, 10, 0, image_width, image_height, image_width - 90, new_image_height + 30, new_image_width, new_image_height, NULL);
	al_flip_display();
	al_rest(1.0);

	al_draw_text(font, al_map_rgb(255, 255, 255), image_width - 80,(new_image_height * 2) + 40, NULL, "Alexandre Cardoso");
	al_flip_display();
	al_rest(1.0);

	al_draw_scaled_bitmap(foto, 10, 0, image_width, image_height, image_width  + 130, new_image_height + 30, new_image_width, new_image_height, NULL);
	al_flip_display();
	al_rest(1.0);

	al_draw_text(font, al_map_rgb(255, 0, 0), image_width + 150,(new_image_height * 2) + 40, NULL, "Alexandre Cardoso");
	al_flip_display();
	al_rest(6.0);

	al_destroy_bitmap(foto);
	al_destroy_display(tela);
	al_destroy_font(font);
}

