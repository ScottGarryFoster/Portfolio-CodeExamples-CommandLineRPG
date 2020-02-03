#include "TextScene.h"

TextScene::TextScene() : Screen()
{
	mImage = new CharacterImage();
	mImage->loadFromFile("CharacterImage/bat_01.txt");

	mCanvas = new CharCanvas(CHARACTER_WIDTH, CANVAS_HEIGHT);
	mCanvas->AddImage(mImage, 1, 0, 0);
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
	mCanvas->Draw();
	DrawSeam();
	if (p_player != nullptr)
		p_player->printBasicStats();
	int number;
	cin >> number;
	if (number > 5)
	{
		cout << "hey" << endl;
	}

	int number2;
	cin >> number2;
}