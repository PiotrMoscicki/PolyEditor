#pragma once

#include <pd/PolyDockRegistry.hpp>

#include <WindowsManagerAPI.hpp>

// *************************************************************************************************
// *************************************************************************************************
// *************************************************************************************************
class WindowsManager : public ed::windowsManager::IManager
{
protected:
	// pt::Manager
	void onOpen() final;
	void onUpdate(float dt) final;
	void onClose() final;

	// ed::windowsManager::IManager
	std::unique_ptr<ed::windowsManager::ITopLevelWindowHandle> openTopLevelWindow() final;

private:
	pd::PolyDockRegistry m_registry;
};