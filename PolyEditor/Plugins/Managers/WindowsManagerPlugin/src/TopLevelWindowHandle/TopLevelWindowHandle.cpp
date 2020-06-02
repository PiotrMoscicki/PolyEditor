#include "TopLevelWindowHandle.hpp"

#include <qwidget.h>
#include <qapplication.h>
#include <qcommandlineparser.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qcalendarwidget.h>

#include <pt/ISubEditorWindowHandle.hpp>

using namespace ed::windowsManager;

// *************************************************************************************************
TopLevelWindowHandle::TopLevelWindowHandle(pd::TabbedWindowHandle handle)
	: m_windowHandle(std::move(handle))
{
}

// *************************************************************************************************
std::unique_ptr<pt::ISubEditorWindowHandle> TopLevelWindowHandle::openSubEditorWindow()
{
	//m_windowHandle.getTabsHeader().addTab();
	return nullptr;
}