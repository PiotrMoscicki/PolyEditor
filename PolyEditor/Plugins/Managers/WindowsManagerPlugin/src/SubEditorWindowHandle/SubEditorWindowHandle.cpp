#include "SubEditorWindowHandle.hpp"

#include <pt/IToolWindowHandle.hpp>

// *************************************************************************************************
SubEditorWindowHandle::SubEditorWindowHandle(pd::WindowTabHandle handle)
	: m_tabHandle(std::move(handle))
{
}

// *************************************************************************************************
void SubEditorWindowHandle::setOwnerInfo(const pt::SubEditorInfo& info)
{
}

// *************************************************************************************************
void SubEditorWindowHandle::setTitle(const std::string& title)
{
}

// *************************************************************************************************
void SubEditorWindowHandle::setWidget(QWidget* widget)
{
}

// *************************************************************************************************
void SubEditorWindowHandle::setMenuBar(QMenuBar* menuBar)
{
}
// *************************************************************************************************

void SubEditorWindowHandle::setToolBar(QToolBar* toolBar)
{
}

// *************************************************************************************************
void SubEditorWindowHandle::setStatusBar(QStatusBar* statusBar)
{
}

// *************************************************************************************************
std::unique_ptr<pt::IToolWindowHandle> SubEditorWindowHandle::addToolWindow(std::string uniqueName)
{
	return nullptr;
}

// *************************************************************************************************
void SubEditorWindowHandle::close()
{
}
