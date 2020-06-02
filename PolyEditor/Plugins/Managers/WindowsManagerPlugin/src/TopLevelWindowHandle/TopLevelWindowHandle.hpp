#pragma once

#include <pd/TabbedWindowHandle.hpp>

#include <WindowsManagerAPI.hpp>

// *************************************************************************************************
// *************************************************************************************************
// *************************************************************************************************
class TopLevelWindowHandle : public ed::windowsManager::ITopLevelWindowHandle
{
public:
	TopLevelWindowHandle(pd::TabbedWindowHandle handle);

	// ed::windowsManager::ITopLevelWindowHandle
	std::unique_ptr<pt::ISubEditorWindowHandle> openSubEditorWindow() final;

private:
	pd::TabbedWindowHandle m_windowHandle;
};