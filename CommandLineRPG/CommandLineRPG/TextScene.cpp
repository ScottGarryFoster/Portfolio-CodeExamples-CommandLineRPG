#include "TextScene.h"

TextScene::TextScene() : Screen()
{
	mImage = new CharacterImage();
	mImage->loadFromFile("CharacterImage/bat_01.txt");

	m_Canvas = new CharCanvas(CHARACTER_WIDTH, CANVAS_HEIGHT);
	m_Canvas->AddImage(mImage, 1, 0, 0);

	m_CanvasInformation = new CharCanvas(CHARACTER_WIDTH, 10);

	m_tab = new InformationPanels();
	m_tab->addInformationTab();
	m_tab->getInformationTab()->addNewOption("[d] Description");
	m_tab->getInformationTab()->addNewOption("[i] Inventory");
	m_tab->getInformationTab()->addNewOption("[m] Map");
	m_CanvasInformation->AddInformationPanel(m_tab, 1);

	m_selectedTab = 1;
	m_tab->getInformationTab()->giveSelectedTab(&m_selectedTab);
}
TextScene::~TextScene()
{
	if (m_CanvasInformation != nullptr) delete m_CanvasInformation;
	if (m_Canvas != nullptr) delete m_Canvas;
	if (m_tab != nullptr) delete m_tab;
}

void TextScene::Setup(Player* player, void* Passover)
{
	p_player = player;
	p_haveSetup = true;
	//Setup a link to the canvas
	m_CanvasInformation->AddInformationPanel(p_player->getInfoPanel(), 0, CHARACTER_WIDTH - p_player->getInfoPanel()->getWidth(), 0);
	m_tab->setSize(CHARACTER_WIDTH - p_player->getInfoPanel()->getWidth(), 3);
	m_tab->getInformationTab()->setWidth(CHARACTER_WIDTH - p_player->getInfoPanel()->getWidth());
	
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