#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>


int main()
{
	const int largura_t = 640; // Variáveis do jogo
	const int altura_t = 480;

	ALLEGRO_DISPLAY *display;

	al_init(); // Inicialização da biblioteca Allegro
	display = al_create_display(largura_t, altura_t); // Criação da tela

	al_init_font_addon(); // Inicialização dos addons
	al_init_ttf_addon();

	ALLEGRO_FONT *fonteTitulo20 = al_load_font("orbitron-black.ttf", 20, 0); // Font loading
	ALLEGRO_FONT *fonteNormal15 = al_load_font("arial.ttf", 15, 0);

	// Função de Desenho
	// Os pontos X e Y são os ancoras do alinhamento dado pelos Flags
	al_draw_text(fonteTitulo20, al_map_rgb(0, 255, 0), 10, 10, ALLEGRO_ALIGN_LEFT, "Teste com o comando al_draw_textf(...)");

	int pixelsX = al_get_display_width(display);
	int pixelsY = al_get_display_height(display);

	
	al_draw_textf(fonteNormal15, al_map_rgb(255, 0, 0), 50, 50, NULL, "Integers: %i %u ", pixelsX, pixelsY);
	al_draw_textf(fonteNormal15, al_map_rgb(255, 0, 0), 50, 70, NULL, "Characters %c %c ", 'z', 80);
	al_draw_textf(fonteNormal15, al_map_rgb(255, 0, 0), 50, 90, NULL, "Decimals %d %ld", 1997, 32000L);
	al_draw_textf(fonteNormal15, al_map_rgb(255, 0, 0), 50, 110, NULL, "O número %d em algumas bases dif. Hexa: %x - Octal: %o", 100, 100, 100);
	al_draw_textf(fonteNormal15, al_map_rgb(255, 0, 0), 50, 130, NULL, "Floats: %4.2f %+.0e %E", 3.14159, 3.14159, 3.14159);
	al_draw_textf(fonteNormal15, al_map_rgb(255, 0, 0), 50, 150, NULL, "Preceder com espaços em branco: %10d", 2020);
	al_draw_textf(fonteNormal15, al_map_rgb(255, 0, 0), 50, 170, NULL, "Preceder com zeros: %010d", 2020);
	al_draw_textf(fonteNormal15, al_map_rgb(255, 0, 0), 50, 190, NULL, "Largura: %*d", 15, 140);
	al_draw_textf(fonteNormal15, al_map_rgb(255, 0, 0), 50, 210, NULL, "Texto: %s", "Educative");

	al_flip_display();
	al_rest(10.0);

	al_destroy_font(fonteNormal15);
	al_destroy_font(fonteTitulo20);
	al_destroy_display(display);
}
