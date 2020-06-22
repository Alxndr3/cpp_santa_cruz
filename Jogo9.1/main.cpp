#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <iostream>
#include <cstdlib>
#include <ctime>



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
	bool active;
	bool check;
	float pos_enemy_x;
	float pos_enemy_y;
	float speed;
	int radius;
	int direction_x;
	int direction_y;
	int shot;
	int r;
	int g;
	int b;
	ALLEGRO_COLOR color;

	inimigo() {
		std::cout << "Inimigo Instanciado" << std::endl;
		this -> active = true;
		this -> check = false;
		this -> pos_enemy_x = rand() % 750 + 40; // Gera números entre 40 e 750
		this -> pos_enemy_y = rand() % 550 + 40; // Gera números entre 550 e 40
		this -> radius = rand() % 40 + 15; // Gera números entre 40 e 15
		this -> speed = (rand() % 10 + 1) * 0.09;
		this -> direction_x = (rand() % 6 ) -3;
		this -> direction_y = (rand() % 6 ) -3;
		this -> shot = 0;
		this -> r = rand() % 255 + 100;
		this -> g = rand() % 255 + 140;
		this -> b = rand() % 255 + 190;
		this -> color = al_map_rgb(r, g, b);
		std::cout << "Características definidas" << std::endl;
	}

	void desenha_inimigo() {
		// Os circulos (inimigos) serão desenhados apenas quando as variável active corresponder a true.
		// Em nosso jogo quado atingimos uma instância do objeto é atribuído o valor false a ela.
		// O sinal % (module) em lógica de programação representa o resto da divisão ex:
		// 4%2=0 3%2=1
		// No códia abaixo a variável active tornaral a ter seu valor atribuído como true caso a n seja igual a zero
		// Module de uma divisão por 1000 variará de 0 999, quando este valor for igual a 0 será atribuído o valor
		// true a variável active então o objeto inimigo voltará a ser desenhado.
		// De maneira que a velocidade do loop principal em c++ é extremamente rápida, brevemente o número será
		// sorteado.
		if(this -> active) {
			al_draw_filled_circle(this->pos_enemy_x, this->pos_enemy_y, this->radius, this->color);
		}
		else {
			int n = rand() % 1000;
			if(n == 0) {
				this -> active = true;
			}
		}
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
		this -> check = false;
		if(pos_x_player >= this -> pos_enemy_x - this -> radius && pos_x_player <= this -> pos_enemy_x + radius) {
			if(pos_y_player >= this -> pos_enemy_y - this -> radius && pos_y_player <= this -> pos_enemy_y + this -> radius) {
				this -> shot++;
				this -> check = true;
				this -> active = false;
				std::cout << "Acertou o alvo!" << std::endl;
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
	bool recharge = false;
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
	// Addons de Audio
	al_init_acodec_addon();
	al_install_audio();
	al_reserve_samples(10);
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
	// Carregar trilha sonora.
	ALLEGRO_SAMPLE *trilha_sonora = al_load_sample("audio/trilha_sonora.ogg");
	// Instanciar a trilha sonora.
	ALLEGRO_SAMPLE_INSTANCE *inst_trilha_sonora = al_create_sample_instance(trilha_sonora);
	// Carregar som para o laser.
	ALLEGRO_SAMPLE *laser = al_load_sample("audio/laser.wav");
	// Instanciar o som do laser.
	ALLEGRO_SAMPLE_INSTANCE *inst_laser = al_create_sample_instance(laser);
	// Carregar som da explosão.
	ALLEGRO_SAMPLE *explosao = al_load_sample("audio/explosao.wav");
	// Instanciar o som da explosao.
	ALLEGRO_SAMPLE_INSTANCE *inst_explosao = al_create_sample_instance(explosao);
	// Carregar som do aplauso.
	ALLEGRO_SAMPLE *aplausos= al_load_sample("audio/aplausos.wav");
	// Instanciar o som do aplauso.
	ALLEGRO_SAMPLE_INSTANCE *inst_aplausos = al_create_sample_instance(aplausos);
	// Mixar a trilha sonora.
	al_attach_sample_instance_to_mixer(inst_trilha_sonora, al_get_default_mixer());
	// Definir que a trilha sonora se repita durante todo o jogo.
	al_set_sample_instance_playmode(inst_trilha_sonora, ALLEGRO_PLAYMODE_LOOP);
	// Modificar o volume do som.
	al_set_sample_instance_gain(inst_trilha_sonora, 0.8);
	// Mixar a trilha do laser.
	al_attach_sample_instance_to_mixer(inst_laser, al_get_default_mixer());
	// Mixar a trilha da explosão.
	al_attach_sample_instance_to_mixer(inst_explosao, al_get_default_mixer());
	// Mixar a trilha do aplauso.
	al_attach_sample_instance_to_mixer(inst_aplausos, al_get_default_mixer());
	// Devinir a fila de eventos para teclado e mouse.
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());
	// Ocultar cursor do mouse
	al_hide_mouse_cursor(display);
	// Tocar a trilha sonora
	al_play_sample_instance(inst_trilha_sonora);

	al_clear_to_color(color_bg);
	al_draw_text(font_2, al_map_rgb(30, 255, 30), 180, 250, 0, "LET'S GET STARTED!!!");
	al_flip_display();
	al_rest(3);

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
		// Caso o valor da variável amo seja zero o jogo é interrompido
		if(amo == 0) {
			al_draw_text(font_2, al_map_rgb(255, 30, 30), 180, 250, 0, "GAME OVER DUDE >8>D");
			al_flip_display();
			al_rest(3.0);
			continue_ = false; }
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
				if(ev.mouse.button == 2) {
					amo = 10;
					recharge = true;
				}
				// Botão esquerdo do mouse.
				if(ev.mouse.button == 1) {
					// Para evitar atraso de sons caso mais de um laser seja atirado antes de acabar o som do anterior
					al_stop_sample_instance(inst_laser);
					al_play_sample_instance(inst_laser);
					std::cout << "X = " << pos_x_player << std::endl;
					std::cout << "Y = " << pos_y_player << std::endl;
					std::cout << "---------------------" << std::endl;
					enemy_1.verifica_disparos(pos_x_player, pos_y_player);
					enemy_2.verifica_disparos(pos_x_player, pos_y_player);
					enemy_3.verifica_disparos(pos_x_player, pos_y_player);
					if(enemy_1.check) {
						shot++ ;
						al_stop_sample_instance(inst_explosao);
						al_play_sample_instance(inst_explosao);
					}
					else if(enemy_2.check) {
						shot++ ;
						al_stop_sample_instance(inst_explosao);
						al_play_sample_instance(inst_explosao);
					}
					else if(enemy_3.check) {
						shot++ ;
						al_stop_sample_instance(inst_explosao);
						al_play_sample_instance(inst_explosao);
					}
					amo--;
					if(shot == 8 && amo == 2 && recharge == false) {
						al_play_sample_instance(inst_aplausos);
					}
					if(shot == 30) {
						al_play_sample_instance(inst_aplausos);
					}
				}
			}
		}
	}

	al_destroy_display(display);

	return 0;
}
