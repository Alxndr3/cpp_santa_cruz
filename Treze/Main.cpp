#include <allegro5/allegro.h>
#include <iostream>

using namespace std;

int main()
{
	char escolha = '0';
	cout << "Escolha a cor de fundo para a tela do jogo" << endl;
	cout << "[1] PRETO" << endl;
	cout << "[2] VERMELHO" << endl;
	cout << "[3] VERDE" << endl;
	cout << "[4] AZUL" << endl;
	cout << "[5] AMARELO" << endl;
	cout << "[6] BRANCO (PADRÃO)" << endl;
	cout << "[X] SAIR" << endl;
	cout << "ESCOLHA: " << endl;

	int largura_tela = 800;
	int altura_tela = 600;

	ALLEGRO_DISPLAY *tela = NULL;
	al_init();

	ALLEGRO_COLOR cor_preta = al_map_rgb(0, 0, 0);
	ALLEGRO_COLOR cor_vermelha = al_map_rgb(255, 0, 0);
	ALLEGRO_COLOR cor_verde = al_map_rgb(0, 255, 0);
	ALLEGRO_COLOR cor_azul = al_map_rgb(0, 0, 255);
	ALLEGRO_COLOR cor_amarelo = al_map_rgb(0, 255, 255);
	ALLEGRO_COLOR cor_fundo = al_map_rgb(255, 255, 255);

	tela = al_create_display(largura_tela, altura_tela);

	if(escolha == '1') {
		cor_fundo = cor_preta;
	}
	else if(escolha == '2') {
		cor_fundo = cor_vermelha;
	}
	else if(escolha == '3') {
		cor_fundo = cor_verde;
	}
	else if(escolha == '4') {
		cor_fundo = cor_azul;
	}
	else if(escolha == '5') {
		cor_fundo = cor_amarelo;
	}
	else
		exit(0);

	al_clear_to_color(cor_fundo);
	al_flip_display();
	al_rest(2.0);
	al_destroy_display(tela);

	return 0;
}

