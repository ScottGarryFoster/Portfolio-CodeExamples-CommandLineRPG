#include "TitleScreen.h"



TitleScreen::TitleScreen()
{
}


TitleScreen::~TitleScreen()
{
}

void TitleScreen::Setup(Player* player, void* Passover)
{
	//p_player = player;
	p_haveSetup = true;
}

void TitleScreen::Output()
{
	cout << "I am a title screen" << endl;
	int number;
	cin >> number;
	if (number > 5)
		NewScreenType = ScreenTypes::TextScene;
}