#include <iostream>

#include <pp/PolyPlugin.hpp>

#include <WindowsManager/WindowsManager.hpp>

using namespace ed::windowsManager;

// ************************************************************************************************
// ************************************************************************************************
// ************************************************************************************************
class Plugin : public pp::IPlugin
{
public:
	void init(std::shared_ptr<pp::Router> router) final
	{
		router->registerIntentHandler<pt::CreateManagerIntent<IManager>>(getPluginInfo(),
			[] (pt::CreateManagerIntent<IManager> intent)
			{
				return std::make_unique<WindowsManager>();
			});
	}

	void deinit(std::shared_ptr<pp::Router> router) final { }
	pp::PluginInfo getPluginInfo() const final { return { "WindowsManager", { 1, 0, 0} }; }

private:
};

// ************************************************************************************************
POLY_PLUGIN_ENTRY()
{
	return new Plugin();
}