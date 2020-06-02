#include "WindowsManager.hpp"

#include <qwidget.h>
#include <qapplication.h>
#include <qcommandlineparser.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qcalendarwidget.h>

#include <pt/ISubEditorWindowHandle.hpp>

#include <TopLevelWindowHandle/TopLevelWindowHandle.hpp>

using namespace ed::windowsManager;

// *************************************************************************************************
void WindowsManager::onOpen()
{
}

// *************************************************************************************************
void WindowsManager::onUpdate(const float dt)
{
}

// *************************************************************************************************
void WindowsManager::onClose()
{
}

// *************************************************************************************************
std::unique_ptr<ITopLevelWindowHandle> WindowsManager::openTopLevelWindow()
{
	return std::make_unique<TopLevelWindowHandle>(m_registry.createWindow());
}