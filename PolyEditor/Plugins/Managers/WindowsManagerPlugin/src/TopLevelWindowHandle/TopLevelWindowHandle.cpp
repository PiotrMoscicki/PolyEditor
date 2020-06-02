#include "TopLevelWindowHandle.hpp"

#include <SubEditorWindowHandle/SubEditorWindowHandle.hpp>

using namespace ed::windowsManager;

// *************************************************************************************************
TopLevelWindowHandle::TopLevelWindowHandle(pd::TabbedWindowHandle handle)
	: m_windowHandle(std::move(handle))
{
}

// *************************************************************************************************
std::unique_ptr<pt::ISubEditorWindowHandle> TopLevelWindowHandle::openSubEditorWindow()
{
	return std::make_unique<SubEditorWindowHandle>(m_windowHandle.getTabsHeader().addTab());
}