#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>

void move_bola(float px, float py, float raio, ALLEGRO_COLOR cor_fundo, ALLEGRO_COLOR cor_bola,
		int v, int dir_x, int dir_y, int flag) {
	if(flag == 0) {
		al_draw_filled_circle(px, py, raio, cor_bola);
	}
	else {
		al_draw_circle(px, py, raio, cor_bola, flag);
		al_flip_display();
		al_rest(0.05);
		al_clear_to_color(cor_fundo);
	}
}

int main() {
	int largura_tela = 800;
	int altura_tela = 600;
	float velocidade_bola = 1;

	ALLEGRO_DISPLAY *tela = NULL;
	al_init();
	al_init_primitives_addon();
	ALLEGRO_COLOR cor_fundo = al_map_rgb(0, 0, 0);
	al_set_new_display_flags(ALLEGRO_WINDOWED);
	tela = al_create_display(largura_tela, altura_tela);
	ALLEGRO_COLOR cor_bola = al_map_rgb(0, 100, 0);

	int k = 0;
	int dx = 1;
	int dy = 1;
	int x = largura_tela / 2;
	int y = altura_tela / 2;
	int raio = 30;

	while(k < 1000) {
		k++;
		move_bola(x, y, raio, cor_fundo, cor_bola, velocidade_bola, dx, dy, 1);
		x += velocidade_bola * dx;
		y += velocidade_bola * dy;

		if(x >= largura_tela - raio) {
			dx = -1;
			x = raio;
		}
		else if(x <= raio) {
			dx = 1;
			x = raio;
		}
		if(y >= altura_tela - raio) {
			dy = -1;
			y = altura_tela;
		}
		else if(y <= raio) {
			dy = 1;
			y = raio;
		}
	}
	al_flip_display();
	al_show_native_message_box(tela, "Objeto em Movimento", "ATENÇÃO",
			"ALTERE O CoDIGO E TENTE NOVAMENTE", NULL, ALLEGRO_MESSAGEBOX_WARN);
	al_destroy_display(tela);
	return 0;
}



