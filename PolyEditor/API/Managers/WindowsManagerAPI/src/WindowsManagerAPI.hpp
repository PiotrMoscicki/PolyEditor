#pragma once

#include <pt/ISubEditorWindowHandle.hpp>
#include <pt/Manager.hpp>

namespace ed::windowsManager
{

// *************************************************************************************************
// *************************************************************************************************
// *************************************************************************************************
class ITopLevelWindowHandle
{
public:
	virtual ~ITopLevelWindowHandle() = default;

	virtual std::unique_ptr<pt::ISubEditorWindowHandle> openSubEditorWindow() = 0;
};

// *************************************************************************************************
// *************************************************************************************************
// *************************************************************************************************
class IManager : public pt::Manager
{
public:
	// *********************************************************************************************
	// *********************************************************************************************
	// *********************************************************************************************
	class IObserver
	{
	public:
	};

	static inline pt::ManagerInfo Info = {"ed::WindowsManager::IManager", 1};
	const pt::ManagerInfo& info() const final { return Info; };
	void setOvserver(IObserver* observer) { m_observer = observer; }

	virtual std::unique_ptr<ITopLevelWindowHandle> openTopLevelWindow() = 0;

protected:
	IObserver* m_observer = nullptr;
};

} // namespace ed::windowsManager
