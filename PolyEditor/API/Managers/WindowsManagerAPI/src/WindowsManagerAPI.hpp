#pragma once

#include <pt/Manager.hpp>

namespace ed::windowsManager
{
	// ************************************************************************************************
	// ************************************************************************************************
	// ************************************************************************************************
	class IManager : public pt::Manager
	{
	public:
		// ********************************************************************************************
		// ********************************************************************************************
		// ********************************************************************************************
		class IObserver
		{
		public:

		};

		static inline pt::ManagerInfo Info = { "ed::WindowsManager::IManager", 1 };
		const pt::ManagerInfo& info() const final { return Info; };
		void setOvserver(IObserver* observer) { m_observer = observer; }

		virtual void openTopLevelWindow() = 0;

	protected:
		IObserver* m_observer = nullptr;
	};
} // namespace ed