#include "ResourceSubEditor.hpp"
#include "ui_ResourceSubEditorWidget.h"

using namespace ed::ResourceBrowser;

// ************************************************************************************************
// ************************************************************************************************
// ************************************************************************************************
ResourceSubEditorWidget::ResourceSubEditorWidget()
	: m_ui(std::make_unique<Ui::ResourceSubEditorWidget>())
{
	m_ui->setupUi(this);
}

// ************************************************************************************************
// ************************************************************************************************
// ************************************************************************************************
void ResourceSubEditor::onOpen()
{
	m_widget = new ResourceSubEditorWidget();
	setWidget(m_widget);
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
void ResourceSubEditor::registerType(std::shared_ptr<const ResourceType> type)
{
}

// ************************************************************************************************
void ResourceSubEditor::unregisterType(std::shared_ptr<const ResourceType> type)
{
}

// ************************************************************************************************
void ResourceSubEditor::registerResource(std::shared_ptr<const ResourceItem> resource)
{
}

// ************************************************************************************************
void ResourceSubEditor::unregisterResource(std::shared_ptr<const ResourceItem> resource)
{
}

