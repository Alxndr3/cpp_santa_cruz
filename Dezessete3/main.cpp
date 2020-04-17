#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>

void desenha_nave(int altura_tela) {
	int x = 40;
	int y = altura_tela / 2;
	// Turbinas da nave
	al_draw_filled_rectangle(x, y - 9, x + 10, y - 7, al_map_rgb(255, 0, 0));
	al_draw_filled_rectangle(x, y + 9, x + 10, y + 7, al_map_rgb(255, 0, 0));
	// Corpo da nave
	al_draw_filled_triangle(x - 12, y - 17, x + 12, y, x - 12, y + 17, al_map_rgb(0, 200, 0));
	al_draw_filled_rectangle(x - 12, y - 2, x + 15, y + 2, al_map_rgb(0, 200, 0));

}

void desenha_retangulo(int p1x, int p2x, int p3x, int p4x, ALLEGRO_COLOR cor, int expessura) {
	if(expessura == 0) {
		al_draw_filled_rectangle(p1x, p2x, p3x, p4x, cor);
	}
	else {
		al_draw_rectangle(p1x, p2x, p3x, p4x, cor, expessura);
	}
}

int main() {
	int tela_largura = 800;
	int tela_altura = 600;

	ALLEGRO_DISPLAY *tela = NULL;
	al_init();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();

	// Variáveis que definem a fonte a ser utilizada no projeto
	ALLEGRO_FONT *font1;
	// A fonte arial.ttf deve estar no mesmo diretório que o arquivo main.cpp
	font1 = al_load_font("arial.ttf", 30, 0);
	ALLEGRO_COLOR cor_fundo = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR cor_retangulo1 = al_map_rgb(0, 0, 255);
	ALLEGRO_COLOR cor_retangulo2 = al_map_rgb(0, 255, 0);
	ALLEGRO_COLOR cor_font = al_map_rgb(255, 0, 0);

	tela = al_create_display(tela_largura, tela_altura);

	for(int x = 0; x <= 200; x++) {
		al_clear_to_color(cor_fundo);
		desenha_nave(tela_altura);
		desenha_retangulo(10 + x, 60, 50 + x, 10, cor_retangulo1, 1);
		desenha_retangulo(60, 20 + x, 80, 60 + x, cor_retangulo2, 0);
		al_draw_textf(font1, cor_font, 250 -x, 250 - x, ALLEGRO_ALIGN_LEFT, "Teste %d", x);
		char text1[15] = "Bom dia!!!";
		char text2[15] = "Boa noite!!!";
		if(x < 100) {
			al_draw_textf(font1, cor_font, 500 - x * 2, 10 + x * 2, ALLEGRO_ALIGN_LEFT, "%s %d", text1, x * 10);
		}
		else {
			al_draw_textf(font1, cor_font, 500 - x * 2, 10 + x * 2, ALLEGRO_ALIGN_LEFT, "%s %d", text2, x * 10);
		}
		al_flip_display();
		al_rest(0.01);
	}
	al_rest(3.0);
	al_destroy_display(tela);
	return 0;
}
