#pragma once

#include <vector>
#include <string>
#include <optional>
#include <memory>
#include <pt/SubEditor.hpp>

namespace ed::ResourceBrowser
{
	// ************************************************************************************************
	// ************************************************************************************************
	// ************************************************************************************************
	class ResourceType
	{
	public:
		std::string name;
		std::string description;
		QIcon icon;
		bool canHaveSubResources;
	};

	// ************************************************************************************************
	// ************************************************************************************************
	// ************************************************************************************************
	class ResourceItem
	{
	public:
		std::shared_ptr<const ResourceType> type;
		std::string name;
	};

	// ************************************************************************************************
	// ************************************************************************************************
	// ************************************************************************************************
	// Resource Browser displays resource tree. Everything is a 
	// resource. Directory is also a resource with sub resources 
	class ISubEditor : public pt::SubEditor
	{
	public:
		// ********************************************************************************************
		// ********************************************************************************************
		// ********************************************************************************************
		class IObserver
		{
		public:
			virtual std::map<std::string, std::shared_ptr<QAction>> getActions(
				std::shared_ptr<const ResourceItem>) = 0;

			virtual void add(std::shared_ptr<const ResourceItem> parent, 
				std::shared_ptr<const ResourceType> type, std::optional<std::string> name) = 0;
			virtual void remove(std::shared_ptr<const ResourceItem> resource) = 0;
			virtual void rename(std::shared_ptr<const ResourceItem> resource, std::string newName) = 0;
			virtual void move(std::shared_ptr<const ResourceItem> resource, 
				std::shared_ptr<const ResourceItem> newParent) = 0;
			virtual void copyTo(std::shared_ptr<const ResourceItem> resource, 
				std::shared_ptr<const ResourceItem> newParent) = 0;
		};

		static inline pt::SubEditorInfo Info = { "ed::ResourceBrowser::ISubEditor", 1 };
		const pt::SubEditorInfo& info() const final { return Info; };
		void setOvserver(IObserver* observer) { m_observer = observer; }

		virtual void registerType(std::shared_ptr<const ResourceType> type) = 0;
		virtual void unregisterType(std::shared_ptr<const ResourceType> type) = 0;
		virtual void registerResource(std::shared_ptr<const ResourceItem> resource) = 0;
		virtual void unregisterResource(std::shared_ptr<const ResourceItem> resource) = 0;

	protected:
		IObserver* m_observer = nullptr;
	};

	// ************************************************************************************************
	// ************************************************************************************************
	// ************************************************************************************************
	class AddResourceDialogIntent
	{
	public:
		class AcceptedResult
		{
		public:
			std::shared_ptr<const ResourceType> type;
			std::string name;
		};

		using Result = std::optional<AcceptedResult>;
		static inline pp::IntentInfo Info = { "AddResourceDialogIntent", 1 };

		std::vector<std::shared_ptr<const ResourceType>> availableTypes;
	};
} // namespace ed