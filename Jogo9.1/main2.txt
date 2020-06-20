#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>



class jogador {

public:
	int pos_x;
	int pos_y;
	int balas;
	int pontos;

	void desenha_jogador() {
		// Dezenhar mira
		al_draw_circle(this->pos_x, this->pos_y + 10, 20, al_map_rgb(255, 255, 0), 1);
		al_draw_rectangle(this->pos_x - 10, this->pos_y, this->pos_x + 10, this->pos_y + 20, al_map_rgb(255, 255, 0), 1);
		al_draw_line(this->pos_x - 20, this->pos_y + 10, this->pos_x -10, this->pos_y + 10, al_map_rgb(255, 255, 0), 1);
		al_draw_line(this->pos_x + 10, this->pos_y + 10, this->pos_x + 20, this->pos_y + 10, al_map_rgb(255, 255, 0), 1);
		al_draw_line(this->pos_x, this->pos_y - 10, this->pos_x, this->pos_y, al_map_rgb(255, 255, 0), 1);
		al_draw_line(this->pos_x, this->pos_y + 20, this->pos_x, this->pos_y + 30, al_map_rgb(255, 255, 0), 1);
	}

	jogador() {
		std::cout << "Jogador Instanciado" << std::endl;
		this -> pos_x = 0; // Posição inicial
		this -> pos_y = 0; // Posição inicial
		this -> balas = 10; // Jogaror tem 10 munições
		this -> pontos = 0; // Jogador tem 0 pontos
		std::cout << "Características do jogador definidas" << std::endl;
	}

	void atualiza_jogador(int x, int y) {
		this -> pos_x = x - 15;
		this -> pos_y = y - 15;
	}
};

// Classe inimigo
class inimigo {

public:
	// Atributos
	float pos_enemy_x;
	float pos_enemy_y;
	float speed;
	int radius;
	int direction_x;
	int direction_y;
	int amo;
	int shot;
	int r;
	int g;
	int b;
	bool active = NULL;
	ALLEGRO_COLOR color;

	inimigo() {
		std::cout << "Inimigo Instanciado" << std::endl;
		this -> pos_enemy_x = rand() % 750 + 40; // Gera números entre 40 e 750
		this -> pos_enemy_y = rand() % 550 + 40; // Gera números entre 550 e 40
		this -> radius = rand() % 40 + 15; // Gera números entre 40 e 15
		this -> speed = (rand() % 10 + 1) * 0.01;
		this -> direction_x = (rand() % 6 ) -3;
		this -> direction_y = (rand() % 6 ) -3;
		this -> amo = 10;
		this -> shot = 0;
		this -> r = rand() % 255 + 100;
		this -> g = rand() % 255 + 140;
		this -> b = rand() % 255 + 190;
		this -> active = true;
		this -> color = al_map_rgb(r, g, b);
		std::cout << "Características definidas" << std::endl;
	}

	void desenha_inimigo() {
		al_draw_filled_circle(this->pos_enemy_x, this->pos_enemy_y, this->radius, this->color);
	}

	void atualiza_inimigo() {
		this -> pos_enemy_x = this -> pos_enemy_x + this -> direction_x * this -> speed;
		this -> pos_enemy_y = this -> pos_enemy_y + this -> direction_y * this -> speed;
	}

	void verifica_limites(int screen_width, int screen_hight) {
		// Verificar o lado direito
		if(this -> pos_enemy_x + this -> radius >= screen_width) {
			this -> direction_x = this -> direction_x * ( -1);
		}
		if(this -> pos_enemy_x + this -> radius <= 0) {
			this -> direction_x = this -> direction_x * ( -1);
		}
		if(this -> pos_enemy_y + this -> radius >= screen_hight) {
			this -> direction_y = this -> direction_y * ( -1);
		}
		if(this -> pos_enemy_y + this -> radius <= 0) {
			this -> direction_y = this -> direction_y * ( -1);
		}
	}

