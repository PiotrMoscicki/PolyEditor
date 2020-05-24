#pragma once

#include <qpointer.h>
#include <ResourceBrowserAPI.hpp>

namespace Ui { class ResourceSubEditorWidget; }

// ************************************************************************************************
// ************************************************************************************************
// ************************************************************************************************
class ResourceSubEditorWidget : public QWidget
{
	Q_OBJECT;

public:
	ResourceSubEditorWidget();

private:
	std::unique_ptr<Ui::ResourceSubEditorWidget> m_ui;
};

// ************************************************************************************************
// ************************************************************************************************
// ************************************************************************************************
class ResourceSubEditor : public ed::ResourceBrowser::ISubEditor
{
protected:
	// ResourceSubEditor
	void onOpen() final;
	void onUpdate(float dt) final;
	void onClose() final;

	// ed::ResourceBrowser::ISubEditor
	void registerType(std::shared_ptr<const ed::ResourceBrowser::ResourceType> type) final;
	void unregisterType(std::shared_ptr<const ed::ResourceBrowser::ResourceType> type) final;
	void registerResource(std::shared_ptr<const ed::ResourceBrowser::ResourceItem> resource) final;
	void unregisterResource(std::shared_ptr<const ed::ResourceBrowser::ResourceItem> resource) final;

private:
	QPointer<ResourceSubEditorWidget> m_widget;
};