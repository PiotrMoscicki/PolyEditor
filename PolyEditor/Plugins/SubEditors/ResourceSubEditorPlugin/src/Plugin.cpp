#include <iostream>

#include <pp/PolyPlugin.hpp>
#include <SubEditor/ResourceSubEditor.hpp>

using namespace ed::ResourceBrowser;

// ************************************************************************************************
// ************************************************************************************************
// ************************************************************************************************
class Plugin : public pp::IPlugin
{
public:
	void init(std::shared_ptr<pp::Router> router) final
	{
		router->registerIntentHandler<pt::CreateSubEditorIntent<ISubEditor>>(getPluginInfo(), 
			[] (pt::CreateSubEditorIntent<ISubEditor> intent)
			{
				return std::make_unique<ResourceSubEditor>();
			});
	}

	void deinit(std::shared_ptr<pp::Router> router) final { }
	pp::PluginInfo getPluginInfo() const final { return { "Calculator", { 1, 0, 0} }; }

private:
};

// ************************************************************************************************
POLY_PLUGIN_ENTRY(Plugin);