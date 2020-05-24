#pragma once

#include <ResourceBrowserAPI.hpp>

namespace Ui { class ResourceSubEditor; }

// ************************************************************************************************
// ************************************************************************************************
// ************************************************************************************************
class ResourceSubEditor : public QWidget, public ed::ResourceBrowser::ISubEditor
{
	Q_OBJECT;

public:
	ResourceSubEditor();

protected:
	// ResourceSubEditor
	void onOpen() final;
	void onUpdate(float dt) final;
	void onClose() final;

	// ed::ResourceBrowser::ISubEditor
	void RegisterType(std::shared_ptr<const ed::ResourceBrowser::ResourceType> type) final;
	void UnregisterType(std::shared_ptr<const ed::ResourceBrowser::ResourceType> type) final;
	void RegisterResource(std::shared_ptr<const ed::ResourceBrowser::ResourceItem> resource) final;
	void UnregisterResource(std::shared_ptr<const ed::ResourceBrowser::ResourceItem> resource) final;

private:
	std::unique_ptr<Ui::ResourceSubEditor> UI;
};