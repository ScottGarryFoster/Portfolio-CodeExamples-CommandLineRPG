#include "TextScene.h"

TextScene::TextScene()
{

}
TextScene::~TextScene()
{

}

void TextScene::Setup(Player* player, void* Passover)
{
	p_player = player;
	p_haveSetup = true;
}

void TextScene::Output()
{
	cout << "I am a text screen" << endl;
	int number;
	cin >> number;
	if (number > 5)
		NewScreenType = ScreenTypes::TitleScreen;
}