	void verifica_disparos(int pos_x_player, int pos_y_player) {
		amo--;
		if(pos_x_player >= pos_enemy_x- radius && pos_x_player <= pos_enemy_x + radius) {
			if(pos_y_player >= pos_enemy_y - radius && pos_y_player <= pos_enemy_y + radius) {
				shot++;
			}
		}
	}
};

void draw_score(int amo, int shot, int pos_x_alvo, int pos_y_alvo, ALLEGRO_COLOR color_bg,
		ALLEGRO_COLOR color_rect, ALLEGRO_FONT *font_1) {
	// Desenhar placar e escrever número de munições e acertos no alvo
	al_draw_filled_rectangle(0, 0, 50, 30, al_map_rgb(0, 200, 0));
	al_draw_filled_rectangle(50, 0, 100, 30, al_map_rgb(200, 0, 0));
	al_draw_text(font_1, color_bg, 10, 0, 0, "Amo");
	al_draw_textf(font_1, color_bg, 20, 13, ALLEGRO_ALIGN_CENTER, "%d", amo);
	al_draw_text(font_1, color_bg, 60, 0, 0, "Shot");
	al_draw_textf(font_1, color_bg, 70, 13, ALLEGRO_ALIGN_CENTER, "%d", shot);
}

int main() {

	srand(time(NULL));
	bool continue_ = true;
	int screen_width = 800;
	int screen_hight = 600;
	int pos_x_player = 0;
	int pos_y_player = 0;
	int count = 0;
	int amo = 10;
	int shot = 0;

	al_init();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();
	al_install_mouse();
	// Instancia da classe inimigo
	inimigo enemy_1;
	inimigo enemy_2;
	inimigo enemy_3;
	// Instancia da classe jogador
	jogador player;

	ALLEGRO_DISPLAY *display = al_create_display(screen_width, screen_hight);
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	ALLEGRO_FONT *font_1 = al_load_font("arial.ttf", 12, 0);
	ALLEGRO_FONT *font_2 = al_load_font("arial.ttf", 32, 0);
	ALLEGRO_EVENT ev;
	ALLEGRO_COLOR color_bg = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR color_rect = al_map_rgb(255, 255, 255);

	// Devinir a fila de eventos para teclado e mouse.
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());

	al_hide_mouse_cursor(display); // Ocultar cursor do mouse

	al_clear_to_color(color_bg);
	al_flip_display();

	while(continue_) {
		al_clear_to_color(color_bg);

		enemy_1.desenha_inimigo();
		enemy_2.desenha_inimigo();
		enemy_3.desenha_inimigo();
		enemy_1.atualiza_inimigo();
		enemy_2.atualiza_inimigo();
		enemy_3.atualiza_inimigo();
		enemy_1.verifica_limites(screen_width, screen_hight);
		enemy_2.verifica_limites(screen_width, screen_hight);
		enemy_3.verifica_limites(screen_width, screen_hight);
		player.desenha_jogador();
		draw_score(amo, shot, pos_x_player, pos_y_player, color_bg, color_rect, font_1);

		if(amo == 0) {
			al_draw_text(font_2, al_map_rgb(255, 30, 30), 180, 250, 0, "GAME OVER DUDE >8>D");
			al_flip_display();
			al_rest(3.0);
			continue_ = false;
		}

		count += 1;

		al_flip_display();

		if(!al_is_event_queue_empty(event_queue)) {

			al_wait_for_event(event_queue, &ev);

			if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
				if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
					continue_ = false;
				}
			}
			else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES) {
				pos_x_player = ev.mouse.x;
				pos_y_player = ev.mouse.y;
				player.atualiza_jogador(pos_x_player, pos_y_player);
			}
			else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
				// Botão esquerdo do mouse.
				if(ev.mouse.button == 1) {
					std::cout << "X = " << pos_x_player << std::endl;
					std::cout << "Y = " << pos_y_player << std::endl;
					std::cout << "---------------------" << std::endl;
					enemy_1.verifica_disparos(pos_x_player, pos_y_player);
					enemy_2.verifica_disparos(pos_x_player, pos_y_player);
					enemy_3.verifica_disparos(pos_x_player, pos_y_player);
				}
			}
		}
	}

	al_destroy_display(display);

	return 0;
}
