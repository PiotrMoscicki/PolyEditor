#include "ResourceSubEditor.hpp"
#include "ui_ResourceSubEditor.h"

using namespace ed::ResourceBrowser;

// ************************************************************************************************
ResourceSubEditor::ResourceSubEditor()
	: UI(std::make_unique<Ui::ResourceSubEditor>())
{
	UI->setupUi(this);
}

// ************************************************************************************************
void ResourceSubEditor::onOpen()
{

}

// ************************************************************************************************
void ResourceSubEditor::onUpdate(float dt)
{
}

// ************************************************************************************************
void ResourceSubEditor::onClose()
{
}

// ************************************************************************************************
void ResourceSubEditor::RegisterType(std::shared_ptr<const ResourceType> type)
{
}

// ************************************************************************************************
void ResourceSubEditor::UnregisterType(std::shared_ptr<const ResourceType> type)
{
}

// ************************************************************************************************
void ResourceSubEditor::RegisterResource(std::shared_ptr<const ResourceItem> resource)
{
}

// ************************************************************************************************
void ResourceSubEditor::UnregisterResource(std::shared_ptr<const ResourceItem> resource)
{
}

