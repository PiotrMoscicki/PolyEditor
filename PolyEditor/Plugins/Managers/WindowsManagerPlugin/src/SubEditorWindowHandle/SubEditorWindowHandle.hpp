#pragma once

#include <pd/WindowTabHandle.hpp>
#include <pt/ISubEditorWindowHandle.hpp>


// *************************************************************************************************
// *************************************************************************************************
// *************************************************************************************************
class SubEditorWindowHandle : public pt::ISubEditorWindowHandle
{
public:
	SubEditorWindowHandle(pd::WindowTabHandle handle);

	// pt::ISubEditorWindowHandle
	void setOwnerInfo(const pt::SubEditorInfo& info) final;
	void setTitle(const std::string& title) final;
	void setWidget(QWidget* widget) final;
	void setMenuBar(QMenuBar* menuBar) final;
	void setToolBar(QToolBar* toolBar) final;
	void setStatusBar(QStatusBar* statusBar) final;
	std::unique_ptr<pt::IToolWindowHandle> addToolWindow(std::string uniqueName) final;
	void close() final;

private:
	pd::WindowTabHandle m_tabHandle;
};