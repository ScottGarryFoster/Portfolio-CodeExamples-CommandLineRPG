#include "TextScene.h"
#include "CharacterImage.h"

TextScene::TextScene() : Screen()
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
		//NewScreenType = ScreenTypes::TitleScreen;
	{
		CharacterImage* charImage = new CharacterImage();
		charImage->loadFromFile("CharacterImage/bat_01.txt");
		charImage->print();
	}

	int number2;
	cin >> number2;
}