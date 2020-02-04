#include "TextScene.h"

TextScene::TextScene() : Screen()
{
	mImage = new CharacterImage();
	mImage->loadFromFile("CharacterImage/bat_01.txt");

	m_Canvas = new CharCanvas(CHARACTER_WIDTH, CANVAS_HEIGHT);
	m_Canvas->AddImage(mImage, 1, 0, 0);

	m_CanvasInformation = new CharCanvas(CHARACTER_WIDTH, 10);
}
TextScene::~TextScene()
{
	if (m_CanvasInformation != nullptr) delete m_CanvasInformation;
	if (m_Canvas != nullptr) delete m_Canvas;
}

void TextScene::Setup(Player* player, void* Passover)
{
	p_player = player;
	p_haveSetup = true;
	//Setup a link to the canvas
	m_CanvasInformation->AddInformationPanel(p_player->getInfoPanel(), 0, 0, 0);
}

void TextScene::Output()
{
	m_Canvas->Draw();
	DrawSeam();
	m_CanvasInformation->Draw();
	int number;
	cin >> number;
	if (number > 5)
	{
		cout << "hey" << endl;
	}
	p_player->addHealth(number);
}