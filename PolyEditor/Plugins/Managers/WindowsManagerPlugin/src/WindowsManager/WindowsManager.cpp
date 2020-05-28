#include "WindowsManager.hpp"

#include <qwidget.h>
#include <qapplication.h>
#include <qcommandlineparser.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qcalendarwidget.h>

#include <pt/ISubEditorWindowHandle.hpp>

using namespace ed::windowsManager;

// ************************************************************************************************
void WindowsManager::onOpen()
{
}

// ************************************************************************************************
void WindowsManager::onUpdate(const float dt)
{
}

// ************************************************************************************************
void WindowsManager::onClose()
{
}

// ************************************************************************************************
void WindowsManager::openTopLevelWindow()
{
	pd::TabbedWindowHandle window1 = m_registry.createWindow();
	pd::WindowTabHandle tab1 = window1.getTabsHeader().addTab();
	pd::WindowTabHandle tab2 = window1.getTabsHeader().addTab();
	pd::WindowTabHandle tab3 = window1.getTabsHeader().addTab();

	tab1.setName("tab1");
	tab1.setTabContent(new QPushButton("tab1"));
	tab2.setName("tab2");
	tab2.setTabContent(new QCalendarWidget());
	tab3.setName("tab3");
	tab3.setTabContent(new QLineEdit("tab3"));
}