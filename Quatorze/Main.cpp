#include <allegro5/allegro.h>
#include <iostream>

using namespace std;

char DefineCorTela() {
	char resposta = '6';
	cout << "Escolha a cor de fundo para a tela do jogo" << endl;
	cout << "[1] PRETO" << endl;
	cout << "[2] VERMELHO" << endl;
	cout << "[3] VERDE" << endl;
	cout << "[4] AZUL" << endl;
	cout << "[5] AMARELO" << endl;
	cout << "[6] BRANCO (PADRÃO)" << endl;
	cout << "[X] SAIR" << endl;
	cout << "Escolha: ";
	cin >> resposta;
	return resposta;
}


int main() {
	char cor_tela = '0';
	char tamanho_tela = '0';

	cor_tela = DefineCorTela();
	cout << cor_tela << endl;

	cout << endl;
	cout << "Escolha o tamanho da tela." << endl;
	cout << "[1] PADRÃO (800X600)" << endl;
	cout << "[2] MAXIMIZADO" << endl;
	cout << "Escolha: ";
	cin >> tamanho_tela;

	int largura_tela = 800;
	int altura_tela = 600;

	ALLEGRO_DISPLAY *tela = NULL;

	al_init();

	ALLEGRO_COLOR cor_preta = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR cor_vermelha = al_map_rgb(255, 0, 0);
	ALLEGRO_COLOR cor_verde = al_map_rgb(0, 255, 0);
	ALLEGRO_COLOR cor_azul = al_map_rgb(0, 0, 255);
	ALLEGRO_COLOR cor_amarela = al_map_rgb(255, 255, 0);
	ALLEGRO_COLOR cor_fundo = al_map_rgb(255, 255, 255);

	tela = al_create_display(largura_tela, altura_tela);

	if(tamanho_tela == '2') {
		al_set_display_flag(tela, ALLEGRO_FULLSCREEN_WINDOW, 1);
	}
	else {
		al_set_display_flag(tela, ALLEGRO_FULLSCREEN_WINDOW, 0);
	}

	if(cor_tela == '1') {
		cor_fundo = cor_preta;
	}
	else if(cor_tela == '2') {
		cor_fundo = cor_vermelha;
	}
	else if(cor_tela == '3') {
		cor_fundo = cor_verde;
	}
	else if(cor_tela == '4') {
		cor_fundo = cor_azul;
	}
	else if(cor_tela == '5') {
		cor_fundo = cor_amarela;
	}
	else
		exit(0);

	al_flip_display();
	al_clear_to_color(cor_fundo);
	al_flip_display();
	al_rest(4.0);
	al_destroy_display(tela);

	return 0;
}

