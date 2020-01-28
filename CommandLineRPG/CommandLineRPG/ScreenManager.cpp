#include "ScreenManager.h"



ScreenManager::ScreenManager()
{
	m_player = new Player();
	InstantiateNewScreen(ScreenTypes::TitleScreen);
}

ScreenManager::~ScreenManager()
{
}

void ScreenManager::Output()
{
	if (m_currentScreen == nullptr) return;
	if (!m_currentScreen->HaveSetup()) m_currentScreen->Setup(m_player);

	m_currentScreen->Output();
	if (m_currentScreen->NewScreenType != ScreenTypes::None)
	{
		void* passover = m_currentScreen->ScreenPassover;
		ScreenTypes newScreenType = m_currentScreen->NewScreenType;
		delete m_currentScreen;
		InstantiateNewScreen(newScreenType);
		m_currentScreen->Setup(m_player, passover);
		system("CLS");
	}
}

void ScreenManager::InstantiateNewScreen(ScreenTypes screenType)
{
	switch (screenType)
	{

	case ScreenTypes::TitleScreen:
	default:
		m_currentScreen = new TitleScreen();
		return;
	}
}