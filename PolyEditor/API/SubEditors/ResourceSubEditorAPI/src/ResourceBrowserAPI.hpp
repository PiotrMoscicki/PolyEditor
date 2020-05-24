#pragma once

#include <vector>
#include <string>
#include <optional>
#include <memory>

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
			virtual std::map<std::string, std::shared_ptr<QAction>> GetActions(
				std::shared_ptr<const ResourceItem>) = 0;

			virtual void Add(std::shared_ptr<const ResourceItem> parent, 
				std::shared_ptr<const ResourceType> type, std::optional<std::string> name) = 0;
			virtual void Remove(std::shared_ptr<const ResourceItem> resource) = 0;
			virtual void Rename(std::shared_ptr<const ResourceItem> resource, std::string newName) = 0;
			virtual void Move(std::shared_ptr<const ResourceItem> resource, 
				std::shared_ptr<const ResourceItem> newParent) = 0;
			virtual void CopyTo(std::shared_ptr<const ResourceItem> resource, 
				std::shared_ptr<const ResourceItem> newParent) = 0;
		};

		static inline SubEditorInfo Info = { "IResourceBrowserSubEditor", 1 };
		const SubEditorInfo& info() const final { return Info; };
		void SetOvserver(IObserver* observer) { m_observer = observer; }

		virtual void RegisterType(std::shared_ptr<const ResourceType> type) = 0;
		virtual void UnregisterType(std::shared_ptr<const ResourceType> type) = 0;
		virtual void RegisterResource(std::shared_ptr<const ResourceItem> resource) = 0;
		virtual void UnregisterResource(std::shared_ptr<const ResourceItem> resource) = 0;

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